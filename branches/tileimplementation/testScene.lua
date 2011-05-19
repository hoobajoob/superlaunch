module(..., package.seeall)

function new( arguments )
	local scene = {}
	require "sprite"
	local tbaUI = require( "tbaUI" )
	require('socket')
	physics.setDrawMode( "hybrid" )
	local groundReferencePoint = 335
	local mainCharacter
	local mainContainerGroup
	local game
	local overlayDisplay
	---[[load sounds
	local explosionSound = audio.loadSound("grenade.mp3")
	local boingSound = audio.loadSound("boing.ogg")
	local swooshSound = audio.loadSound("swoosh.mp3")	
	local bounceSound = audio.loadSound("bounce.mp3")	
	local owSound = audio.loadSound("ow.ogg")	
	--]]------
	local totalScore = {}
	local timeLeft = 100
	math.randomseed( os.time() )
	math.random()
	if arguments ~= nil and # arguments > 1 and arguments[2] == true then						
		timeMode = true
		timeBar = tbaUI.newBar{
			bounds = { 0, 290 + display.screenOriginY, 5, 5 },
			lineColor = { 0, 255, 50, 255 },
			size = timeLeft,
			width = 5
		}
		timeBar.bodyName = "timeBar"
		timeBar:setSize( timeLeft )
		timeBar.isVisible = true
		print( "timeMode on")
		local tTimeLeft = system.getTimer()
		local function timeCheck( event )
			local tTimeLeftDelta = (event.time - tTimeLeft)
			if timeMode and tTimeLeftDelta > 750 then
				tTimeLeft = event.time;
				timeLeft = timeLeft - 1
				timeBar:setSize( timeLeft )
			end
		end
		Runtime:addEventListener( "enterFrame", timeCheck )
	end
	
	function start()
		print("Starting Super Launch")
		physics.start()		
		
		return game
	end
	
	return start()
end