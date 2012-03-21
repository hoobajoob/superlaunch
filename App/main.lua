display.setStatusBar( display.HiddenStatusBar )
isSimulator = "simulator" == system.getInfo("environment")
--local preloader = require("preloader")
local storyboard = require "storyboard"
local ls = require( "loadingScreen" )
---[[
local splash = ls.newLoadingScreen{
	srcImage = "splash.png",
	transitionToImage = "splashWIcons.png",
	duration = 5000,
	finalEvent = storyboard.gotoScene,
	eventArguments = "mainMenu"
} 
--]]
local ui = require("ui")
local physics = require("physics")
local ads = require("ads")
local gameNetwork = require "gameNetwork"
require "sqlite3"

system.activate( "multitouch" )



ads.init( "inneractive", "RecRoomRecords_Superlaunch_Android" )
gameNetwork.init( "openfeint", "j6oZJXqa1ZMPXOFkezATA", "D0jJ5j57G1chPqXUQiv5m60hHlRwhzaXGgMNWUaQOI", "SuperLaunch", "405093" )

highScoreLeaderboard = "1002786"
	
storyboard.userName = "Anonymous"
storyboard.userIndex = 0

storyboard.playSounds = true
	
local onSystem = function( event )
	if event.type == "applicationSuspend" then
		if gameIsActive then
				gameIsActive = false
				physics.pause()
		end

	elseif event.type == "applicationExit" then
		if system.getInfo( "environment" ) == "device" then
				native.requestExit()
		end
	end
end


splash.loadingFinished()