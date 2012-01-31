module(..., package.seeall)
local ui = require("ui")
local util = require("util")
local storyboard = require( "storyboard" )
local scene = storyboard.newScene()
local launchButton

function scene:createScene( event )
	local group = self.view
	
	local background = display.newRect(0, 0, display.contentWidth, display.contentHeight)
	
	background:setFillColor(140, 140, 140)
	
	launchButton = display.newImage( "launch.png" )
	group:insert( launchButton )
end

function scene:enterScene( event )
	local group = self.view
	local touchDelay = 0
	launchButton.isVisible = false
	local tNoPress
	
	local function sendLaunchValues()
	{
		Runtime:removeEventListener( "enterFrame", touchDelayAdd )
		storyboard.launchAngle = 50
		storyboard.launchPower = 100 - ( touchDelay * .2 )	
		storyboard.gotoScene(storyBoard.nextScene)
	}
	
	local function touchDelayAdd( event )
		if (event.time - tNoPress) > 100 then
			tNoPress = event.time
			touchDelay = touchDelay + 1
		end
		if touchDelay > 500 then
			sendLaunchValues()
		end
	end
	
	local function launchButtonTouched( event )
		sendLaunchValues()
	end
	
	local function showButton( event )
		launchButton.isVisible = true
		launchButton:addEventListener( "touch", launchButtonTouched )
		tNoPress = system.getTimer()
		Runtime:addEventListener( "enterFrame", touchDelayAdd )
	end
	 
	timer.performWithDelay( 1000, showButton )
end

function scene:exitScene( event )
	local group = self.view
		launchButton:removeEventListener( "touch", launchButtonTouched )
end

function scene:destroyScene( event )
	local group = self.view
end

scene:addEventListener( "createScene", scene )
scene:addEventListener( "enterScene", scene )
scene:addEventListener( "exitScene", scene )
scene:addEventListener( "destroyScene", scene )

return scene