module(..., package.seeall)
function new()
	local self = display.newGroup()
	
	local startButtonPress = function( event )
		local backgroundMusic = audio.loadStream("backgroundMusic.mp3")
		local backgroundMusicChannel = audio.play( backgroundMusic, { channel=1, loops=-1, fadein=5000 }  )  -- play the background music on channel 1, loop infinitely, and fadein over 5 seconds 
		director:changeScene("timedModeMain", "moveFromRight")
	end
	
	local highScoresButtonPress = function( event )
		director:changeScene("highScores", "moveFromTop")
	end
	
	local startButton = ui.newButton{
				default = "buttonRed.png",
				over = "buttonRedOver.png",
				onPress = startButtonPress,
				text = "Start",
				emboss = true,
				x = 240,
				y = 55
			}
	startButton.isVisible = true
	
	self:insert(startButton)
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
	
	function clean()
	end
	
	return self
end