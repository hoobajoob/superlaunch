module(..., package.seeall)
local ui = require("ui")
local storyboard = require( "storyboard" )
local scene = storyboard.newScene()

function scene:createScene( event )
	local group = self.view

	local bg = display.newImage( "background.png", true )
	
	local openFeintButtonPress = function( event )
		gameNetwork.show("leaderboards")
	end
	
	local achievementsButtonPress = function( event )
		gameNetwork.show("achievements")
	end
	
	local localButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent );
		storyboard.gotoScene("localHighScores")
	end
	
	local openFeintButton = ui.newButton{
		defaultSrc = "btn_leaderboard.png",
		overSrc = "btn_leaderboardA.png",
		onRelease = openFeintButtonPress,
		emboss = true,
		x = 80,
		y = 280
	}
	openFeintButton.isVisible = true

	local achievementsButton = ui.newButton{
		defaultSrc = "btn_achievements.png",
		overSrc = "btn_achievementsA.png",
		onRelease = achievementsButtonPress,
		emboss = true,
		x = 240,
		y = 280
	}
	achievementsButton.isVisible = true
	
	local localButton = ui.newButton{
				defaultSrc = "btn_localHS.png",
				overSrc = "btn_localHSA.png",
				onPress = localButtonPress,
				emboss = true,
				x = 400,
				y = 280
			}			
	localButton.isVisible = true
	
	local backButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )
		storyboard.gotoScene("mainMenu")
	end
	
	local backButton = ui.newButton{
		defaultSrc = "btn_back.png",
		overSrc = "btn_back.png",
		onRelease = backButtonPress,
		emboss = true,
		x = 450,
		y = 30
	}
	backButton.isVisible = true
	
	group:insert( bg )	
	group:insert(openFeintButton)
	group:insert(achievementsButton)
	group:insert(localButton)
	group:insert(backButton)
end

function scene:enterScene( event )
	local group = self.view
end

function scene:exitScene( event )
	local group = self.view
end

function scene:destroyScene( event )
	local group = self.view
end

scene:addEventListener( "createScene", scene )
scene:addEventListener( "enterScene", scene )
scene:addEventListener( "exitScene", scene )
scene:addEventListener( "destroyScene", scene )

return scene