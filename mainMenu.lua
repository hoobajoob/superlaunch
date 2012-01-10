module(..., package.seeall)
local ui = require("ui")
local storyboard = require( "storyboard" )
local scene = storyboard.newScene()

-----------------------------------------------------------------------------------------
-- BEGINNING OF YOUR IMPLEMENTATION
-- 
-- NOTE: Code outside of listener functions (below) will only be executed once,
--		 unless storyboard.removeScene() is called.
-- 
-----------------------------------------------------------------------------------------

-- Called when the scene's view does not exist:
function scene:createScene( event )
	local group = self.view
	
	local bg = display.newImage( "background.png", true )
	group:insert( bg )

	-- Handler that gets notified when the alert closes
	local function onQuitComplete( event )
			if "clicked" == event.action then
					local i = event.index
					if 1 == i then							
						native.requestExit()
					elseif 2 == i then
						-- Do nothing; dialog will simply dismiss
					end
			end
	end
		
	-- Back Key listener
	local function onKeyEvent( event )
		local phase = event.phase
		local keyName = event.keyName
		
		-- Show alert with five buttons
		if (keyName == "back") then 
			local alert = native.showAlert( "SuperLaunch", "Are you sure you want to exit?", 
										{ "YES", "NO" }, onQuitComplete )
		else			
			local alert = native.showAlert( "SuperLaunch", "You pressed the "..keyName.." button.", 
										{ "YES", "NO" } )
		end
		return true
	end
	
	--Open GameData.sqlite.  If the file doesn't exist it will be created
	local path = system.pathForFile("GameData.sqlite", system.DocumentsDirectory)
	db = sqlite3.open( path )   
	 
	--Handle the applicationExit event to close the db
	function onSystemEvent( event )
		if( event.type == "applicationExit" ) then              
			db:close()
		end
	end
	 
	--setup the system listener to catch applicationExit
	Runtime:addEventListener( "system", onSystemEvent )	
	
	--Setup the user table if it doesn't exist
	local tablesetup = [[CREATE TABLE IF NOT EXISTS tblUsers (ixUser INTEGER PRIMARY KEY, sName);]]
	db:exec( tablesetup )
	
	local classicButtonPress = function( event )			
		Runtime:removeEventListener( "key", onKeyEvent )
		local backgroundMusic = audio.loadStream("backgroundMusic.mp3")
		--local backgroundMusicChannel = audio.play( backgroundMusic, { channel=1, loops=-1, fadein=5000 }  )  -- play the background music on channel 1, loop infinitely, and fadein over 5 seconds 
		storyboard.gotoScene("timedModeMain")
	end
	
	local loginButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )
		storyboard.gotoScene("localLogin")
	end
	
	local levelButtonPress = function( event )		
		Runtime:removeEventListener( "key", onKeyEvent )
		local backgroundMusic = audio.loadStream("backgroundMusic.mp3")
		--local backgroundMusicChannel = audio.play( backgroundMusic, { channel=1, loops=-1, fadein=5000 }  )  -- play the background music on channel 1, loop infinitely, and fadein over 5 seconds 
		storyboard.gotoScene("levelModeMain")		
	end
	
	local highScoresButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )
		storyboard.gotoScene("highScores")
	end
	
	local helpButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )
		storyboard.gotoScene("help")
	end
	
	local classicButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				onEvent = classicButtonPress,
				overSrc = "buttonRedOver.png",
				text = "Classic Play",
				emboss = true,
				x = 240,
				y = 34
			}
	classicButton.isVisible = true
	
	local loginButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				x = 240,
				y = 98,
				overSrc = "buttonRedOver.png",
				onEvent = loginButtonPress,
				text = "Login",
				emboss = true
			}
	loginButton.isVisible = true	
	
	local levelButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				x = 240,
				y = 162,
				overSrc = "buttonRedOver.png",
				onEvent = levelButtonPress,
				text = "Level Play",
				emboss = true
			}
	levelButton.isVisible = true
	
	local highScoresButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				x = 240,
				y = 226,
				overSrc = "buttonRedOver.png",
				onEvent = highScoresButtonPress,
				text = "High Scores and Achievements",
				emboss = true
			}
	highScoresButton.isVisible = true
	
	local helpButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				x = 240,
				y = 286,
				overSrc = "buttonRedOver.png",
				onEvent = helpButtonPress,
				text = "Help",
				emboss = true
			}
	helpButton.isVisible = true

	function moveBack(where, how, arguments)
		storyboard.arguments = arguments
		storyboard.gotoScene(where, how)
	end
	
	-- Add the back key callback
	Runtime:addEventListener( "key", onKeyEvent );
	
	-- all display objects must be inserted into group
	group:insert(classicButton)
	group:insert(loginButton)
	group:insert(levelButton)
	group:insert(highScoresButton)
	group:insert(helpButton)
end

-- Called immediately after scene has moved onscreen:
function scene:enterScene( event )
	local group = self.view
	storyboard.removeScene( "superLaunch" )
	
	-- INSERT code here (e.g. start timers, load audio, start listeners, etc.)
	
end

-- Called when scene is about to move offscreen:
function scene:exitScene( event )
	local group = self.view
	
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