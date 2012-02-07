--loadingScreen.lua
module(..., package.seeall)

function newLoadingScreen( params )
	local loadingScreen, lcImage, startTime, endTime, finalEvent, eventArguments
	
	loadingScreen = display.newGroup()
	
	if params.srcImage then
		lcImage = display.newImage( params.srcImage )
	else
		lcImage = display.newRect(0, 0, display.contentWidth, display.contentHeight)
		lcImage:setFillColor(0, 0, 0)
	end
	
	if params.finalEvent then
		finalEvent = params.finalEvent
	end
	
	startTime = system.getTimer()
	if params.duration then
		endTime = startTime + params.duration
	else
		endTime = startTime + 500
	end
	
	loadingScreen.clear = function()
		print ( "screenCleared" )
		lcImage.isVisible = false
		loadingScreen.isVisible = false
		loadingScreen:removeSelf()
		loadingScreen = nil
		if finalEvent and type(finalEvent) == "function" then
			if params.eventArguments then
				finalEvent( params.eventArguments)
			else
				finalEvent()
			end
		end
	end
	
	loadingScreen.loadingFinished = function()
		curTime = system.getTimer()
		if endTime > curTime then
			timer.performWithDelay(endTime - curTime, loadingScreen.clear, 1)
		else
			loadingScreen.clear()
		end
	end
	
	return loadingScreen
end