module(..., package.seeall)

function new( arguments )
	local scene = {}
	require "sprite"
	local tbaUI = require( "tbaUI" )
	require('socket')
	--physics.setDrawMode( "hybrid" )
	local groundReferencePoint = 335
	local mainCharacter
	local mainContainerGroup
	local game
	local overlayDisplay
	---[[load sounds
	local explosionSound = audio.loadSound("grenade.mp3")
	local boingSound = audio.loadSound("boing.ogg")
	local swooshSound = audio.loadSound("swoosh.mp3")	
	local bounceSound = audio.loadSound("bounce.mp3")	
	local owSound = audio.loadSound("ow.ogg")	
	local jetSound = audio.loadSound("jetFuel.mp3")	
	local jetContinuousSound = audio.loadSound("jetFuelContinuous.mp3")	
	--]]------
	local totalScore = {}
	local timeLeft = 100
	local startingSkyX1 = -45
	local startingSkyX2 = 515
	timeBar = nil
	math.randomseed( os.time() )
	math.random()
	---[[
	if arguments ~= nil and # arguments > 1 and arguments[2] == true then						
		timeMode = true
		timeBar = tbaUI.newBar{
			bounds = { 0, 290 + display.screenOriginY, 5, 5 },
			lineColor = { 0, 255, 50, 255 },
			size = timeLeft,
			width = 5
		}
		timeBar.bodyName = "timeBar"
		timeBar:setSize( timeLeft )
		timeBar.isVisible = true
		print( "timeMode on")
		local tTimeLeft = system.getTimer()
		local function timeCheck( event )
			local tTimeLeftDelta = (event.time - tTimeLeft)
			if timeMode and tTimeLeftDelta > 750 then
				tTimeLeft = event.time;
				timeLeft = timeLeft - 1
				timeBar:setSize( timeLeft )
			end			
			if timeLeft <=0 then
				Runtime:removeEventListener( "enterFrame", timeCheck )
				if timebar ~= nil then timeBar:removeSelf() end
			end
		end
		Runtime:addEventListener( "enterFrame", timeCheck )
	end
	--]]
	function start()
		print("Starting Super Launch")
		physics.start()
		--physics.setDrawMode( "hybrid" )
		worldLength = 0
		--local slingShot
		local slingShotString
		local life = 100
		local explosion
		local boost = 100
		local worldLength = 0
		mainContainerGroup = display.newGroup()
		game = display.newGroup()
		mainContainerGroup:insert( game )
		game.x = 0
		overlayDisplay = display.newGroup()
		mainContainerGroup:insert( overlayDisplay )	
						
		-- Sky and ground graphics
		local function createFirstSection()
		
			sky = display.newImage( "sky.png", true )
			game:insert( sky )
			sky:setReferencePoint( display.CenterLeftReferencePoint )
			sky.x = startingSkyX1; sky.y = 140
			msky = display.newImage( "skymiddle.png", true )
			game:insert( msky )
			msky:setReferencePoint( display.CenterLeftReferencePoint )
			msky.x = startingSkyX1; msky.y = -180
			tsky = display.newImage( "skytop.png", true )
			game:insert( tsky )
			tsky:setReferencePoint( display.CenterLeftReferencePoint )
			tsky.x = startingSkyX1; tsky.y = -500
			ttsky = display.newImage( "skytransition.png", true )
			game:insert( ttsky )
			ttsky:setReferencePoint( display.CenterLeftReferencePoint )
			ttsky.x = startingSkyX1; ttsky.y = -820
			sky2 = display.newImage( "sky.png", true )
			game:insert( sky2 )
			sky2:setReferencePoint( display.CenterLeftReferencePoint )
			sky2.x = startingSkyX2; sky2.y = 140
			msky2 = display.newImage( "skymiddle.png", true )
			game:insert( msky2 )
			msky2:setReferencePoint( display.CenterLeftReferencePoint )
			msky2.x = startingSkyX2; msky2.y = -180
			tsky2 = display.newImage( "skytop.png", true )
			game:insert( tsky2 )
			tsky2:setReferencePoint( display.CenterLeftReferencePoint )
			tsky2.x = startingSkyX2; tsky2.y = -500
			ttsky2 = display.newImage( "skytransition.png", true )
			game:insert( ttsky2 )
			ttsky2:setReferencePoint( display.CenterLeftReferencePoint )
			ttsky2.x = startingSkyX2; ttsky2.y = -820

			local grass = display.newImage( "grass.png", true )
			game:insert( grass )
			grass.x = 160; grass.y = groundReferencePoint - 20
			physics.addBody( grass, "static", { friction=0.1, bounce=0.25, shape={ 480,60, -480,60, -480,-30, 480,-30 } } )
			grass.bodyName = "grass1"
		end
	
		local function AddSection()
			worldLength = worldLength + 1
			local addition = 160 + ( (worldLength - 1) * 960 )
			
			local dgrass
			if worldLength > 1 and math.random(5) < 3 then
				dgrass = display.newImage( "lava.png", true )
				dgrass.bodyName = "lava"..worldLength
				dgrass.x = addition; dgrass.y = groundReferencePoint - 20
				physics.addBody( dgrass, "static", { friction=0.7, bounce=0.2, shape={ 480,60, -480,60, -480,-30, 480,-30 } } )
			else
				dgrass = display.newImage( "grass.png", true )
				dgrass.bodyName = "grass"..worldLength
				dgrass.x = addition; dgrass.y = groundReferencePoint - 20
				physics.addBody( dgrass, "static", { friction=0.1, bounce=0.25, shape={ 480,60, -480,60, -480,-30, 480,-30 } } )
			end
			
			game:insert( dgrass )

			if worldLength > 2 then		
				if math.random(100) < 83 then
					if math.random(5) < 3 then
						local trampoline = display.newImage( "trampoline.png" )
						trampoline.x = addition + math.random( 40, 920 ); trampoline.y = groundReferencePoint - 50
						trampoline.bodyName = "trampoline"..worldLength
						physics.addBody( trampoline, "static", { friction=0, bounce=5, shape={ 20,1, -20,1, -20,-1, 20,-1 } } )	
						game:insert( trampoline )	
						trampoline:toFront()
					else						
						local ramp = display.newImage( "ramp.png" )
						ramp.x = addition + math.random( 40, 920 ); ramp.y = groundReferencePoint - 75
						ramp.bodyName = "ramp"..worldLength
						physics.addBody( ramp, "static", { friction=0, bounce=.2, shape={ 40,25, -40,25, 40,-31 } } )	
						game:insert( ramp )	
						ramp:toFront()	
					end
				else 
					if math.random(5) <4 then
						local spikeWall = display.newImage( "spikewall.png" )
						spikeWall.x = addition - math.random( 40, 920 ); spikeWall.y = groundReferencePoint - 90
						spikeWall.bodyName = "spikeWall"..worldLength
						physics.addBody( spikeWall, "static", { density=10, friction=1, bounce=0, shape={ -20,-43, 38,40, 22,40, -36,-43 } } )
						game:insert( spikeWall )
						spikeWall:toFront()	
					else
						local keg = display.newImage( "keg.png" )
						keg.x = addition - math.random( 40, 920 ); keg.y = groundReferencePoint - 75
						keg.bodyName = "keg"..worldLength
						physics.addBody( keg, "static", { friction=1, bounce=0 } )
						game:insert( keg )
						keg:toFront()	
					end
				end
					
				local star = display.newImage( "star.png" )
				star.x = addition + math.random( 40, 920 ); star.y = math.random( -500, 140 )
				star.bodyName = "star"
				physics.addBody( star, "static", { friction=0, bounce=0 } )
				star.isSensor = true
				game:insert( star )
				 star:toFront()	
				
				local bacon = display.newImage( "bacon.png" )
				bacon.x = addition + math.random( 40, 920 ); bacon.y = math.random( -500, 140 )
				bacon.bodyName = "bacon"
				physics.addBody( bacon, "static", { friction=0, bounce=0 } )
				bacon.isSensor = true
				game:insert( bacon )
				bacon:toFront()	
				
				if math.random(100) > 83 then
					local bomb = display.newImage( "bomb.png" )
					bomb.x = addition + math.random( 40, 920 ); bomb.y = math.random( -500, 140 )
					bomb.bodyName = "bomb"
					physics.addBody( bomb, "static", { friction=0, bounce=0 } )
					bomb.isSensor = true
					game:insert( bomb )
					bomb:toFront()	
				end
			end
		end
		
		createFirstSection()
		for i=1,2 do
			AddSection()
		end	
		
		local timeBar
		
		mainCharacterShape = { 15,-22, 16,0, 14,20, 10,31, -10,32, -14,20, -19,-6, -14,-20 }

		if arguments ~= nil then
			print ("Number of Arguments = " .. #arguments)
			local character = arguments[1]
			print("Character is: "..character)
			local sheet1
			if character == "noah" then
				sheet1 = sprite.newSpriteSheet( "noahSprite.png", 64, 64 )	
			elseif character == "baby" then
				sheet1 = sprite.newSpriteSheet( "babySprite.png", 44, 64 )
			elseif character == "dog" then
				sheet1 = sprite.newSpriteSheet( "dogSprite.png", 64, 80 )
			end
			local spriteSet1 = sprite.newSpriteSet(sheet1, 1, 4)
			sprite.add( spriteSet1, "mainCharacterSprite", 1, 4, 500, 0 ) -- play 8 frames every 1000 ms	
			mainCharacter = sprite.newSprite( spriteSet1 )	
			if character == "dog" then mainCharacter:rotate(90) end
		else
			local sheet1 = sprite.newSpriteSheet( "noahSprite.png", 64, 64 )
			local spriteSet1 = sprite.newSpriteSet(sheet1, 1, 4)
			sprite.add( spriteSet1, "mainCharacterSprite", 1, 4, 500, 0 ) -- play 8 frames every 1000 ms
			mainCharacter = sprite.newSprite( spriteSet1 )	
		end
		mainCharacter.x = 160; mainCharacter.y = groundReferencePoint - 200

		slingshotString = display.newImage( "string.png" )
		slingshotString.x = 150; slingshotString.y = groundReferencePoint - 180
		slingshotString.bodyName = "slingShotString"
		game:insert(slingshotString)
		--joint = physics.newJoint( "pivot", slingshot, slingshotString, 55, 220 )
--[[
		slingshot = display.newImage( "slingshot.png" )
		slingshot.x = 170; slingshot.y = groundReferencePoint - 180
		--physics.addBody( slingshot, "static", { friction=0.5 } )
		slingshot.bodyName = "slingShot"
		game:insert(slingshot)
--]]
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


		local lifeBar = tbaUI.newBar{
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


		local boostBar = tbaUI.newBar{
			bounds = { 400, 290 + display.screenOriginY, 5, 5 },
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
			explosion.x = mainCharacter.x; explosion.y = 230
			local explosionChannel = audio.play( explosionSound, { channel=2 }  )
			explosion:play()
		end

		local function showBlood()
			blood = display.newImage( "blood.png" )
			game:insert( blood )
			blood .x = mainCharacter.x + 10; blood .y = mainCharacter.y
		end
		
		local function showDeath( deathType )
			lifeBar:setSize( 0 )
			boostBar:setSize ( 0 )
			if deathType == "explosion" then
				showExplosion()
			elseif deathType == "bloody" then
				showBlood()
			end
			mainCharacter:pause()
			mainCharacter.bodyType = "static"
			local menuButton = nil
			local restartButton = nil
			
			local menuButtonPress = function( event )
				menuButton.isVisible = false
				timeLeft = 0
				Runtime:removeEventListener( "enterFrame", timeCheck )
				if timebar ~= nil then timeBar:removeSelf() end
				--TODO/FIX--scoreDisplay.parent:remove( scoreDisplay )
				print("Clearing All "..game.numChildren.."in Game")	
				while game.numChildren > 0	do		
						if game[1] ~= nil then
							if game[1].bodyName ~= nil then
								print("Clearing "..game[1].bodyName)
							end
							game:remove( 1 )
						end
				end
				while overlayDisplay.numChildren > 0	do	
					print("Clearing All "..overlayDisplay.numChildren.."in overlayDisplay")	
					for i=1, overlayDisplay.numChildren do
						if overlayDisplay[i] ~= nil then
							if overlayDisplay[i].bodyName ~= nil then
								print("Clearing "..overlayDisplay[i].bodyName)
							end
							overlayDisplay:remove( i )
						end
					end
				end
				game:removeSelf()
				overlayDisplay:removeSelf()
				mainContainerGroup:removeSelf()
				if restartButton ~= nil then restartButton:removeSelf() end
				physics = nil
				ui = nil
				audio.stop( backgroundMusicChannel )
				director:changeScene("mainMenu", "moveFromLeft")
			end
						
			menuButton = ui.newButton{
				default = "buttonRed.png",
				over = "buttonRedOver.png",
				onPress = menuButtonPress,
				text = "Return To Menu",
				emboss = true,
				x = 240,
				y = 55
			}
			menuButton.isVisible = true
			menuButton.bodyName = "menuButton"
			--overlayDisplay:insert(menuButton)
			
			
			local restartButtonPress = function( event )
				
				restartButton.isVisible = false
				--TODO: FIX--scoreDisplay.parent:remove( scoreDisplay )				
				
				while game.numChildren > 0	do		
					print("Clearing All "..game.numChildren.."in Game")				
					for i=1, game.numChildren do
						if game[i] ~= nil then
							if game[i].bodyName ~= nil then
								print("Clearing "..game[i].bodyName)
							end
							game:remove( i )
						end
					end
				end
				while overlayDisplay.numChildren > 0	do	
					print("Clearing All "..overlayDisplay.numChildren.."in overlayDisplay")	
					for i=1, overlayDisplay.numChildren do
						if overlayDisplay[i] ~= nil then
							if overlayDisplay[i].bodyName ~= nil then
								print("Clearing "..overlayDisplay[i].bodyName)
							end
							overlayDisplay:remove( i )
						end
					end
				end
				menuButton.isVisible = false
				restartButton.isVisible = false
				--director:changeScene("testChange", "crossFade", arguments)
				start()
			end
			
			if #totalScore == 5 then
					local lowestScoreIndex = 1
					local lowestScore = totalScore[1]
					for i=2, #totalScore do
						if lowestScore > totalScore[i] then
							lowestScoreIndex = i
							lowestScore = totalScore[i]
						end
					end
					if score > lowestScore then
						totalScore[lowestScoreIndex] = score
						print ("Replacing score "..lowestScore.." with "..score)
					end
				else
					table.insert(totalScore, score)
				end
			if timeMode then
				print ("Time Mode is on")
			else
				print("Time Mode is off")
			end
			if timeMode and timeLeft <= 0 then
				local aggregatedScore = 0
				for i=1, #totalScore do
					aggregatedScore = aggregatedScore + totalScore[i]
					print("Score " .. i .. " = " .. totalScore[i])
				end
				local totalDisplay = ui.newLabel{
						bounds = { display.contentWidth - 320, 200 + display.screenOriginY, 100, 24 }, -- align label with right side of current screen
						text = string.format( "%i", aggregatedScore ),
						--font = "Trebuchet-BoldItalic",
						textColor = { 255, 225, 102, 255 },
						size = 32,
						align = "center"
					}
					totalDisplay.bodyName = "totalDisplay"
					overlayDisplay:insert( totalDisplay )
					score = 0
					
					--Open GameData.sqlite.  If the file doesn't exist it will be created
					local path = system.pathForFile("GameData.sqlite", system.DocumentsDirectory)
					db = sqlite3.open( path )   
					 
					--Handle the applicationExit event to close the db
					local function onSystemEvent( event )
						if( event.type == "applicationExit" ) then              
							db:close()
						end
					end
					 
					--setup the system listener to catch applicationExit
					Runtime:addEventListener( "system", onSystemEvent )

					--Setup the high score table if it doesn't exist
					local tablesetup = [[CREATE TABLE IF NOT EXISTS tblHighScores (ixHighScore INTEGER PRIMARY KEY, sName, dScore, dtCreated);]]
					print(tablesetup)
					db:exec( tablesetup )

					--Add rows with a auto index in 'id'. You don't need to specify a set of values because we're populating all of them
					local testvalue = {}
					local tablefill =[[INSERT INTO tblHighScores VALUES (NULL, 'New User', ]]..aggregatedScore..[[, 2011-05-13);]]
					db:exec( tablefill )

					--print the sqlite version to the terminal
					print( "version " .. sqlite3.version() )
					 
					--print all the table contents
					for row in db:nrows("SELECT * FROM tblHighScores") do
					  local text = row.sName.." - "..row.dScore.." - "..row.dtCreated
					  local t = display.newText(text, 0, 50 + (40 * row.ixHighScore), null, 16)
					  t:setTextColor(255,0,255)
					  overlayDisplay:insert( t )
					end
			else
				restartButton = ui.newButton{
					default = "buttonRed.png",
					over = "buttonRedOver.png",
					onPress = restartButtonPress,
					text = "Restart",
					emboss = true,
					x = 240,
					y = 195
				}
				restartButton.isVisible = true
				restartButton.bodyName = "restartButton"	
			end
		end

		local tPrevious = system.getTimer()
		local tNotMovingPrevious = system.getTimer()
		local tAdShownPrevious = system.getTimer()
		local function frameCheck( event )
			local tNotMovingDelta = (event.time - tNotMovingPrevious)
			local tDelta = (event.time - tPrevious)
			local tAddShown = (event.time - tAdShownPrevious)
			if mainCharacter.x > ( worldLength - 2 ) * 960 then
				AddSection()
			mainCharacter:toFront();
			end
			if mainCharacter.x > score then
				score = mainCharacter.x
				scoreDisplay:setText( string.format( "%i", score ) )
			end
			if (mainCharacter.x > 100) then
				game.x = math.ceil(-mainCharacter.x) + 120
			end
			if (mainCharacter.y < 220) then
				game.y = -mainCharacter.y - math.fmod(-mainCharacter.y, 2) + 220
			end
			if mainCharacter ~= nil then
				vx, vy = mainCharacter:getLinearVelocity()
				if vx < 35 and vy < 5 and tNotMovingDelta > 100 then
					tNotMovingPrevious = event.time
					life = life - 5
					lifeBar:setSize( life )
				end
			end
			
			
			if ( game.x + sky.x ) > sky.contentWidth then
				sky:translate( -(sky.contentWidth * 2), 0)
			end
			if ( game.x + sky2.x ) > sky.contentWidth then
				sky2:translate( -(sky2.contentWidth * 2), 0)
			end
			
			if ( game.x + sky.x + sky.contentWidth) < -40 then
				sky:translate( sky.contentWidth * 2, 0)
			end
			if ( game.x + sky2.x + sky2.contentWidth) < -40 then
				sky2:translate( sky2.contentWidth * 2, 0)
			end
			
			local mskyTotal = game.x + msky.x + msky.contentWidth
			local msky2Total = game.x + msky2.x + msky2.contentWidth
			
			if ( mskyTotal < 0 or mskyTotal > msky.contentWidth * 2 or msky2Total < 0 or msky2Total > msky2.contentWidth * 2 ) and game.y > 20 then
				msky.x = sky.x
				msky2.x = sky2.x
			end			
			
			local tskyTotal = game.x + tsky.x + tsky.contentWidth
			local tsky2Total = game.x + tsky2.x + tsky2.contentWidth
					
			if ( tskyTotal < 0 or tskyTotal > tsky.contentWidth * 2 or tsky2Total < 0 or tsky2Total > tsky2.contentWidth * 2 ) and game.y > 220 then
				tsky.x = sky.x
				tsky2.x = sky2.x
			end
			
			local ttskyTotal = game.x + ttsky.x + ttsky.contentWidth
			local ttsky2Total = game.x + ttsky2.x + ttsky2.contentWidth
					
			if ( ttskyTotal < 0 or ttskyTotal > ttsky.contentWidth * 2 or ttsky2Total < 0 or ttsky2Total > ttsky2.contentWidth * 2 ) and game.y > 400 then
				ttsky.x = sky.x
				ttsky2.x = sky2.x
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
		local jetpackSoundChannel
		local tJetpack = system.getTimer()
		local function applyJetpackBoost( event )
			local tDelta = (event.time - tJetpack)
			if boost > 0 then
				if tDelta > 150 and mainCharacter ~= nil then	
					tJetpack = event.time
					boost = boost - 10
					boostBar:setSize( boost )
					mainCharacter:applyLinearImpulse( 10, -30, mainCharacter.x - 1, mainCharacter.y )
				end
			else
				jetpackButton.isVisible = false	
				jetpackButton:removeSelf();
				jetpackButton = display.newImage( "jetPack.png" )
				jetpackButton.x = 445; jetpackButton.y = 245
				jetpackButton.bodyName = "Jet Pack Button"
				overlayDisplay:insert(jetpackButton)
				Runtime:removeEventListener( "enterFrame", applyJetpackBoost )
				
			end
		end
		local jetChannel
		--[[
		local function playJetContinuousSound()
			jetChannel = audio.play( jetContinuousSound, ({ channel=4 }, onComplete=playJetContinuousSound) )
		end
		--]]
		local function startJets()
			--jetChannel = audio.play( jetSound, ({ channel=4 }, onComplete=playJetContinuousSound  ) )
			jetChannel = audio.play( jetSound,{ channel=4 })
			Runtime:addEventListener( "enterFrame", applyJetpackBoost )
		end
		
		local function endJets()
			audio.stop( jetChannel )
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
			print ( "lava Delta = "..tDelta)
			if tDelta > 25 then	
				tLavaPrevious = event.time
				life = life - 1
				lifeBar:setSize( life )
				local owChannel = audio.play( owSound, { channel=4 }  ) 
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
					--slingshot:removeSelf()
					slingshotString:removeSelf()
					local swooshChannel = audio.play( swooshSound, { channel=2 }  )
					t:prepare("mainCharacterSprite")
					t:play()
					if t.x<1 then
						t.x = 1
					end
					if t.y>185 then
						t.y = 184
					end
					physics.addBody( t, { density=5.0, friction=0.1, bounce=0, shape=mainCharacterShape } )
					game:insert(t)
					t.bodyName = "mainCharacterDynamic"
					t.isFixedRotation = true
					--t.angularDamping = 10
					t:removeEventListener( "touch", onTouch )
					t:applyLinearImpulse( 2 * (170 - t.x) , 1 * (groundReferencePoint - 200 - t.y), t.x + 9, t.y)
					Runtime:addEventListener( "enterFrame", frameCheck )
				end
			end

			-- Important to return true. This tells the system that the event
			-- should not be propagated to listeners of any objects underneath.
			return true
		end

		mainCharacter:addEventListener( "touch", onTouch )

		----------------------------------------------------------
		-- Two collision types (run Corona Terminal to see output)
		----------------------------------------------------------


		-- METHOD 1: Use table listeners to make a single object report collisions between "self" and "other"

		local function onLocalCollision( self, event )
			if ( event.phase == "began" ) then
				--print( self.bodyName .. ": collision began with " .. event.other.bodyName )
				if self.bodyName == "lava" or event.other.bodyName == "lava" then
					life = life - 1
					lifeBar:setSize( life )
					print("adding lava removal listener")
					Runtime:addEventListener( "enterFrame", removeLifeLava )
				elseif event.other.bodyName == "star" then
					mainCharacter:applyLinearImpulse( 0, -150, mainCharacter.x + 9, mainCharacter.y )
				elseif event.other.bodyName == "bacon" then
					if life > 74 then
						life = 100
					else
						life = life + 25
					end			
					lifeBar:setSize( life )
					mainCharacter:applyLinearImpulse( -10, -75, mainCharacter.x + 9, mainCharacter.y )
				elseif event.other.bodyName == "bomb" then
					if life < 10 then
						life = 0
					else
						life = life - 10
					end
					lifeBar:setSize( life )
					mainCharacter:applyLinearImpulse( 15, -5, mainCharacter.x, mainCharacter.y )
				elseif string.find( event.other.bodyName, "spikeWall" ) ~= nil then
					print("removing event Listeners")
					Runtime:removeEventListener( "enterFrame", frameCheck )
					Runtime:removeEventListener( "enterFrame", removeLifeLava )
					Runtime:removeEventListener( "collision", onGlobalCollision )
					showDeath ( "bloody" )					
				end

				elseif ( event.phase == "ended" ) then
					--print( self.bodyName .. ": collision ended with " .. event.other.bodyName )
					if self.bodyName == "lava" or event.other.bodyName == "lava" then				
						Runtime:removeEventListener( "enterFrame", removeLifeLava )
					end
				end
		end

		mainCharacter.collision = onLocalCollision
		mainCharacter:addEventListener( "collision", mainCharacter )
			

		-- METHOD 2: Use a runtime listener to globally report collisions between "object1" and "object2"
		-- Note that the order of object1 and object2 may be reported arbitrarily in any collision

		local tPrevious = system.getTimer()
		local function onGlobalCollision( event )
			if ( event.phase == "began" ) then
				--aprint( "Global report: " .. event.object1.bodyName .. " & " .. event.object2.bodyName .. " collision began" )
			elseif ( event.phase == "ended" ) then

				--print( "Global report: " .. event.object1.bodyName .. " & " .. event.object2.bodyName .. " collision ended" )

			end
			
			--print( "**** " .. event.element1 .. " -- " .. event.element2 )
			
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
			bodyName = event.other.bodyName
			if ( event.force > 20.0 ) then
				--print( "postCollision force: " .. event.force .. ", friction: " .. event.friction )
				life = life - ( string.format( "%i", event.force / 50  ) )
				lifeBar:setSize( life )
				local impactChannel
				if string.find(bodyName, "lava") ~= nil or string.find(bodyName, "grass") ~= nil then
					impactChannel = audio.play( boingSound, { channel=3 }  ) 
				elseif string.find(bodyName, "ramp") ~= nil then
					impactChannel = audio.play( swooshSound, { channel=3 }  ) 
				elseif string.find(bodyName, "trampoline") ~= nil then
					impactChannel = audio.play( bounceSound, { channel=3 }  ) 
				elseif string.find(bodyName, "keg") ~= nil then
					impactChannel = audio.play( owSound, { channel=3 }  ) 
				elseif string.find(bodyName, "spikeWall") ~= nil then
					impactChannel = audio.play( owSound, { channel=3 }  ) 
				end
			end--]]
		end

		-- Here we assign the above two functions to local listeners within mainCharacter only, using table listeners:

		mainCharacter.postCollision = onLocalPostCollision
		mainCharacter:addEventListener( "postCollision", mainCharacter )
		
		return game
	end
	
	-- Back Key listener
	local function onKeyEventSuperLaunch( event )
		local phase = event.phase
		local keyName = event.keyName

		if (phase == "up" and keyName == "back") then 
			Runtime:removeEventListener( "key", onKeyEvent );
			timer.performWithDelay(100, moveBack("characterSelect", "moveFromLeft", {"superLaunch"}), 1)
		end
	end
	
	-- Add the back key callback
	Runtime:addEventListener( "key", onKeyEventSuperLaunch );	
	
	return start()
end