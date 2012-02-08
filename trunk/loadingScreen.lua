--loadingScreen.lua
module(..., package.seeall)

function newLoadingScreen( params )
	local loadingScreen, lcImage, startTime, endTime, fadeTime, finalEvent, eventArguments, background, transitionToImage
	local fadeOutComplete = false
	loadingScreen = display.newGroup()
	
	if params.blackBackground then
		background = display.newRect(0, 0, display.contentWidth, display.contentHeight)
		background:setFillColor(0, 0, 0)
	end
	
	if params.srcImage then
		lcImage = display.newImage( params.srcImage )
	else
		lcImage = display.newRect(0, 0, display.contentWidth, display.contentHeight)
		lcImage:setFillColor(0, 0, 0)
	end	
	
	startTime = system.getTimer()
	if isSimulator then
		endTime = startTime + 250
		fadeTime = 250
	else
		fadeTime = 1000
		if params.duration then
			endTime = startTime + params.duration
		else
			endTime = startTime + 500
		end
	end
	
	if params.fadeIn then
		lcImage.alpha = 0
		transition.to( lcImage, { time=fadeTime, alpha=1 } )
	end
	
	if params.finalEvent then
		finalEvent = params.finalEvent
	end
	
	loadingScreen.clear = function()
		print ( "screenCleared" )
		if transitionToImage ~= nil then
			transitionToImage.isVisible = false
			transitionToImage:removeSelf()		
		end
		lcImage.isVisible = false
		lcImage:removeSelf()
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
			if params.fadeOut and fadeOutComplete == false then
				fadeOutComplete = true
				transition.to( lcImage, { time=fadeTime, alpha=0, onComplete=loadingScreen.loadingFinished } )
			else
				timer.performWithDelay(endTime - curTime, loadingScreen.clear, 1)
			end
		else
			loadingScreen.clear()
		end
	end
	
	
	if params.transitionToImage then
		transitionToImage = display.newImage( params.transitionToImage )
		transitionToImage.alpha = 0
		local function trans()
			transition.to( transitionToImage, { time=( endTime - curTime ) / 2, alpha=1 } )
		end
		curTime = system.getTimer()
		timer.performWithDelay( (endTime - curTime) / 4, trans , 1 )
	end
	return loadingScreen
end