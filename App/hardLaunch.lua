module(..., package.seeall)
local ui = require("ui")
local util = require("util")
local storyboard = require( "storyboard" )
local scene = storyboard.newScene()
local launchLabel
local background	

function scene:createScene( event )
	print( "creating hardLaunch" )
	local group = self.view
	
	background = display.newRect(0, 0, display.contentWidth, display.contentHeight)
	
	background:setFillColor(140, 140, 140)
		
	launchLabel = ui.newLabel{
			bounds = { display.contentWidth /2 - 45, 100 + display.screenOriginY, 100, 24 },
			text = "   Touch Screen\n      to\nStart Launch Sequence",
			--font = "Trebuchet-BoldItalic",
			textColor = { 255, 200, 100, 255 },
			size = 33,
			align = "center"
		}
	launchLabel.isVisible = true
		
	group:insert( background )
	group:insert( launchLabel )
end

function scene:enterScene( event )
	print( "entering hardLaunch" )
	local group = self.view
	local touchStart
	local tNoPress
	local valuesSent = false
	
	local function reduceBackground()
		local change =  ( system.getTimer() - touchStart ) * .2
		background:setFillColor( change, 255 - change, 50, 255 - ( change / 1.5 ) )
	end
	
	local function startReduceBackground()
		Runtime:addEventListener( "enterFrame", reduceBackground )	
	end
	
	local function sendLaunchValues()
		Runtime:removeEventListener( "enterFrame", reduceBackground )
		valuesSent = true
		storyboard.launchPower = 100 - ( (system.getTimer() - tNoPress) * .016 )
		print("sending launch power "..storyboard.launchPower)
		storyboard.gotoScene(storyboard.nextScene)
	end
	
	local function backgroundTouchedEarly( event )
		background:removeEventListener( "touch", backgroundTouchedEarly )
		background:setFillColor( 255, 0, 0, 255 )
		launchLabel:setText( "TOO SOON!!!" )
		tNoPress = system.getTimer() - 5000
		timer.performWithDelay( 500, sendLaunchValues ) --prevents touch event from carrying over to superlaunch
	end
	
	local function backgroundTouched( event )
		if event.phase == "ended" then
			background:removeEventListener( "touch", backgroundTouched )
			timer.performWithDelay( 1, sendLaunchValues ) --prevents touch event from carrying over to superlaunch
		end
	end
	
	local function sendIfNotSent()
		if valuesSent == false then sendLaunchValues() end
	end
	
	local function startPower( event )
		if valuesSent == false then
			background:removeEventListener( "touch", backgroundTouchedEarly )
			background:setFillColor( 0, 255, 50 )
			launchLabel:setText( "Launch!!!" )
			background:addEventListener( "touch", backgroundTouched )
			tNoPress = system.getTimer()
			timer.performWithDelay( 1250, sendIfNotSent )
			touchStart = system.getTimer()
			timer.performWithDelay( 250, startReduceBackground )
		end
	end
	
	math.randomseed( os.time() )
	math.random()
	local function addEarlyTouchEvent()
		background:addEventListener( "touch", backgroundTouchedEarly )	
	end
	
	local function startLaunch()
		background:removeEventListener( "touch", startLaunch )
		background:setFillColor(0,0,0)
		launchLabel:setText( "Get Ready" )
		timer.performWithDelay( 100, addEarlyTouchEvent )
		timer.performWithDelay(  math.random(2000,5000), startPower )
	end
	
	background:addEventListener( "touch", startLaunch )
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