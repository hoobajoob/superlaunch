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



ads.init( "inneractive", "RecRoomRecords_Superlaunch_Android" )
gameNetwork.init( "openfeint", "j6oZJXqa1ZMPXOFkezATA", "D0jJ5j57G1chPqXUQiv5m60hHlRwhzaXGgMNWUaQOI", "SuperLaunch", "405093" )

highScoreLeaderboard = "1002786"
	
storyboard.userName = "Anonymous"
storyboard.userIndex = 0

playSounds = false
	
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

--storyboard.gotoScene( "mainMenu" )

--[[
local adSpace
local tableView = require("tableView")
local scrollView = require("scrollView")
local util = require("util")

local aboutDisplay

local function showAd(event)
     -- Is the url a remote call?
     if string.find(event.url, "http://", 1, false) == 1 then
          -- Is it a call to the admob server?
          if string.find(event.url, "c.admob.com", 1, false) == nil then
               adSpace.url = event.url
          else
               -- an actual click on an ad, so open in Safari
               system.openURL(event.url)
          end
     else
          -- Feb 1, 2011: if using the old version of this code, remove the
          -- following line:
          -- adSpace.url = event.url
          -- and put in this line instead:
          return true
     end
end

adSpace = native.showWebPopup(0, 432, 320, 48, "ad.html", {baseUrl = system.ResourceDirectory, urlRequest = showAd})

local noahLauncher = require( "noahLauncher" )
local ui = require( "ui" )
require('socket')
resetButton = nil
startButton = nil
optionsButton = nil
helpButton = nil
aboutButton = nil

local function clearMenu()
	--startButton:removeSelf()
	optionsButton:removeSelf()
	helpButton:removeSelf()
	aboutButton:removeSelf()
end

local resetButtonPress = function( event )
	if scene ~= nil then
		scene:clearAll()
	end
	if scene ~= nil then
		--scene:removeSelf()
		scene = nil
	end
	if resetButton ~= nil then
		resetButton = nil
	end
	scene = noahLauncher.createScene{
		onDeath = displayResetButton,
		showAdFunction = showAd
	}
end
local startButtonPress = function( event )
	clearMenu()
	scene = noahLauncher.createScene{
		onDeath = displayResetButton,
		showAdFunction = showAd
	}
end

local menuButtonPress = function( event )

end

local helpButtonPress = function( event )

end

local createAboutDisplay = function( params )		
	local background = display.newRect(0, 0, display.contentWidth, display.contentHeight)
	background:setFillColor(140, 140, 140)
	
	local onBack
	if ( params.onBack and ( type(params.onBack) == "function" ) ) then
		onBack = params.onBack
	end
	local backButtonPress = function( event )
		self:removeSelf()
	end
	local backButton = ui.newButton{
		default = "menuButton.png",
		over = "menuButtonOver.png",
		onPress = backButtonPress,
		text = "Back",
		emboss = true,
		x = 60,
		y = 20,
		size = 15
	}

	-- Setup a scrollable content group
	local topBoundary = display.screenOriginY
	local bottomBoundary = display.screenOriginY
	local scrollView = scrollView.new{ top=topBoundary, bottom=bottomBoundary }

	local myText = display.newText("Move Up to Scroll", 0, 20, native.systemFontBold, 16)
	myText:setTextColor(0, 0, 0)
	myText.x = math.floor(display.contentWidth*0.5)
	myText.y = 48
	scrollView:insert(myText)

	-- add some text to the scrolling screen
	local aboutText = "SuperLaunch Alpha is the first release of a scrolling physics game created by KC Embrey.  This is the first game released by TeamBearAttack, Rec Room Records and KC Embrey.  There will be subsequent releases of this game very soon which will include graphics, gameplay and interface enhancements as well as new modes of play and a high score tracker."
	
	local aboutTextObject = util.wrappedText( aboutText, 39, 14, native.systemFont, {0,0,0} )
	scrollView:insert(aboutTextObject)
	aboutTextObject.x = 24
	aboutTextObject.y = math.floor(myText.y + myText.height)

	-- Important! Add a background to the scroll view for a proper hit area
	local scrollBackground = display.newRect(0, 40, display.contentWidth, scrollView.height+64)
	scrollBackground:setFillColor(255, 255, 255)
	scrollView:insert(1, scrollBackground)

	scrollView:addScrollBar()
end

local function clearAboutDisplay()
	aboutDisplay:removeSelf()
end

local aboutButtonPress = function( event )
	aboutDisplay = createAboutDisplay{
		onBack = clearAboutDisplay
	}
end

local optionsButtonPress = function( event )

end

function displayResetButton()
	resetButton = ui.newButton{
		default = "buttonRed.png",
		over = "buttonRedOver.png",
		onPress = resetButtonPress,
		text = "Reset",
		emboss = true,
		x = 240,
		y = 155
	}
end

function displayMenu()
	startButton = ui.newButton{
		default = "menuButton.png",
		over = "menuButtonOver.png",
		onPress = startButtonPress,
		text = "Start",
		emboss = true,
		x = 160,
		y = 106,
		size = 15
	}
	optionsButton = ui.newButton{
		default = "menuButton.png",
		over = "menuButtonOver.png",
		onPress = optionsButtonPress,
		text = "Options",
		emboss = true,
		x = 320,
		y = 106,
		size = 15
	}
	helpButton = ui.newButton{
		default = "menuButton.png",
		over = "menuButtonOver.png",
		onPress = helpButtonPress,
		text = "Help",
		emboss = true,
		x = 160,
		y = 213,
		size = 15
	}
	aboutButton = ui.newButton{
		default = "menuButton.png",
		over = "menuButtonOver.png",
		onPress = aboutButtonPress,
		text = "About",
		emboss = true,
		x = 320,
		y = 213,
		size = 15
	}
end

displayMenu()
--]]