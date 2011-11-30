module(..., package.seeall)
function new()
	local self = display.newGroup()
	
	local bg = display.newImage( "background.png", true )
	self:insert( bg )

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
	
	function onVolumeEvent( event )
		if (event.phase == "up") then
			if event.keyName == "volumeUp" then
			
			elseif event.keyName == "volumeDown" then
			
			end
		end
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
			
		Runtime:removeEventListener( "key", onKeyEvent );
		local backgroundMusic = audio.loadStream("backgroundMusic.mp3")
		--local backgroundMusicChannel = audio.play( backgroundMusic, { channel=1, loops=-1, fadein=5000 }  )  -- play the background music on channel 1, loop infinitely, and fadein over 5 seconds 
		director:changeScene("timedModeMain", "moveFromRight")
	end
	
	local levelButtonPress = function( event )
		---[[
		Runtime:removeEventListener( "key", onKeyEvent );
		local backgroundMusic = audio.loadStream("backgroundMusic.mp3")
		--local backgroundMusicChannel = audio.play( backgroundMusic, { channel=1, loops=-1, fadein=5000 }  )  -- play the background music on channel 1, loop infinitely, and fadein over 5 seconds 
		director:changeScene("levelModeMain", "moveFromRight")
		--]]
	end
	
	local highScoresButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent );
		director:changeScene("highScores", "moveFromTop")
	end
	
	local classicButton = ui.newButton{
				default = "buttonRed.png",
				over = "buttonRedOver.png",
				onPress = classicButtonPress,
				text = "Classic Play",
				emboss = true,
				x = 240,
				y = 55
			}
	classicButton.isVisible = true	
	self:insert(classicButton)
	
	local levelButton = ui.newButton{
				default = "buttonRed.png",
				over = "buttonRedOver.png",
				onPress = levelButtonPress,
				text = "Level Play",
				emboss = true,
				x = 240,
				y = 155
			}
	levelButton.isVisible = true
	self:insert(levelButton)
	
	local highScoresButton = ui.newButton{
				default = "buttonRed.png",
				over = "buttonRedOver.png",
				onPress = highScoresButtonPress,
				text = "High Scores and Achievements",
				emboss = true,
				x = 240,
				y = 255
			}
	highScoresButton.isVisible = true
	self:insert(highScoresButton)
	
	function moveBack(where, how, arguments)
		director:changeScene( where, how, arguments)
	end
	
	-- Add the back key callback
	Runtime:addEventListener( "key", onKeyEvent );
	
	local onSystem = function( event )
		if event.type == "applicationSuspend" then
			if gameIsActive then
					gameIsActive = false
					physics.pause()
			end

		elseif event.type == "applicationExit" then
			if system.getInfo( "environment" ) == "device" then
					native.requestExit()
			end
		end
	end
	
	function clean()
	end
	
	return self
end