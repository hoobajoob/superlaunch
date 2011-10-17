module(..., package.seeall)
function new()
	local self = display.newGroup()
		
	 	
	-- Back Key listener
	local function onKeyEvent( event )
		local phase = event.phase
		local keyName = event.keyName
		
		-- Show alert with five buttons
		if (phase == "up" and keyName == "back") then 
			local alert = native.showAlert( "Corona", "Are you sure you want to exit?", 
										{ "YES", "NO" }, onQuitComplete )
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
	
	local classicButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent );
		local backgroundMusic = audio.loadStream("backgroundMusic.mp3")
		--local backgroundMusicChannel = audio.play( backgroundMusic, { channel=1, loops=-1, fadein=5000 }  )  -- play the background music on channel 1, loop infinitely, and fadein over 5 seconds 
		director:changeScene("characterSelect", "moveFromRight", {"superlaunch"})
	end
	
	local levelButtonPress = function( event )
		--[[
		Runtime:removeEventListener( "key", onKeyEvent );
		local backgroundMusic = audio.loadStream("backgroundMusic.mp3")
		--local backgroundMusicChannel = audio.play( backgroundMusic, { channel=1, loops=-1, fadein=5000 }  )  -- play the background music on channel 1, loop infinitely, and fadein over 5 seconds 
		director:changeScene("characterSelect", "moveFromRight", {"levelMenu"})
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
				text = "LevelPlay",
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
				text = "High Scores",
				emboss = true,
				x = 240,
				y = 255
			}
	highScoresButton.isVisible = true
	self:insert(highScoresButton)
	
	function moveBack(where, how, arguments)
		director:changeScene( where, how, arguments)
	end

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