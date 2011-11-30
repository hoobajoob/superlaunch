module(..., package.seeall)
function new()
	local self = display.newGroup()	

	local bg = display.newImage( "background.png", true )
	self:insert( bg )
	
	local openFeintButtonPress = function( event )
		gameNetwork.show("leaderboards")
	end
	
	local achievementsButtonPress = function( event )
		gameNetwork.show("achievements")
	end
	
	local localButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent );
		director:changeScene("localHighScores", "moveFromRight")
	end
	
	local openFeintButton = ui.newButton{
		default = "btn_leaderboard.png",
		over = "btn_leaderboardA.png",
		onRelease = openFeintButtonPress,
		emboss = true,
		x = 80,
		y = 280
	}
	openFeintButton.isVisible = true
	self:insert(openFeintButton)

	local achievementsButton = ui.newButton{
		default = "btn_achievements.png",
		over = "btn_achievementsA.png",
		onRelease = achievementsButtonPress,
		emboss = true,
		x = 240,
		y = 280
	}
	achievementsButton.isVisible = true
	self:insert(achievementsButton)
	
	local localButton = ui.newButton{
				default = "btn_localHS.png",
				over = "btn_localHSA.png",
				onPress = localButtonPress,
				emboss = true,
				x = 400,
				y = 280
			}			
	localButton.isVisible = true
	self:insert(localButton)
	
	function clean()
	end
	
	return self
end