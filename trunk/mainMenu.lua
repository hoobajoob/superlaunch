module(..., package.seeall)
function new()
	local self = display.newGroup()
	
	local classicButtonPress = function( event )
		local backgroundMusic = audio.loadStream("backgroundMusic.mp3")
		--local backgroundMusicChannel = audio.play( backgroundMusic, { channel=1, loops=-1, fadein=5000 }  )  -- play the background music on channel 1, loop infinitely, and fadein over 5 seconds 
		director:changeScene("characterSelect", "moveFromRight", {"superlaunch"})
	end
	
	local levelButtonPress = function( event )
		local backgroundMusic = audio.loadStream("backgroundMusic.mp3")
		--local backgroundMusicChannel = audio.play( backgroundMusic, { channel=1, loops=-1, fadein=5000 }  )  -- play the background music on channel 1, loop infinitely, and fadein over 5 seconds 
		director:changeScene("characterSelect", "moveFromRight", {"levelMenu"})
	end
	
	local highScoresButtonPress = function( event )
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
	
	

	-- Handler that gets notified when the alert closes
	local function onComplete( event )
			if "clicked" == event.action then
					local i = event.index
					if 1 == i then							
						os.exit()
					elseif 2 == i then
						-- Do nothing; dialog will simply dismiss
					end
			end
	end
	 
	
	-- Key listener
	local function onKeyEvent( event )
		local phase = event.phase
		local keyName = event.keyName
		
		-- Show alert with five buttons
		local alert = native.showAlert( "Corona", "Are you sure you want to exit?", 
										{ "YES", "NO" }, onComplete )
		return true
	end
	
	-- Add the key callback
	Runtime:addEventListener( "back", onKeyEvent );
	
	function clean()
	end
	
	return self
end