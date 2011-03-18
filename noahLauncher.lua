module(..., package.seeall)

function new()
	local scene = {}
	require "sprite"
	local physics = require( "physics" )
	local ui = require( "ui" )
	require('socket')
	physics.start()
	physics.setDrawMode( "hybrid" )
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
	local mainContainerGroup = display.newGroup()
	local game = display.newGroup()
	mainContainerGroup:insert( game )
	game.x = 0
	local overlayDisplay = display.newGroup()
	mainContainerGroup:insert( overlayDisplay )	
	math.randomseed( os.time() )
	math.random()

	-- Sky and ground graphics
	local function createFirstSection()
	
		sky = display.newImage( "sky.png", true )
		game:insert( sky )
		sky:setReferencePoint( display.CenterLeftReferencePoint )
		sky.x = -40; sky.y = 120
		msky = display.newImage( "skymiddle.png", true )
		game:insert( msky )
		msky:setReferencePoint( display.CenterLeftReferencePoint )
		msky.x = -40; msky.y = -430
		tsky = display.newImage( "skytop.png", true )
		game:insert( tsky )
		tsky:setReferencePoint( display.CenterLeftReferencePoint )
		tsky.x = -40; tsky.y = -980
		sky2 = display.newImage( "sky.png", true )
		game:insert( sky2 )
		sky2:setReferencePoint( display.CenterLeftReferencePoint )
		sky2.x = 920; sky2.y = 120
		msky2 = display.newImage( "skymiddle.png", true )
		game:insert( msky2 )
		msky2:setReferencePoint( display.CenterLeftReferencePoint )
		msky2.x = 920; msky2.y = -430
		tsky2 = display.newImage( "skytop.png", true )
		game:insert( tsky2 )
		tsky2:setReferencePoint( display.CenterLeftReferencePoint )
		tsky2.x = 920; tsky2.y = -980

		local grass = display.newImage( "grass.png", true )
		game:insert( grass )
		grass.x = 160; grass.y = groundReferencePoint
		physics.addBody( grass, "static", { friction=0.1, bounce=0 } )
		grass.bodyName = "grass1"
	end
	
	spikeWallShape = { -20,-43, 38,40, 22,40, -36,-43 }

	local function AddSection()
		worldLength = worldLength + 1
		local addition = 160 + ( (worldLength - 1) * 960 )
		
		local dgrass
		if worldLength > 1 and math.random(5) < 3 then
			dgrass = display.newImage( "lava.png", true )
			dgrass.bodyName = "lava"
			dgrass.x = addition; dgrass.y = groundReferencePoint
			physics.addBody( dgrass, "static", { friction=0.7, bounce=0.2 } )
		else
			dgrass = display.newImage( "grass.png", true )
			dgrass.bodyName = "grass"..worldLength
			dgrass.x = addition; dgrass.y = groundReferencePoint
			physics.addBody( dgrass, "static", { friction=0.1, bounce=0.3 } )
		end
		
		game:insert( dgrass )

		if worldLength > 2 then		
			if math.random(5) < 4 then
				if math.random(5) < 3 then
					local trampoline = display.newImage( "ramp.png" )
					trampoline.x = addition + math.random( 40, 920 ); trampoline.y = groundReferencePoint - 40
					trampoline.bodyName = "trampoline"..worldLength
					physics.addBody( trampoline, "static", { friction=0, bounce=6, shape={ 20,0, -20,0, -20,-3, 20,-3 } } )	
					game:insert( trampoline )		
				else						
					local ramp = display.newImage( "ramp.png" )
					ramp.x = addition + math.random( 40, 920 ); ramp.y = groundReferencePoint - 65
					ramp.bodyName = "ramp"..worldLength
					physics.addBody( ramp, "static", { friction=0, bounce=.2, shape={ 40,25, -40,25, 40,-31 } } )	
					game:insert( ramp )		
				end
			else 
				if math.random(5) == 1 then
					local spikeWall = display.newImage( "spikewall.png" )
					spikeWall.x = addition - math.random( 40, 920 ); spikeWall.y = groundReferencePoint - 80
					spikeWall.bodyName = "spikeWall"..worldLength
					physics.addBody( spikeWall, "static", { density=10, friction=1, bounce=0, shape=spikeWallShape } )
					game:insert( spikeWall )
				else
					local keg = display.newImage( "keg.png" )
					keg.x = addition - math.random( 40, 920 ); keg.y = groundReferencePoint - 65
					keg.bodyName = "keg"..worldLength
					physics.addBody( keg, "static", { friction=1, bounce=0 } )
					game:insert( keg )
				end
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

	function start( character )
	
		createFirstSection()
		for i=1,2 do
			AddSection()
		end		
		
		noahDestructorShape = { 16,-22, 16,0, 14,20, 10,31, -10,32, -14,20, -19,-6, -14, -20 }
	
		if character ~= nil then
			if character == "noah" then
				local sheet1 = sprite.newSpriteSheet( "noahSprite.png", 64, 64 )
				local spriteSet1 = sprite.newSpriteSet(sheet1, 1, 4)
				sprite.add( spriteSet1, "noahSprite", 1, 4, 500, 0 ) -- play 8 frames every 1000 ms
				noahDestructor = sprite.newSprite( spriteSet1 )		
			elseif character == "baby" then
				local sheet1 = sprite.newSpriteSheet( "babySprite.png", 44, 64 )
				local spriteSet1 = sprite.newSpriteSet(sheet1, 1, 4)
				sprite.add( spriteSet1, "noahSprite", 1, 4, 500, 0 ) -- play 8 frames every 1000 ms
				noahDestructor = sprite.newSprite( spriteSet1 )	
			elseif character == "dog" then
				local sheet1 = sprite.newSpriteSheet( "dogSprite.png", 64, 80 )
				local spriteSet1 = sprite.newSpriteSet(sheet1, 1, 4)
				sprite.add( spriteSet1, "noahSprite", 1, 4, 500, 0 ) -- play 8 frames every 1000 ms
				noahDestructor = sprite.newSprite( spriteSet1 )		
				noahDestructor:rotate(90)
			end
		else
			noahDestructor = display.newImage("noah.png")		
		end
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
		scoreDisplay.bodyName = "scoreDisplay"
		overlayDisplay:insert( scoreDisplay )
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
		lifeBar.bodyName = "lifeBar"
		overlayDisplay:insert( lifeBar )
		lifeBar:setSize( life )
		
		------------------------------------------------------------
		-- boost display


		local boostBar = ui.newBar{
			bounds = { 0, 300 + display.screenOriginY, 5, 5 },
			lineColor = { 0, 255, 50, 255 },
			size = boost,
			width = 5
		}
		boostBar.bodyName = "boostBar"
		overlayDisplay:insert( boostBar )
		boostBar:setSize( boost )

		local function showExplosion()		
			local explosionSheet = sprite.newSpriteSheet( "explosionSprite.png", 170, 130 )
			local explosionSpriteSet = sprite.newSpriteSet(explosionSheet, 1, 4)
			sprite.add( explosionSpriteSet, "explosionSprite", 1, 4, 2500, 1 )
			explosion = sprite.newSprite( explosionSpriteSet )
			game:insert( explosion )
			explosion.x = noahDestructor.x; explosion.y = 230
			explosion:play()
		end

		local function showBlood()
			blood = display.newImage( "blood.png" )
			game:insert( blood  )
			blood .x = noahDestructor.x + 10; blood .y = noahDestructor.y
		end
		
		local function showDeath( deathType )
			lifeBar:setSize( 0 )
			boostBar:setSize ( 0 )
			lifeBar.isVisible = false
			lifeBar = nil
			if deathType == "explosion" then
				showExplosion()
			elseif deathType == "bloody" then
				showBlood()
			end
			noahDestructor:pause()
			noahDestructor.bodyType = "static"
			local menuButton = nil
			local menuButtonPress = function( event )
				menuButton.isVisible = false
				scoreDisplay:getParent():remove( scoreDisplay )
				
				print("Clearing All "..game.numChildren.."in Game")				
				for i=1, game.numChildren, 1 do
					if game[i] ~= nil then
						game:remove( i )
					end
				end
				print("Clearing All "..overlayDisplay.numChildren.."in overlayDisplay")	
				for i=1, overlayDisplay.numChildren, 1 do
					if overlayDisplay[i] ~= nil then
						if overlayDisplay[i].bodyName ~= nil then
							print("Clearing "..overlayDisplay[i].bodyName)
						end
						overlayDisplay:remove( i )
					end
				end
				game:removeSelf()
				overlayDisplay:removeSelf()
				mainContainerGroup:removeSelf()
				physics = nil
				ui = nil
				director:changeScene("screen_Menu", "moveFromLeft")
			end
						
			menuButton = ui.newButton{
				default = "buttonRed.png",
				over = "buttonRedOver.png",
				onPress = menuButtonPress,
				text = "Return To Menu",
				emboss = true,
				x = 240,
				y = 155
			}
			menuButton.isVisible = true
			menuButton.bodyName = "menuButton"
			--overlayDisplay:insert(menuButton)
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
			noahDestructor:toFront();
			end
			if noahDestructor.x > score then
				score = noahDestructor.x
				scoreDisplay:setText( string.format( "%i", score ) )
			end
			if (noahDestructor.x > 100) then
				game.x = math.ceil(-noahDestructor.x) + 120
			end
			if (noahDestructor.y < 220) then
				game.y = -noahDestructor.y - math.fmod(-noahDestructor.y, 2) + 220
			end
			if noahDestructor ~= nil then
				vx, vy = noahDestructor:getLinearVelocity()
				if vx < 35 and vy < 5 and tNotMovingDelta > 100 then
					tNotMovingPrevious = event.time
					life = life - 5
					lifeBar:setSize( life )
				end
			end
			
			
			if ( game.x + sky.x + sky.contentWidth) > sky.contentWidth * 2 then
				sky:translate( -(sky.contentWidth * 2), 0)
			end
			if ( game.x + sky2.x + sky2.contentWidth) > sky.contentWidth * 2 then
				sky2:translate( -(sky2.contentWidth * 2), 0)
			end
			
			if ( game.x + sky.x + sky.contentWidth) < -50 then
				sky:translate( sky.contentWidth * 2, 0)
			end
			if ( game.x + sky2.x + sky2.contentWidth) < -50 then
				sky2:translate( sky2.contentWidth * 2, 0)
			end		
			
			local mskyTotal = game.x + msky.x + msky.contentWidth
			local msky2Total = game.x + msky2.x + msky2.contentWidth
			
			if ( mskyTotal < 0 or mskyTotal > msky.contentWidth * 2 or msky2Total < 0 or msky2Total > msky2.contentWidth * 2 ) and game.y > 160 then
				msky.x = sky.x
				msky2.x = sky2.x
			end			
			
			local tskyTotal = game.x + tsky.x + tsky.contentWidth
			local tsky2Total = game.x + tsky2.x + tsky2.contentWidth
					
			if ( tskyTotal < 0 or tskyTotal > tsky.contentWidth * 2 or tsky2Total < 0 or tsky2Total > tsky2.contentWidth * 2 ) and game.y > 320 then
				tsky.x = sky.x
				tsky2.x = sky2.x
			end
			
			
			if life <= 0 then	
				print("removing event Listeners")
				Runtime:removeEventListener( "enterFrame", frameCheck )
				Runtime:removeEventListener( "enterFrame", removeLifeLava )
				Runtime:removeEventListener( "collision", onGlobalCollision )
				showDeath( "explosion" )
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
					noahDestructor:applyLinearImpulse( 10, -30, noahDestructor.x - 1, noahDestructor.y )
				end
			else
				jetpackButton.isVisible = false				
				jetpackButton = display.newImage( "jetPack.png" )
				jetpackButton.x = 445; jetpackButton.y = 245
				jetpackButton.bodyName = "Jet Pack Button"
				overlayDisplay:insert(jetpackButton)
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
		jetpackButton.bodyName = "Jet Pack Button"
		overlayDisplay:insert(jetpackButton)
		
		local tLava = system.getTimer()
		local function removeLifeLava( event )
			local tDelta = (event.time - tLava)
			if tDelta > 250 then	
				tLavaPrevious = event.time
				life = life - 1
				lifeBar:setSize( life )
			end
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
					t:prepare("noahSprite")
					t:play()
					physics.addBody( t, { density=5.0, friction=0.1, bounce=0, shape=noahDestructorShape } )
					game:insert(t)
					t.bodyName = "noahDestructorDynamic"
					t.isFixedRotation = true
					--t.angularDamping = 10
					if t.x<1 then
						t.x = 1
					end
					if t.y>295 then
						t.y = 295
					end
					t:removeEventListener( "touch", onTouch )
					t:applyLinearImpulse( 2 * (170 - t.x) , 1 * (groundReferencePoint - 200 - t.y), t.x + 9, t.y)
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
					noahDestructor:applyLinearImpulse( 0, -150, noahDestructor.x + 9, noahDestructor.y )
				elseif event.other.bodyName == "bacon" then
					if life > 74 then
						life = 100
					else
						life = life + 25
					end			
					lifeBar:setSize( life )
					noahDestructor:applyLinearImpulse( -10, -75, noahDestructor.x + 9, noahDestructor.y )
				elseif string.find( event.other.bodyName, "spikeWall" ) ~= nil then
					print("removing event Listeners")
					Runtime:removeEventListener( "enterFrame", frameCheck )
					Runtime:removeEventListener( "enterFrame", removeLifeLava )
					Runtime:removeEventListener( "collision", onGlobalCollision )
					showDeath ( "bloody" )					
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
				life = life - ( string.format( "%i", event.force / 50  ) )
				lifeBar:setSize( life )
			end--]]
		end

		-- Here we assign the above two functions to local listeners within noahDestructor only, using table listeners:

		noahDestructor.postCollision = onLocalPostCollision
		noahDestructor:addEventListener( "postCollision", noahDestructor )
	end
	
	local noahButton = nil
	local babyButton = nil
	local dogButton = nil
	
	local function noahButtonPress()
		noahButton.isVisible = false
		babyButton.isVisible = false
		dogButton.isVisible = false
		start( "noah" )
	end
	
	local function babyButtonPress()
		babyButton.isVisible = false
		noahButton.isVisible = false
		dogButton.isVisible = false
		start( "baby" )
	end
	
	local function dogButtonPress()
		babyButton.isVisible = false
		noahButton.isVisible = false
		dogButton.isVisible = false
		start( "dog" )
	end

	noahButton = ui.newButton{
					default = "noah.png",
					onPress = noahButtonPress,
					emboss = true,
					x = 180,
					y = 200
				}
	babyButton = ui.newButton{
					default = "baby.png",
					onPress = babyButtonPress,
					emboss = true,
					x = 320,
					y = 200
				}
	dogButton = ui.newButton{
					default = "dog.png",
					onPress = dogButtonPress,
					emboss = true,
					x = 250,
					y = 100
				}
	return game
end