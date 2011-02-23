module(..., package.seeall)

function createScene( params )
	local scene = {}

	local physics = require( "physics" )
	local ui = require( "ui" )
	require('socket')
	physics.start()
	--physics.setDrawMode( "hybrid" )
	local worldLength = 0
	local groundReferencePoint = 335
	local noahDestructor
	local slingShot
	local slingShotString
	local life = 100
	local onDeath
	local showAd
	local explosion
	local boost = 100

	if ( params.onDeath and ( type(params.onDeath) == "function" ) ) then
		print("setting onDeath")
		onDeath = params.onDeath
	end
	if ( params.showAddFunction and ( type(params.showAddFunction) == "function" ) ) then
		print("setting showAddFunction")
		showAd = params.showAdFunction
		showAd()
	end
	
	local game = display.newGroup()
	game.x = 0

	-- Sky and ground graphics
	function createFirstSection()
	--[[
		local sky = display.newImage( "sky.png", true )
		game:insert( sky )
		sky.x = 160; sky.y = 120
		local msky = display.newImage( "skymiddle.png", true )
		game:insert( msky )
		msky.x = 160; msky.y = -430
		local tsky = display.newImage( "skytop.png", true )
		game:insert( tsky )
		tsky.x = 160; tsky.y = -980
--]]
		local grass = display.newImage( "grass.png", true )
		game:insert( grass )
		grass.x = 160; grass.y = groundReferencePoint
		physics.addBody( grass, "static", { friction=0.2, bounce=0.1 } )
		grass.bodyName = "grass1"
	end

	function AddSection()
		worldLength = worldLength + 1
		local addition = 1120 + ( (worldLength - 1) * 960 )
		--[[
		local dsky = display.newImage( "sky.png", true )
		game:insert( dsky )
		dsky.x = addition; dsky.y = 120
		local msky = display.newImage( "skymiddle.png", true )
		game:insert( msky )
		msky.x = addition; msky.y = -430
		local tsky = display.newImage( "skytop.png", true )
		game:insert( tsky )
		tsky.x = addition; tsky.y = -980
		--]]
		addition = addition - 960		
		
		local dgrass
		if worldLength==3 or worldLength==6 or worldLength>8 then
			dgrass = display.newImage( "lava.png", true )
			dgrass.bodyName = "lava"
			dgrass.x = addition; dgrass.y = groundReferencePoint
			physics.addBody( dgrass, "static", { friction=0.8, bounce=0 } )
		else
			dgrass = display.newImage( "grass.png", true )
			dgrass.bodyName = "grass"..worldLength
			dgrass.x = addition; dgrass.y = groundReferencePoint
			physics.addBody( dgrass, "static", { friction=0.2, bounce=0.15 } )
		end
		
		game:insert( dgrass )

		if worldLength > 2 then
			math.random( os.time() )
			math.random()
			if math.random() < .5 then
				local ramp = display.newImage( "ramp.png" )
				ramp.x = addition + math.random( 40, 920 ); ramp.y = groundReferencePoint - 65
				ramp.bodyName = "ramp"..worldLength
				physics.addBody( ramp, "static", { friction=0, bounce=0, shape={ 40,25, -40,25, 40,-31 } } )	
				game:insert( ramp )		
			else
				local keg = display.newImage( "keg.png" )
				keg.x = addition - math.random( 40, 920 ); keg.y = groundReferencePoint - 65
				keg.bodyName = "keg"..worldLength
				physics.addBody( keg, "static", { friction=0, bounce=0 } )
				game:insert( keg )
			end
			
			local star = display.newImage( "star.png" )
			star.x = addition + math.random( 40, 920 ); star.y = math.random( -500, 140 )
			star.bodyName = "star"
			physics.addBody( star, "static", { friction=0, bounce=0 } )
			star.isSensor = true
			game:insert( star )
			
			local bacon = display.newImage( "bacon.png" )
			bacon.x = addition + math.random( 40, 920 ); bacon.y = math.random( -500, 140 )
			bacon.bodyName = "bacon"
			physics.addBody( bacon, "static", { friction=0, bounce=0 } )
			bacon.isSensor = true
			game:insert( bacon )
		end
	end

	createFirstSection()
	for i=1,2 do
		AddSection()
	end
	
	noahDestructorShape = { 16,-22, 16,0, 14,20, 10,31, -10,32, -14,20, -19,-6, -14, -20 }
	noahDestructor = display.newImage("noah.png")
	noahDestructor.x = 160; noahDestructor.y = groundReferencePoint - 200


	slingshotString = display.newImage( "string.png" )
	slingshotString.x = 150; slingshotString.y = groundReferencePoint - 180
	slingshotString.bodyName = "slingShotString"
	game:insert(slingshotString)
	--joint = physics.newJoint( "pivot", slingshot, slingshotString, 55, 220 )

	slingshot = display.newImage( "slingshot.png" )
	slingshot.x = 170; slingshot.y = groundReferencePoint - 180
	physics.addBody( slingshot, "static", { friction=0.5 } )
	slingshot.bodyName = "slingShot"
	game:insert(slingshot)

	------------------------------------------------------------
	-- Simple score display

	local scoreDisplay = ui.newLabel{
		bounds = { display.contentWidth - 120, 10 + display.screenOriginY, 100, 24 }, -- align label with right side of current screen
		text = "0",
		--font = "Trebuchet-BoldItalic",
		textColor = { 255, 225, 102, 255 },
		size = 32,
		align = "right"
	}

	score = 0
	scoreDisplay:setText( score )


	------------------------------------------------------------
	-- Life display


	local lifeBar = ui.newBar{
		bounds = { 0, 10 + display.screenOriginY, 5, 5 },
		lineColor = { 0, 255, 50, 255 },
		size = life,
		width = 5
	}
	lifeBar:setSize( life )
	
	------------------------------------------------------------
	-- boost display


	local boostBar = ui.newBar{
		bounds = { 0, 300 + display.screenOriginY, 5, 5 },
		lineColor = { 0, 255, 50, 255 },
		size = boost,
		width = 5
	}
	boostBar:setSize( boost )

	local function showExplosion()
		lifeBar:setSize ( 0 )
		noahDestructor:removeSelf()
		explosion = display.newImage( "explosion.png" )
		explosion.x = 100; explosion.y = 230
	end

	local tPrevious = system.getTimer()
	local tNotMovingPrevious = system.getTimer()
	local tAdShownPrevious = system.getTimer()
	local function frameCheck( event )
		local tNotMovingDelta = (event.time - tNotMovingPrevious)
		local tDelta = (event.time - tPrevious)
		local tAddShown = (event.time - tAdShownPrevious)
		if noahDestructor.x > ( worldLength - 2 ) * 960 then
			AddSection()
			game:insert( noahDestructor )
		end
		if noahDestructor.x > score then
			score = noahDestructor.x
			scoreDisplay:setText( string.format( "%i", score ) )
		end
		if (noahDestructor.x > 100) then
			game.x = -noahDestructor.x + 100
		end
		if (noahDestructor.y < 220) then
			game.y = -noahDestructor.y + 220
		end
		if noahDestructor ~= nil then
			vx, vy = noahDestructor:getLinearVelocity()
			if vx < 35 and vy < 35 and tNotMovingDelta > 100 then
				tNotMovingPrevious = event.time
				life = life - 5
				lifeBar:setSize( life )
			end
		end
		if life <= 0 then			
			Runtime:removeEventListener( "enterFrame", frameCheck )
			Runtime:removeEventListener( "enterFrame", removeLifeLava )
			Runtime:removeEventListener( "collision", onGlobalCollision )
			--[[
			noahDestructor:removeEventListener( "touch", onTouch )
			noahDestructor:removeEventListener( "collision", noahDestructor )
			noahDestructor:removeEventListener( "postCollision", noahDestructor )
			--]]
			showExplosion()
			onDeath()
		end
	end
	
	local jetpackButton	
	local tJetpack = system.getTimer()
	local function applyJetpackBoost( event )
		local tDelta = (event.time - tJetpack)
		if boost > 0 then
			if tDelta > 150 and noahDestructor ~= nil then	
				tJetpack = event.time
				boost = boost - 10
				boostBar:setSize( boost )
				noahDestructor:applyLinearImpulse( 2, -15, noahDestructor.x, noahDestructor.y )
			end
		else
			jetpackButton = ui.newButton{
				default = "jetPack.png",
				emboss = true,
				x = 445,
				y = 245
			}
			Runtime:removeEventListener( "enterFrame", applyJetpackBoost )
		end
	end
		
	local function startJets()		
		Runtime:addEventListener( "enterFrame", applyJetpackBoost )
	end
	
	local function endJets()
		Runtime:removeEventListener( "enterFrame", applyJetpackBoost )
	end
	
	jetpackButton = ui.newButton{
		default = "jetPack.png",
		over = "jetPackOver.png",
		onPress = startJets,
		onRelease = endJets,
		emboss = true,
		x = 445,
		y = 245
	}
	
	local tLava = system.getTimer()
	local function removeLifeLava( event )
		local tDelta = (event.time - tLava)
		if tDelta > 150 then	
			tLavaPrevious = event.time
			life = life - 3
			lifeBar:setSize( life )
		end
	end	
	
	if params.default then
		button = display.newGroup()
		default = display.newImage( params.default )
		button:insert( default, true )
	end
	
	if params.over then
		over = display.newImage( params.over )
		over.isVisible = false
		button:insert( over, true )
	end

	local function onTouch( event )
		local t = event.target

		local phase = event.phase
		if "began" == phase then
			-- Make target the top-most object
			local parent = t.parent
			parent:insert( t )
			display.getCurrentStage():setFocus( t )
			-- Spurious events can be sent to the target, e.g. the user presses 
			-- elsewhere on the screen and then moves the finger over the target.
			-- To prevent this, we add this flag. Only when it's true will "move"
			-- events be sent to the target.
			t.isFocus = true

			-- Store initial position
			t.x0 = event.x - t.x
			t.y0 = event.y - t.y
		elseif t.isFocus then
			if "moved" == phase then
				-- Make object move (we subtract t.x0,t.y0 so that moves are
				-- relative to initial grab point, rather than object "snapping").
				t.x = event.x - t.x0
				t.y = event.y - t.y0
			elseif "ended" == phase or "cancelled" == phase then
				display.getCurrentStage():setFocus( nil )
				t.isFocus = false
				slingshot:removeSelf()
				slingshotString:removeSelf()
				physics.addBody( t, { density=3.0, friction=0.1, bounce=0, shape=noahDestructorShape } )
				game:insert(t)
				t.bodyName = "noahDestructorDynamic"
				if t.x<1 then
					t.x = 1
				end
				if t.y>295 then
					t.y = 295
				end
				t:removeEventListener( "touch", onTouch )
				t:applyLinearImpulse( 2 * (140 - t.x) , 1 * (190 - t.y), t.x, t.y )
				Runtime:addEventListener( "enterFrame", frameCheck )
			end
		end

		-- Important to return true. This tells the system that the event
		-- should not be propagated to listeners of any objects underneath.
		return true
	end

	noahDestructor:addEventListener( "touch", onTouch )
	
	function boostNoah()
		noahDestructor:applyForce( 100, 100, noahDestructor.x, noahDestructor.y )
	end

	----------------------------------------------------------
	-- Two collision types (run Corona Terminal to see output)
	----------------------------------------------------------


	-- METHOD 1: Use table listeners to make a single object report collisions between "self" and "other"

	local function onLocalCollision( self, event )
		if ( event.phase == "began" ) then
			print( self.bodyName .. ": collision began with " .. event.other.bodyName )
			if self.bodyName == "lava" or event.other.bodyName == "lava" then
				life = life - 1
				lifeBar:setSize( life )
				Runtime:addEventListener( "enterFrame", removeLifeLava )
			elseif event.other.bodyName == "star" then
				noahDestructor:applyLinearImpulse( 100, -100, noahDestructor.x, noahDestructor.y )
			elseif event.other.bodyName == "bacon" then
				if life > 74 then
					life = 100
				else
					life = life + 25
				end			
				lifeBar:setSize( life )
				noahDestructor:applyLinearImpulse( -10, -50, noahDestructor.x, noahDestructor.y )
			end

			elseif ( event.phase == "ended" ) then
				print( self.bodyName .. ": collision ended with " .. event.other.bodyName )
				if self.bodyName == "lava" or event.other.bodyName == "lava" then				
					Runtime:removeEventListener( "enterFrame", removeLifeLava )
				end
			end
	end

	noahDestructor.collision = onLocalCollision
	noahDestructor:addEventListener( "collision", noahDestructor )
		

	-- METHOD 2: Use a runtime listener to globally report collisions between "object1" and "object2"
	-- Note that the order of object1 and object2 may be reported arbitrarily in any collision

	local tPrevious = system.getTimer()
	local function onGlobalCollision( event )
		if ( event.phase == "began" ) then
			print( "Global report: " .. event.object1.bodyName .. " & " .. event.object2.bodyName .. " collision began" )
		elseif ( event.phase == "ended" ) then

			print( "Global report: " .. event.object1.bodyName .. " & " .. event.object2.bodyName .. " collision ended" )

		end
		
		print( "**** " .. event.element1 .. " -- " .. event.element2 )
		
	end

	Runtime:addEventListener( "collision", onGlobalCollision )


	-------------------------------------------------------------------------------------------
	-- New pre- and post-collision events (run Corona Terminal to see output)
	--
	-- preCollision can be quite "noisy", so you probably want to make its listeners
	-- local to the specific objects you care about, rather than a global Runtime listener
	-------------------------------------------------------------------------------------------

	local function onLocalPreCollision( self, event )
		-- This new event type fires shortly before a collision occurs, so you can use this if you want
		-- to override some collisions in your game logic. For example, you might have a platform game
		-- where the character should jump "through" a platform on the way up, but land on the platform
		-- as they fall down again.
		
		-- Note that this event is very "noisy", since it fires whenever any objects are somewhat close!

		--print( "preCollision: " .. self.bodyName .. " is about to collide with " .. event.other.bodyName )
		

	end

	local function onLocalPostCollision( self, event )
		-- This new event type fires only after a collision has been completely resolved. You can use 
		-- this to obtain the calculated forces from the collision. For example, you might want to 
		-- destroy objects on collision, but only if the collision force is greater than some amount.
		
		---[[
		if ( event.force > 20.0 ) then
			print( "postCollision force: " .. event.force .. ", friction: " .. event.friction )
			life = life - ( string.format( "%i", event.force / 20  ) )
			lifeBar:setSize( life )
		end--]]
	end

	-- Here we assign the above two functions to local listeners within noahDestructor only, using table listeners:

	noahDestructor.postCollision = onLocalPostCollision
	noahDestructor:addEventListener( "postCollision", noahDestructor )
		
	function scene:clearAll()	
		print("Clearing All")
		for i,v in ipairs(game) do
			game[i]:removeSelf()
		end
		game:removeSelf()
		physics = nil
		ui = nil
		if explosion~= nil then
			explosion:removeSelf()
		end
	end
	
	return scene
end