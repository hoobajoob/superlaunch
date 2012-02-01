module(..., package.seeall)
local ui = require("ui")
local storyboard = require( "storyboard" )
local scene = storyboard.newScene()

function scene:createScene( event )
	local group = self.view
	
	local backButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )
		storyboard.gotoScene("levelModeMain")
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
	
	local levelButtonPress = function(event)
		Runtime:removeEventListener( "key", onKeyEventLevelMenu );
		table.insert(storyboard.arguments, event.arguments)
		if storyboard.arguments[3] == "hardLaunch" then
			storyboard.nextScene = "levelLaunch"
			storyboard.gotoScene( "hardLaunch" )
		else
			storyboard.gotoScene("levelLaunch")
		end
	end
	
	---[[
	local int row = 1
	local int col = 1
	local yOffset = 40
	local xOffset = 0
	for level=1,20 do
		local thisButton = ui.newButton{				
				defaultSrc = "levelButton.png",
				onEvent = levelButtonPress,
				overSrc = "levelButtonOver.png",
				text = "SlingShot Mode",
				text = level,
				emboss = true,
				x = ( col * 78 ) + xOffset,
				y = ( row * 58 ) + yOffset,
				arguments = level
			}
		thisButton.isVisible = true
		group:insert( thisButton )
		col = col + 1
		if level % 5 == 0 then row = row + 1; col = 1 end
    end
	--]]
	
	group:insert( backButton )
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