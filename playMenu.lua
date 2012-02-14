module(..., package.seeall)
local ui = require("ui")
local storyboard = require( "storyboard" )
local scene = storyboard.newScene()
-- Back Key listener
local function onBackEvent( event )
	local phase = event.phase
	local keyName = event.keyName
	
	if (keyName == "back" and phase == "up") then 
		storyboard.gotoScene("mainMenu")
	end
	return true
end	

local function addKeyEvent()
	print( "adding Key Listener" )
	Runtime:addEventListener( "key", onBackEvent )
end

-- Called when the scene's view does not exist:
function scene:createScene( event )
	print("creating playMenu")
	local group = self.view
	
	local bg = display.newImage( "background.png", true )
	group:insert( bg )
	
	local classicButtonPress = function( event )
		local backgroundMusic = audio.loadStream("backgroundMusic.mp3")
		--local backgroundMusicChannel = audio.play( backgroundMusic, { channel=1, loops=-1, fadein=5000 }  )  -- play the background music on channel 1, loop infinitely, and fadein over 5 seconds 
		storyboard.arguments = "superLaunch"
		storyboard.gotoScene("timedModeMain")
	end
	
	local levelButtonPress = function( event )
		local backgroundMusic = audio.loadStream("backgroundMusic.mp3")
		--local backgroundMusicChannel = audio.play( backgroundMusic, { channel=1, loops=-1, fadein=5000 }  )  -- play the background music on channel 1, loop infinitely, and fadein over 5 seconds 
		storyboard.arguments = "levelMenu"
		storyboard.gotoScene("timedModeMain")		
	end
	
	local backButtonPress = function( event )
		storyboard.gotoScene("mainMenu")
	end
	
	local backButton = ui.newButton{
		defaultSrc = "btn_back.png",
		overSrc = "btn_back.png",
		onRelease = backButtonPress,
		emboss = true,
		x = 450,
		y = 80
	}
	backButton.isVisible = true
	
	local classicButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				onRelease = classicButtonPress,
				overSrc = "buttonRedOver.png",
				text = "Classic Play",
				emboss = true,
				x = 240,
				y = 120
			}
	classicButton.isVisible = true	
	
	local levelButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				x = 240,
				y = 240,
				overSrc = "buttonRedOver.png",
				onRelease = levelButtonPress,
				text = "Level Play",
				emboss = true
			}
	levelButton.isVisible = true
	
	-- all display objects must be inserted into group
	group:insert(classicButton)
	group:insert(levelButton)
	group:insert( backButton )
end

-- Called immediately after scene has moved onscreen:
function scene:enterScene( event )
	print("entering playMenu")
	-- INSERT code here (e.g. start timers, load audio, start listeners, etc.)
	local group = self.view
	timer.performWithDelay( 10, addKeyEvent )
	-- Add the back key callback
end

-- Called when scene is about to move offscreen:
function scene:exitScene( event )
	local group = self.view
	Runtime:removeEventListener( "key", onBackEvent )
	
	-- INSERT code here (e.g. stop timers, remove listenets, unload sounds, etc.)
	
end

-- If scene's view is removed, scene:destroyScene() will be called just prior to:
function scene:destroyScene( event )
	local group = self.view
end

-----------------------------------------------------------------------------------------
-- END OF YOUR IMPLEMENTATION
-----------------------------------------------------------------------------------------

-- "createScene" event is dispatched if scene's view does not exist
scene:addEventListener( "createScene", scene )

-- "enterScene" event is dispatched whenever scene transition has finished
scene:addEventListener( "enterScene", scene )

-- "exitScene" event is dispatched whenever before next scene's transition begins
scene:addEventListener( "exitScene", scene )

-- "destroyScene" event is dispatched before view is unloaded, which can be
-- automatically unloaded in low memory situations, or explicitly via a call to
-- storyboard.purgeScene() or storyboard.removeScene().
scene:addEventListener( "destroyScene", scene )

-----------------------------------------------------------------------------------------

return scene