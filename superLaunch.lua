module(..., package.seeall)
local ui = require("ui")
local storyboard = require( "storyboard" )
local widget = require("widget")
local scene = storyboard.newScene()
local onBackEvent = {}
local frameCheck = {}
local applyJetpackBoost = {}
local endJets
local character

local function addKeyEvent()
	print( "adding Key Listener" )
	Runtime:addEventListener( "key", onBackEvent )
end

function scene:createScene( event )
	print( "creating superLaunch" )
	local group = self.view
	arguments = storyboard.arguments
	
	require "sprite"
	local tbaUI = require( "tbaUI" )
	require('socket')
	--physics.setDrawMode( "hybrid" )
	local groundReferencePoint = 335
	local mainCharacter
	local flame
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
	local launchType = "slingShot"
	local menuButton = nil
	local restartButton = nil
	local timeBar = nil
	local timeLabel = nil
	local lifeBar = nil
	local boostBar = nil
	local timeCheck
	local jetpackButton = nil
	local jetpackButtonOver = nil
	local shootingForTheStarsAchieved = false
	local twentyThousandLeagueAchieved = false
	local removeLifeLava
	
	math.randomseed( os.time() )
	math.random()	
	
	--Open GameData.sqlite.  If the file doesn't exist it will be created
	local path = system.pathForFile("GameData.sqlite", system.DocumentsDirectory)
	db = sqlite3.open( path )   
	---[[
	if arguments ~= nil and # arguments > 1 and arguments[2] == true then
		timeMode = true
		timeBar = tbaUI.newBar{
			bounds = { 0, 305 + display.screenOriginY, 5, 5 },
			lineColor = { 0, 255, 50, 255 },
			size = timeLeft,
			width = 5, 
			beautyBar = true
		}
		timeBar.bodyName = "timeBar"
		timeBar:setSize( timeLeft )
		timeBar.isVisible = true
		
		timeLabel = ui.newLabel{
			bounds = { -25, 275 + display.screenOriginY, 100, 24 },
			text = "Time Remaining",
			--font = "Trebuchet-BoldItalic",
			textColor = { 10, 10, 10, 255 },
			size = 20,
			align = "left"
		}
		timeLabel.bodyName = "timeLabel"
		local function hideTimeLabel()
			if timeLabel ~= nil then timeLabel.isVisible = false end
		end		
		timer.performWithDelay( 4000, hideTimeLabel )
		
		print( "timeMode on")
		local tTimeLeft = system.getTimer()
		function timeCheck( event )
			local tTimeLeftDelta = (event.time - tTimeLeft)
			if timeMode and tTimeLeftDelta > 1000 then
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
		
	lifeLabel = ui.newLabel{
		bounds = { 35, 20 + display.screenOriginY, 100, 24 },
		text = "Life",
		--font = "Trebuchet-BoldItalic",
		textColor = { 10, 10, 10, 255 },
		size = 20,
		align = "left"
	}
	lifeLabel.bodyName = "lifeLabel"
	local function hideLifeLabel()
		if lifeLabel ~= nil then lifeLabel.isVisible = false end
	end	
	--]]
	function start()
		print("Starting Super Launch")
		physics.start()
		worldLength = 0
		--local slingShot
		local slingShotString
		local life = 100
		local explosion
		local boost = 100
		local worldLength = 0
		local showAngle
		mainContainerGroup = display.newGroup()
		group:insert( mainContainerGroup )
		game = display.newGroup()
		mainContainerGroup:insert( game )
		game.x = 0
		overlayDisplay = display.newGroup()
		mainContainerGroup:insert( overlayDisplay )
		flame = display.newImage("flame.png")
		flame.isVisible = false
		game:insert( flame )
		
			
		local roosterSheet = sprite.newSpriteSheet( "roosterSprite.png", 125, 113 )
		local roosterSpriteSet = sprite.newSpriteSet(roosterSheet, 1, 2)
		sprite.add( roosterSpriteSet, "roosterSprite", 1, 2, 1000, 4 )
		local rooster = sprite.newSprite( roosterSpriteSet )	
		game:insert( rooster )
		rooster.isVisible = false
						
		-- Sky and ground graphics
		local function createFirstSection()
		
			--Create Backwards Crap
			---[[
				borderBodyElement = { friction=0.5, bounce=0.3 }
				local borderBottom = display.newRect( -820, 775, 480, 20 )
				borderBottom:setFillColor( 0, 100, 100)		-- make invisible
				physics.addBody( borderBottom, "static", borderBodyElement )
				game:insert( borderBottom )

				local borderLeft = display.newRect( -820, -200, 20, 975 )
				borderLeft:setFillColor( 0, 100, 100)		-- make invisible
				physics.addBody( borderLeft, "static", borderBodyElement )
				game:insert( borderLeft )
---[[
				local borderRight = display.newRect( -360, 300, 20, 800 )
				borderRight:setFillColor( 0, 100, 100)		-- make invisible
				physics.addBody( borderRight, "static", borderBodyElement )
				game:insert( borderRight )
				--]]
				local triangle = display.newImage("triangle.png")
				triangle.x = -600; triangle.y = 160
				
				local triangle2 = display.newImage("triangle.png")
				triangle2.x = -510; triangle2.y = 160

				local pentagon = display.newImage("pentagon.png")
				pentagon.x = -600; pentagon.y = 70

				local pentagon2 = display.newImage("pentagon.png")
				pentagon2.x = -510; pentagon2.y = 70

				local crate = display.newImage("crate.png")
				crate.x = -530; crate.y = 250

				local crateB = display.newImage("crateB.png")
				crateB.x = -430; crateB.y = 250

				local crateC = display.newImage("crateC.png")
				crateC.x = -420; crateC.y = 50

				local soccerball = display.newImage("soccer_ball.png")
				soccerball.x = -600; soccerball.y = 320

				local superball = display.newImage("super_ball.png")
				superball.x = -420; superball.y = 340

				local superball2 = display.newImage("super_ball.png")
				superball2.x = -440; superball2.y = 130

				local superball3 = display.newImage("super_ball.png")
				superball3.x = -430; superball3.y = 180


				triangleShape = { 0,-35, 37,30, -37,30 }
				pentagonShape = { 0,-37, 37,-10, 23,34, -23,34, -37,-10 }

				physics.addBody( crate, { density=2, friction=0.5, bounce=0.4 } )
				physics.addBody( crateB, { density=4, friction=0.5, bounce=0.4 } )
				physics.addBody( crateC, { density=1, friction=0.5, bounce=0.4 } )
				game:insert( crate )
				game:insert( crateB )
				game:insert( crateC )

				physics.addBody( triangle, { density=0.9, friction=0.5, bounce=0.3, shape=triangleShape } )
				physics.addBody( triangle2, { density=0.9, friction=0.5, bounce=0.3, shape=triangleShape } )
				game:insert( triangle )
				game:insert( triangle2 )

				physics.addBody( pentagon, { density=0.9, friction=0.5, bounce=0.4, shape=pentagonShape } )
				physics.addBody( pentagon2, { density=0.9, friction=0.5, bounce=0.4, shape=pentagonShape } )
				game:insert( pentagon )
				game:insert( pentagon2 )

				physics.addBody( soccerball, { density=0.9, friction=0.5, bounce=0.6, radius=38 } )
				physics.addBody( superball, { density=0.9, friction=0.5, bounce=0.8, radius=24 } )
				physics.addBody( superball2, { density=0.9, friction=0.5, bounce=0.8, radius=24 } )
				physics.addBody( superball3, { density=0.9, friction=0.5, bounce=0.8, radius=24 } )
				game:insert( soccerball )
				game:insert( superball )
				game:insert( superball2 )
				game:insert( superball3 )
			--]]
		
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
			llskyStars = display.newImage( "skyStars.png", true )
			game:insert( llskyStars )
			llskyStars:setReferencePoint( display.CenterLeftReferencePoint )
			llskyStars.x = startingSkyX1; llskyStars.y = -1140
			lrskyStars = display.newImage( "skyStars.png", true )
			game:insert( lrskyStars )
			lrskyStars:setReferencePoint( display.CenterLeftReferencePoint )
			lrskyStars.x = startingSkyX2; lrskyStars.y = -1140
			ulskyStars = display.newImage( "skyStars.png", true )
			game:insert( ulskyStars )
			ulskyStars:setReferencePoint( display.CenterLeftReferencePoint )
			ulskyStars.x = startingSkyX1; ulskyStars.y = -1460
			urskyStars = display.newImage( "skyStars.png", true )
			game:insert( urskyStars )
			urskyStars:setReferencePoint( display.CenterLeftReferencePoint )
			urskyStars.x = startingSkyX2; urskyStars.y = -1460
			
			mountain_big = display.newImage("mountain_big.png", 132-240, 92) 
			game:insert( mountain_big )
			mountain_sma = display.newImage("mountain_small.png", 84, 111)
			game:insert( mountain_sma )
			 
			tree_s = display.newImage("tree_s.png", 129-30, 151) 
			game:insert( tree_s )
			tree_l = display.newImage("tree_l.png", 145, 131) 
			game:insert( tree_l )

			local grass = display.newImage( "grass.png", true )
			game:insert( grass )
			grass.x = 160; grass.y = groundReferencePoint - 20
			physics.addBody( grass, "static", { friction=0.1, bounce=0.25, shape={ 480,60, -480,60, -480,-30, 480,-30 } } )
			grass.bodyName = "grass1"
		end
		
		local function AddSection()
			worldLength = worldLength + 1
			local addition = (worldLength* 960 )
			local newToys = true
			local dgrass
			if worldLength > 1 and math.random(5) < 3 then
				if math.random(5) < 4 then
					dgrass = display.newImage( "lava.png", true )
					dgrass.bodyName = "lava"..worldLength
					physics.addBody( dgrass, "static", { friction=0.7, bounce=0.2, shape={ 480,60, -480,60, -480,-30, 480,-30 } } )
				else
					newToys = false
					local quickSandTop = display.newImage( "quickSandTop.png", true )
					quickSandTop.x = addition; quickSandTop.y = groundReferencePoint - 70
					physics.addBody( quickSandTop, "static", { friction=0, bounce=0 } )
					quickSandTop.isSensor = true
					quickSandTop.bodyName = "quickSandTop"..worldLength
					game:insert( quickSandTop )
					quickSandTop:toBack()
					dgrass = display.newImage( "quickSand.png", true )
					dgrass.bodyName = "quickSand"..worldLength
					physics.addBody( dgrass, "static",
									  { friction=0.9, bounce=0, shape={ -360,60, -480,60, -480,-30, -360,0 }},
									  { friction=1.5, bounce=0, shape={ 360,60, -360,60, -360,0, 360,0 }},
									  { friction=0.9, bounce=0, shape={ 480,60, 360,60, 360,0, 480,-30 }}
									)
					quickSandTop.subSand = dgrass
				end
			else
				dgrass = display.newImage( "grass.png", true )
				dgrass.bodyName = "grass"..worldLength
				physics.addBody( dgrass, "static", { friction=0.1, bounce=0.25, shape={ 480,60, -480,60, -480,-30, 480,-30 } } )
			end
			dgrass.x = addition; dgrass.y = groundReferencePoint - 20
			game:insert( dgrass )
			dgrass:toBack()
			sky:toBack()
			sky2:toBack()
			if worldLength > 2 then					
				if newToys == true then
					toyX = addition + math.random( 10, 480 )
					if math.random(100) < 85 then
						if math.random(5) < 3 then
							local trampoline = display.newImage( "trampoline.png" )
							trampoline.x = toyX; trampoline.y = groundReferencePoint - 60
							trampoline.bodyName = "trampoline"..worldLength
							physics.addBody( trampoline, "static", { friction=0, bounce=5, shape={ 20,13, -20,11, -20,10, 20,6 } } )	
							game:insert( trampoline )	
							trampoline:toFront()
						else						
							local ramp = display.newImage( "ramp.png" )
							ramp.x = toyX; ramp.y = groundReferencePoint - 75
							ramp.bodyName = "ramp"..worldLength
							physics.addBody( ramp, "static", { friction=0, bounce=.2, shape={ 40,25, -40,25, 40,-31 } } )	
							game:insert( ramp )	
							ramp:toFront()	

						end
					else 
						if math.random(5) < 3 then
							local spikeWall = display.newImage( "spikewall.png" )
							spikeWall.x = toyX; spikeWall.y = groundReferencePoint - 90
							spikeWall.bodyName = "spikeWall"..worldLength
							physics.addBody( spikeWall, "static", { density=10, friction=1, bounce=0, shape={ -20,-43, 38,40, 22,40, -36,-43 } } )
							game:insert( spikeWall )
							spikeWall:toFront()	
						else
							local keg = display.newImage( "keg.png" )
							keg.x = toyX; keg.y = groundReferencePoint - 75
							keg.bodyName = "keg"..worldLength
							physics.addBody( keg, "static", { friction=1, bounce=0 } )
							game:insert( keg )
							keg:toFront()	
						end
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
				if math.random(100) < 15 then
					local bomb = display.newImage( "bomb.png" )
					bomb.x = addition + math.random( 40, 920 ); bomb.y = math.random( -500, 140 )
					bomb.bodyName = "bomb"
					physics.addBody( bomb, "static", { friction=0, bounce=0 } )
					bomb.isSensor = true
					game:insert( bomb )
					bomb:toFront()	
				end
				if math.random(100) < 50 then
					local jetRefill = display.newImage( "jetRefill.png" )
					jetRefill.x = addition + math.random( 40, 920 ); jetRefill.y = math.random( -500, 140 )
					jetRefill.bodyName = "jetRefill"
					physics.addBody( jetRefill, "static", { friction=0, bounce=0 } )
					jetRefill.isSensor = true
					game:insert( jetRefill )
					jetRefill:toFront()	
				end
				
				if math.random(100) < 10 then				
					local roosterPH = display.newImage( "rooster.png" )
					roosterPH.x = addition + math.random( 40, 920 ); roosterPH.y = groundReferencePoint - 100
					roosterPH.bodyName = "rooster"
					physics.addBody( roosterPH, "static", { friction=0, bounce=0} )
					roosterPH.isSensor = true
					game:insert( roosterPH )
					roosterPH:toFront()
				end
			end
		end
		
		createFirstSection()
		
		for i=1,2 do
			AddSection()
		end	
		
		mainCharacterShape = { 15,-22, 16,0, 14,20, 10,31, -10,32, -14,20, -19,-6, -14,-20 }

		if arguments ~= nil then
			print ("Number of Arguments = " .. #arguments)
			character = arguments[1]
			print("Character is: "..character)
			local sheet1
			if character == "noah" then
				sheet1 = sprite.newSpriteSheet( "noahSprite.png", 64, 64 )	
			elseif character == "baby" then
				sheet1 = sprite.newSpriteSheet( "babySprite.png", 44, 64 )
			elseif character == "dog" then
				--mainCharacterShape = { 8,-35, 35,-28, 30,10, 25,33, -35,33, -28,-8 }
				sheet1 = sprite.newSpriteSheet( "aryaSprite.png", 66, 68 )
			end
			local spriteSet1 = sprite.newSpriteSet(sheet1, 1, 4)
			sprite.add( spriteSet1, "mainCharacterSprite", 1, 4, 500, 0 ) -- play 8 frames every 1000 ms	
			mainCharacter = sprite.newSprite( spriteSet1 )
			
			if #arguments > 2 then
				launchType = arguments[3]
			end
		else
			local sheet1 = sprite.newSpriteSheet( "noahSprite.png", 64, 64 )
			local spriteSet1 = sprite.newSpriteSet(sheet1, 1, 4)
			sprite.add( spriteSet1, "mainCharacterSprite", 1, 4, 500, 0 ) -- play 8 frames every 1000 ms
			mainCharacter = sprite.newSprite( spriteSet1 )	
		end
		mainCharacter.x = 160; mainCharacter.y = groundReferencePoint - 250

		slingshotString = display.newImage( "string.png" )
		slingshotString.x = 150; slingshotString.y = groundReferencePoint - 230
		physics.addBody( slingshotString, "static", { friction=0.5 } )
		slingshotString.bodyName = "slingShotString"
		game:insert(slingshotString)
		
		--[[
		slingshot = display.newImage( "slingshot.png" )
		slingshot.x = 170; slingshot.y = groundReferencePoint - 220
		physics.addBody( slingshot, "static", { friction=0.5 } )
		slingshot.bodyName = "slingShot"
		game:insert(slingshot)
		--joint = physics.newJoint( "pivot", slingshot, slingshotString, 160, 120 )
		--]]
		------------------------------------------------------------
		-- Simple score display

		local scoreDisplay = ui.newLabel{
			bounds = { display.contentWidth - 140, 10 + display.screenOriginY, 100, 24 }, -- align label with right side of current screen
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


		lifeBar = tbaUI.newBar{
			bounds = { 0, 10 + display.screenOriginY, 5, 5 },
			lineColor = { 0, 255, 50, 255 },
			size = life,
			width = 5, 
			beautyBar = true
		}
		lifeBar.bodyName = "lifeBar"
		overlayDisplay:insert( lifeBar )
		lifeBar:setSize( life )	
		timer.performWithDelay( 4000, hideLifeLabel )
		
		------------------------------------------------------------
		-- boost display


		boostBar = tbaUI.newBar{
			bounds = { 400, 305 + display.screenOriginY, 5, 5 },
			lineColor = { 0, 255, 50, 255 },
			size = boost,
			width = 5, 
			beautyBar = true
		}
		boostBar.bodyName = "boostBar"
		overlayDisplay:insert( boostBar )
		boostBar:setSize( boost )

		local function showExplosion()		
			local explosionSheet = sprite.newSpriteSheet( "starExpSprite.png", 264, 264 )
			local explosionSpriteSet = sprite.newSpriteSet(explosionSheet, 1, 2)
			sprite.add( explosionSpriteSet, "explosionSprite", 1, 2, 2500, 1 )
			explosion = sprite.newSprite( explosionSpriteSet )
			game:insert( explosion )
			explosion.x = mainCharacter.x; explosion.y = mainCharacter.y
			if storyboard.playSounds then local explosionChannel = audio.play( explosionSound, { channel=2 }  ) end
			explosion:play()
		end

		local function showBlood()
			blood = display.newImage( "blood.png" )
			game:insert( blood )
			blood.x = mainCharacter.x + 10; blood.y = mainCharacter.y
		end
		
		local removeMainItems = function( event )	
			while game.numChildren > 0	do
				for i=1, game.numChildren do
					if game[i] ~= nil then
						game:remove( i )
					end
				end
			end
			while overlayDisplay.numChildren > 0	do
				for i=1, overlayDisplay.numChildren do
					if overlayDisplay[i] ~= nil then
						overlayDisplay:remove( i )
					end
				end
			end
		end
		
		local goToMenu = function ( event )
			if menuButton ~= nil then
				menuButton.isVisible = false
				menuButton = nil
			end
			if restartButton ~= nil then
				restartButton.isVisible = false
				restartButton = nil
			end
			Runtime:removeEventListener( "key", onKeyEvent )	
			Runtime:removeEventListener( "enterFrame", frameCheck )
			Runtime:removeEventListener( "enterFrame", removeLifeLava )
			Runtime:removeEventListener( "collision", onGlobalCollision )
			Runtime:removeEventListener( "enterFrame", timeCheck )
			Runtime:removeEventListener( "enterFrame", showAngle )
			Runtime:removeEventListener( "enterFrame", objectToFront )
			if timeBar ~= nil then
				timeBar:setSize( 0 )
				timeBar.isVisible = false
				timeBar = nil
			end
			if timeLabel ~= nil then
				timeLabel.isVisible = false
				timeLabel = nil
			end
			if lifeLabel ~= nil then
				lifeLabel.isVisible = false
				lifeLabel = nil
			end
			if lifeBar ~= nil then
				lifeBar:setSize( 0 )
				lifeBar.isVisible = false
				lifeBar = nil
			end
			if boostBar ~= nil then
				boostBar:setSize( 0 )
				boostBar.isVisible = false
				boostBar = nil
			end
			if mainCharacter ~= nil then
				mainCharacter.isVisible = false
				mainCharacter = nil
			end
			removeMainItems()	
			storyboard.gotoScene("mainMenu")
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
			Runtime:removeEventListener( "enterFrame", removeLifeLava )
			
			jetpackButton.isVisible = false	
			jetpackButton:removeSelf();
			endJets()
			Runtime:removeEventListener( "enterFrame", applyJetpackBoost )
									
			menuButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				over = "buttonRedOver.png",
				onPress = goToMenu,
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
				
				removeMainItems()
				menuButton.isVisible = false
				restartButton.isVisible = false
				--director:changeScene("testChange", "crossFade", arguments)
				start()
			end
			
			if #totalScore == 4 then
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
			if timeMode and timeLeft <= 0 then
				local aggregatedScore = 0
				table.sort( totalScore, function(a,b) return a>b end )  --Sort the top 4 scores in descending order
				
				local usersList = {}
				for row in db:nrows("SELECT ixUser, sName FROM tblUsers") do
					print("adding user "..row.ixUser.." - "..row.sName)		
					usersList[row.ixUser] = row
				end
				
				local list = widget.newTableView{
					left = 96,
					top = 100 + display.screenOriginY,
					topPadding = 20,
					bottomPadding = 20,
					width = 288,
					height = 192,
					maskFile = "endScoreBackground.png",
					bgColor = { 0, 0, 0, 255 }
				}
				
				for i=1, #totalScore do
					aggregatedScore = aggregatedScore + totalScore[i]
					print("Score " .. i .. " = " .. totalScore[i])
				end				
				local function onRowRender( event )
					local row = event.target
						local text = display.newRetinaText( "Total. "..string.format( "%i",aggregatedScore), 0, 0, native.systemFontBold, 20 )
						text:setReferencePoint( display.CenterLeftReferencePoint )
						text.x = 25
						text.y = row.height * 0.5
						--text.y = curHeight + (row.height * 0.5)
						--curHeight = curHeight + row.height
						event.view:insert( text )
					end
					list:insertRow{
						id = "index Header",
						isCategory = isCategory,
						height = 30,
						rowColor = { 0, 0, 0, 255 },
						onRender = onRowRender
					}				
				for i=1, #totalScore do					
					local function onRowRender( event )
					local row = event.target
						local text = display.newRetinaText( i..". "..string.format( "%i",totalScore[i]), 0, 0, native.systemFontBold, 20 )
						text:setReferencePoint( display.CenterLeftReferencePoint )
						text.x = 25
						text.y = row.height * 0.5
						--text.y = curHeight + (row.height * 0.5)
						--curHeight = curHeight + row.height
						event.view:insert( text )
					end
				score = 0
					list:insertRow{
						id = "index "..i,
						height = 30,
						rowColor = { 0, 0, 0, 255 },
						onRender = onRowRender
					}
				end		
				
				overlayDisplay:insert(list)			
					

				--Setup the high score table if it doesn't exist
				local tablesetup = [[CREATE TABLE IF NOT EXISTS tblHighScores (ixHighScore INTEGER PRIMARY KEY, ixUser, dScore, dtCreated);]]
				db:exec( tablesetup )

				--Add rows with a auto index in 'id'. You don't need to specify a set of values because we're populating all of them
				local tablefill =[[INSERT INTO tblHighScores VALUES (NULL, ]]..storyboard.userIndex..[[, ]]..aggregatedScore..[[,']]..os.date("%x")..[[');]]
				print (tablefill)
				db:exec( tablefill )
				
				--Insert in to OpenFeint high score
				gameNetwork.request( "setHighScore", { leaderboardID=highScoreLeaderboard, score=aggregatedScore, displayText=string.format( "%i", aggregatedScore) } )
				if aggregatedScore > 49999 then gameNetwork.request( "unlockAchievement", "1395962" ) end
				if aggregatedScore > 999999 then gameNetwork.request( "unlockAchievement", "1395982" ) end
			else
				restartButton = ui.newButton{
					defaultSrc = "buttonRed.png",
					over = "buttonRedOver.png",
					onPress = restartButtonPress,
					text = "Relaunch",
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
		function frameCheck( event )
			
			if not shootingForTheStarsAchieved and mainCharacter.y < -900 then
				gameNetwork.request( "unlockAchievement", "1395992" )
				shootingForTheStarsAchieved = true
			end
			
			local tNotMovingDelta = (event.time - tNotMovingPrevious)
			local tDelta = (event.time - tPrevious)
			local tAddShown = (event.time - tAdShownPrevious)
			if mainCharacter.x > 0 and mainCharacter.x > ( worldLength - 2 ) * 960 then
				AddSection()
				mainCharacter:toFront();
			end
			
			if mainCharacter.x > score then
				score = mainCharacter.x / 2
				scoreDisplay:setText( string.format( "%i", score ) )
				if not twentyThousandLeagueAchieved and score > 19999 then
					gameNetwork.request( "unlockAchievement", "1395952" )
					twentyThousandLeagueAchieved = true
				end
			end
			if (mainCharacter.x > -800) then
				game.x = math.ceil(-mainCharacter.x) + 120
			end
			if (mainCharacter.x < -100 or mainCharacter.y < 235) then
				game.y = -mainCharacter.y - math.fmod(-mainCharacter.y, 2) + 235
			end
			if mainCharacter ~= nil then
				vx, vy = mainCharacter:getLinearVelocity()
				if vx < 35 and vy < 5 and tNotMovingDelta > 100 then
					tNotMovingPrevious = event.time
					life = life - 5
					lifeBar:setSize( life )
				end
			end
			
			if (mainCharacter.x > 0) then
				if ( game.x + sky.x ) > sky.contentWidth - 40 then
					sky:translate( -(sky.contentWidth * 2), 0)
				end
				if ( game.x + sky2.x ) > sky.contentWidth - 40 then
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
				
				-------
				if mainCharacter.y < -1100 then
					if ( game.y + llskyStars.y ) > llskyStars.contentHeight then
						llskyStars:translate(0,  -(llskyStars.contentHeight * 2))
					end
					if ( game.y + lrskyStars.y ) > lrskyStars.contentHeight then
						lrskyStars:translate(0,  -(lrskyStars.contentHeight * 2))
					end
					
					if ( game.y + llskyStars.y + llskyStars.contentHeight) < 120 then
						llskyStars:translate(0,  llskyStars.contentHeight * 2)
					end
					if ( game.y + lrskyStars.y + lrskyStars.contentHeight) < 120 then
						lrskyStars:translate(0,  lrskyStars.contentHeight * 2)
					end
					
					if ( game.y + ulskyStars.y ) > ulskyStars.contentHeight then
						ulskyStars:translate(0,  -(ulskyStars.contentHeight * 2))
					end
					if ( game.y + urskyStars.y ) > urskyStars.contentHeight then
						urskyStars:translate(0,  -(urskyStars.contentHeight * 2))
					end
					
					if ( game.y + ulskyStars.y + ulskyStars.contentHeight) < 120 then
						ulskyStars:translate(0,  ulskyStars.contentHeight * 2)
					end
					if ( game.y + urskyStars.y + urskyStars.contentHeight) < 120 then
						urskyStars:translate(0,  urskyStars.contentHeight * 2)
					end
				end
				
				local llskyStarsTotal = game.x + llskyStars.x + llskyStars.contentWidth
				local lrskyStarsTotal = game.x + lrskyStars.x + lrskyStars.contentWidth
						
				if ( llskyStarsTotal < 0 or llskyStarsTotal > llskyStars.contentWidth * 2 or lrskyStarsTotal < 0 or lrskyStarsTotal > lrskyStars.contentWidth * 2 ) and game.y > 1000 then
					llskyStars.x = sky.x
					lrskyStars.x = sky2.x
				end	
				
				local ulskyStarsTotal = game.x + ulskyStars.x + ulskyStars.contentWidth
				local urSkyStarsTotal = game.x + urskyStars.x + urskyStars.contentWidth
						
				if ( ulskyStarsTotal < 0 or ulskyStarsTotal > ulskyStars.contentWidth * 2 or urSkyStarsTotal < 0 or urSkyStarsTotal > urskyStars.contentWidth * 2 ) and game.y > 1400 then
					ulskyStars.x = sky.x
					urskyStars.x = sky2.x
				end	
				
				-------
				
				if game.y < 320 then
					mountain_big.x = mountain_big.x + ( ( vx / 320 ) * 8 )
					if mountain_big.x < mainCharacter.x - 280 then
						mountain_big.x = mainCharacter.x + 500
					end	
					
					mountain_sma.x = mountain_sma.x + ( ( vx / 320 ) * 7 )
					if mountain_sma.x < mainCharacter.x - 280 then
						mountain_sma.x = mainCharacter.x + 500
					end						
					
					tree_s.x = tree_s.x + ( ( vx / 320 ) * 5 )
					if tree_s.x < mainCharacter.x - 280 then
						tree_s.x = mainCharacter.x + 500
					end							
									
					tree_l.x = tree_l.x + ( ( vx / 320 ) * 4 )
					if tree_l.x < mainCharacter.x - 280 then
						tree_l.x = mainCharacter.x + 500
					end					
				end
			end
			
			if life <= 0 then	
				Runtime:removeEventListener( "enterFrame", frameCheck )
				Runtime:removeEventListener( "enterFrame", removeLifeLava )
				Runtime:removeEventListener( "collision", onGlobalCollision )
				showDeath( "explosion" )
			end
		end
		
		function onBackEvent( event )
			local phase = event.phase
			local keyName = event.keyName
			
			if (keyName == "back" and phase == "up") then 				
				goToMenu( event )
			end
			return true
		end	

		local backButton = ui.newButton{
			defaultSrc = "btn_back.png",
			overSrc = "btn_back.png",
			onRelease = goToMenu,
			emboss = true,
			x = 470,
			y = 30
		}
		backButton.isVisible = true
		overlayDisplay:insert(backButton)
		
		local jetpackSoundChannel
		local tJetpack = system.getTimer()
		function applyJetpackBoost:enterFrame( event )			
			flame.x = mainCharacter.x - 20
			flame.y = mainCharacter.y + 40
			flame:toFront()
			local tDelta = (event.time - tJetpack)
			if boost > 0 then		
				if tDelta > 150 and mainCharacter ~= nil then	
					flame.isVisible = true
					jetpackButtonOver.isVisible = true
					tJetpack = event.time
					if boost < 10 then
						boost = 0
					else
						boost = boost - 10
					end
					boostBar:setSize( boost )
					mainCharacter:applyLinearImpulse( 10, -30, mainCharacter.x - 1, mainCharacter.y )
				end
			else
				flame.isVisible = false
				jetpackButtonOver.isVisible = false
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
			if storyboard.playSounds then jetChannel = audio.play( jetSound,{ channel=4 }) end
			Runtime:addEventListener( "enterFrame", applyJetpackBoost )
		end
		
		function endJets()
			--audio.stop( jetChannel )
			flame.isVisible = false
			jetpackButtonOver.isVisible = false
			Runtime:removeEventListener( "enterFrame", applyJetpackBoost )
		end
		
		jetpackButton = display.newImage( "jetPack.png" )
		overlayDisplay:insert(jetpackButton)
		jetpackButton.x = 445; jetpackButton.y = 255
		jetpackButtonOver = display.newImage( "jetPackOver.png" )
		overlayDisplay:insert(jetpackButtonOver)
		jetpackButtonOver.x = 445; jetpackButtonOver.y = 255
		jetpackButtonOver.isVisible = false
		
		local tLava = system.getTimer()
		function removeLifeLava( event ) 
			if lifeBar == nil then 
				runtime:removeEventListener( "enterFrame", removeLifeLava )
			else
				local tDelta = (event.time - tLava)
				if tDelta > 25 then	
					tLavaPrevious = event.time
					life = life - 1
					lifeBar:setSize( life )
					if storyboard.playSounds then local owChannel = audio.play( owSound, { channel=4 }  ) end
				end
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
					if event.x>1 then
						t.x = event.x - t.x0
					else
						t.x = 1
					end					
					if event.y< 245 then
						t.y = event.y - t.y0
					else
						t.y = 245
					end
				elseif "ended" == phase or "cancelled" == phase then
					jetpackButton.isVisible = false
					jetpackButton = nil
					jetpackButton = ui.newButton{
						defaultSrc = "jetPack.png",
						x = 445,
						y = 255,
						overSrc = "jetPackOver.png",
						onPress = startJets,
						onRelease = endJets
					}
					jetpackButton.bodyName = "Jet Pack Button"
					overlayDisplay:insert(jetpackButton)
					display.getCurrentStage():setFocus( nil )
					t.isFocus = false
					if storyboard.playSounds then local swooshChannel = audio.play( swooshSound, { channel=2 }  ) end
					t:prepare("mainCharacterSprite")
					t:play()
					--if character == "dog" then
					--	physics.addBody( t, { density=2.2, friction=0.1, bounce=0, shape=mainCharacterShape } )
					--else
						physics.addBody( t, { density=5.0, friction=0.1, bounce=0, shape=mainCharacterShape } )
					--end
					game:insert(t)
					t.bodyName = "mainCharacterDynamic"
					t.isFixedRotation = true
					--t.angularDamping = 10
					t:removeEventListener( "touch", onTouch )
					slingshotString:removeSelf()
					t:applyLinearImpulse( 2 * (170 - t.x) , 1.6 * (groundReferencePoint - 200 - t.y), t.x + 9, t.y)
					Runtime:addEventListener( "enterFrame", frameCheck )
				end
			end

			-- Important to return true. This tells the system that the event
			-- should not be propagated to listeners of any objects underneath.
			return true
		end
		local function launchCharacter()
			Runtime:removeEventListener ( "enterFrame", showAngle )
			if mainCharacter ~= nil then
				jetpackButton.isVisible = false
				jetpackButton = nil
				jetpackButton = ui.newButton{
					defaultSrc = "jetPack.png",
					x = 445,
					y = 255,
					overSrc = "jetPackOver.png",
					onPress = startJets,
					onRelease = endJets
				}
				jetpackButton.bodyName = "Jet Pack Button"
				overlayDisplay:insert(jetpackButton)
				angle = (storyboard.launchAngle - 7.5) * 50
				power = storyboard.launchPower
				display.getCurrentStage():setFocus( nil )
				local t = mainCharacter
				if storyboard.playSounds then local swooshChannel = audio.play( swooshSound, { channel=2 }  ) end
				t:prepare("mainCharacterSprite")
				t:play()
				if character == "dog" then
					physics.addBody( t, { density=2.2, friction=0.1, bounce=0, shape=mainCharacterShape } )
				else
					physics.addBody( t, { density=5.0, friction=0.1, bounce=0, shape=mainCharacterShape } )
				end
				game:insert(t)
				t.bodyName = "mainCharacterDynamic"
				t.isFixedRotation = true
				--t.angularDamping = 10
				t:removeEventListener( "touch", onTouch )
				--Angle of 0 = all y Force. Angle of 100 = all x Force.
				print ( "Angle = "..angle.." and Power = "..power )
				local xForce = power
				local yForce = power / 100  * angle
				print ( "xForce = "..xForce.." and yForce = "..yForce )
				
				local launchBoard = display.newImage( "launchBoard.png" )
				launchBoard.y = 200
				local xInterval = ( t.x - 170 ) / 100
				for i=1,100 do
					launchBoard.x = 170 + xInterval
				end	
				launchBoard.isVisible = false
				launchBoard:removeSelf()				
				slingshotString:removeSelf()
				t:applyLinearImpulse( xForce * 3.5 , -yForce * 3 , t.x + 9, t.y)
				Runtime:addEventListener( "enterFrame", frameCheck )
			end
		end

		
		local function setAngle()
			Runtime:removeEventListener ( "touch", setAngle )
			print("angle set" )
			storyboard.launched = true
			launchCharacter()
		end
		
		local function launchDefaultAngle()
			Runtime:removeEventListener ( "touch", setAngle )
			if not storyboard.launched then	
				launchCharacter()
			end
		end
		
		local direction = 1
		showAngle = function()
			angle = storyboard.launchAngle
			if direction == 1 then
				if angle >= 9.5 then
					direction = 0
				else
					storyboard.launchAngle = angle + .1
				end
			else
				if angle <= 7.5 then
					direction = 1
				else
					storyboard.launchAngle = angle - .1
				end
			end
			mainCharacter.x = 190 + 50 * math.sin( angle );
			mainCharacter.y = 75 + 50 * math.cos( angle );
			--[[
			slingshotString:removeSelf()
			slingshotString = nil
			slingshotString = display.newLine( mainCharacter.x, mainCharacter.y, slingshot.x, slingshot.y ) 
			slingshotString.width = 4
			game:insert( slingshotString ) 
			--]]
		end
	
		if launchType == "hardLaunch" then
			storyboard.launched = false
			local power = storyboard.launchPower
			Runtime:addEventListener ( "touch", setAngle )
			timer.performWithDelay(5000, launchDefaultAngle )
			storyboard.launchAngle = 7.5
			Runtime:addEventListener ( "enterFrame", showAngle )
		else
			mainCharacter:addEventListener( "touch", onTouch )
		end
		
		----------------------------------------------------------
		-- Two collision types (run Corona Terminal to see output)
		----------------------------------------------------------


		-- METHOD 1: Use table listeners to make a single object report collisions between "self" and "other"
		local function objectToFront( curToFrontObject )			
			storyboard.curToFrontObject:toFront()
		end
		local function onLocalCollision( self, event )
			if ( event.phase == "began" ) then
				--print( self.bodyName .. ": collision began with " .. event.other.bodyName )
				local bodyName = event.other.bodyName
				if bodyName ~= nil then
					if string.find(bodyName, "lava") ~= nil then
						life = life - 1
						lifeBar:setSize( life )
						print("adding lava removal listener")
						Runtime:addEventListener( "enterFrame", removeLifeLava )
					elseif string.find(bodyName, "quickSandTop") ~= nil then
						print("sending quicksand to front")
						storyboard.curToFrontObject = event.other.subSand
						Runtime:addEventListener( "enterFrame", objectToFront )
					elseif bodyName == "star" then
						mainCharacter:applyLinearImpulse( 0, -150, mainCharacter.x + 9, mainCharacter.y )
					elseif bodyName == "bacon" then
						if life > 74 then
							life = 100
						else
							life = life + 25
						end			
						lifeBar:setSize( life )
						mainCharacter:applyLinearImpulse( -10, -75, mainCharacter.x + 9, mainCharacter.y )
					elseif bodyName == "bomb" then
						if life < 10 then
							life = 0
						else
							life = life - 10
						end
						lifeBar:setSize( life )
						mainCharacter:applyLinearImpulse( -100, 20, mainCharacter.x, mainCharacter.y )
					elseif bodyName == "jetRefill" then
						if boost > 74 then
							boost = 100
						else
							boost = boost + 25
						end
						boostBar:setSize( boost )
					elseif string.find(bodyName, "rooster") ~= nil then
						if storyboard.playSounds then impactChannel = audio.play( owSound, { channel=3 }  ) end
						transition.to(mainCharacter, {x = event.other.x  - 40, y= event.other.y + 30, time=0})
						event.other.isVisible = false
						rooster.x = event.other.x; rooster.y = event.other.y
						--game.y = rooster.y - 240	TODO: I still want the camera to move, but it's causing crashes.  WHYYYYY!!!!!!
						rooster.isVisible = true	
						rooster:toFront()
						rooster:prepare()		
						rooster:play()
						Runtime:removeEventListener( "enterFrame", frameCheck )
						Runtime:removeEventListener( "enterFrame", removeLifeLava )
						Runtime:removeEventListener( "collision", onGlobalCollision )
						showDeath ( "bloody" )
					elseif string.find( bodyName, "spikeWall" ) ~= nil then
						Runtime:removeEventListener( "enterFrame", frameCheck )
						Runtime:removeEventListener( "enterFrame", removeLifeLava )
						Runtime:removeEventListener( "collision", onGlobalCollision )
						showDeath ( "bloody" )					
					end
				end
				elseif ( event.phase == "ended" ) then
					--print( self.bodyName .. ": collision ended with " .. event.other.bodyName )
					if bodyName ~= nil and (string.find(bodyName, "lava") ~= nil or string.find(self.bodyName, "lava") ~= nil) then				
						Runtime:removeEventListener( "enterFrame", removeLifeLava )
					elseif event.other.bodyName ~= nil and string.find(event.other.bodyName, "quickSandTop") ~= nil then
						print("removing quicksand to front")
						Runtime:removeEventListener( "enterFrame", objectToFront )
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
				if bodyName ~= nil then
					if string.find(bodyName, "lava") ~= nil or string.find(bodyName, "grass") ~= nil then
						if storyboard.playSounds then impactChannel = audio.play( boingSound, { channel=3 }  ) end
					elseif string.find(bodyName, "ramp") ~= nil then
						if storyboard.playSounds then impactChannel = audio.play( swooshSound, { channel=3 }  ) end
					elseif string.find(bodyName, "trampoline") ~= nil then
						if storyboard.playSounds then impactChannel = audio.play( bounceSound, { channel=3 }  ) end
					elseif string.find(bodyName, "keg") ~= nil then
						if storyboard.playSounds then impactChannel = audio.play( owSound, { channel=3 }  ) end
					elseif string.find(bodyName, "spikeWall") ~= nil then
						if storyboard.playSounds then impactChannel = audio.play( owSound, { channel=3 }  ) end
					end
				end
			end--]]
		end

		-- Here we assign the above two functions to local listeners within mainCharacter only, using table listeners:

		mainCharacter.postCollision = onLocalPostCollision
		mainCharacter:addEventListener( "postCollision", mainCharacter )
		return game
	end	
	start()
end

function scene:enterScene( event )
	print( "entering superLaunch" )
	local group = self.view
	timer.performWithDelay( 10, addKeyEvent )
	ads.hide();
end

function scene:exitScene( event )
	local group = self.view	
	Runtime:removeEventListener( "enterFrame", timeCheck )	
			if timeBar ~= nil then
				timeBar.setSize(0)
				timeBar.isVisible = false
				timeBar = nil
			end
	Runtime:removeEventListener( "key", onBackEvent )
end

function scene:destroyScene( event )
	local group = self.view	
			if timeBar ~= nil then
				timeBar.setSize(0)
				timeBar.isVisible = false
				timeBar = nil
			end
end

scene:addEventListener( "createScene", scene )
scene:addEventListener( "enterScene", scene )
scene:addEventListener( "exitScene", scene )
scene:addEventListener( "destroyScene", scene )

return scene