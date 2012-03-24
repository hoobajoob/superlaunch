module(..., package.seeall)
local ui = require("ui")
local scrollView = require("scrollView")
local util = require("util")
local storyboard = require( "storyboard" )
local scene = storyboard.newScene()
-- Back Key listener
local function onBackEvent( event )
	local phase = event.phase
	local keyName = event.keyName
	
	if (keyName == "back" and phase == "up") then 
		storyboard.gotoScene("mainMenu")
		return true
	end
end	

local function addKeyEvent()
	print( "adding Key Listener" )
	Runtime:addEventListener( "key", onBackEvent )
end

function scene:createScene( event )
	local group = self.view
end

function scene:enterScene( event )
	local group = self.view
	
	local background = display.newRect(0, 0, display.contentWidth, display.contentHeight)
	
	background:setFillColor(140, 140, 140)
	-- Setup a scrollable content group
	local topBoundary = display.screenOriginY
	local bottomBoundary = display.screenOriginY
	local scrollView = scrollView.new{ top=topBoundary, bottom=bottomBoundary }
	 
	local myText = display.newText("\n\n\nMove Up to Scroll", 0, 0, native.systemFontBold, 16)
	myText:setTextColor(0, 0, 0)
	myText.x = math.floor(display.contentWidth*0.5)
	myText.y = 108
	scrollView:insert(myText)
	 	
	-- add some text to the scrolling screen
	local path = system.pathForFile( "helpText.txt", system.ResourceDirectory )
	local file = io.open( path, "r" )
	local lotsOfText = nil
	if file then -- nil if no file found
	   lotsOfText = file:read( "*a" )
	   io.close( file )
	end
	local lotsOfTextObject = util.wrappedText( lotsOfText, 65, 14, native.systemFont, {0,0,0} )
	scrollView:insert(lotsOfTextObject)
	lotsOfTextObject.x = 24
	lotsOfTextObject.y = math.floor(myText.y + myText.height)
	 
	-- Important! Add a background to the scroll view for a proper hit area
	local scrollBackground = display.newRect(0, 0, display.contentWidth, scrollView.height+64)
	scrollBackground:setFillColor(255, 255, 255)
	scrollView:insert(1, scrollBackground)
	
	scrollView:addScrollBar()
	
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
	
	local emailButtonPress = function( event )
		local options =
		{
		   to = "kc@teambearattack.com",
		   subject = "Superlaunch Feedback",
		   body = "KC.  I have something to tell you about Superlaunch:\n\n\n",
		}
		native.showPopup("mail", options)
	end	
	
	local emailButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				x = 240,
				y = 30,
				overSrc = "buttonRedOver.png",
				onRelease = emailButtonPress,
				text = "Email Developer",
				emboss = true
			}
	emailButton.isVisible = true
	
	local tutorialOnButton
	
	local tutorialOnButtonPress = function( event )		
		--Open GameData.sqlite.  If the file doesn't exist it will be created
		local path = system.pathForFile("GameData.sqlite", system.DocumentsDirectory)
		db = sqlite3.open( path )
		local insertValue = 1
		if storyboard.tutorialEnabled == true then
			insertValue = 0
			storyboard.tutorialEnabled = false
			tutorialOnButton:setText( "Turn Tutorial On")
		else
			storyboard.tutorialEnabled = true
			tutorialOnButton:setText( "Turn Tutorial Off" )
		end
		local tablefill = [[UPDATE tblUsers SET fTutorial = ]]..insertValue..[[ WHERE ixUser = ]]..storyboard.userIndex..[[;]]
		db:exec( tablefill )
	end	
	
	tutorialOnButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				x = 240,
				y = 90,
				overSrc = "buttonRedOver.png",
				onRelease = tutorialOnButtonPress,
				text = "Turn Tutorial On",
				emboss = true
			}
	if storyboard.tutorialEnabled == true then
		tutorialOnButton:setText( "Turn Tutorial Off" )
	end
	tutorialOnButton.isVisible = true
	
	group:insert( background )
	group:insert( scrollView )
	group:insert( backButton )
	group:insert( emailButton )
	group:insert( tutorialOnButton )
	timer.performWithDelay( 10, addKeyEvent )
end

function scene:exitScene( event )
	local group = self.view
	Runtime:removeEventListener( "key", onBackEvent );
end

function scene:destroyScene( event )
	local group = self.view
end

scene:addEventListener( "createScene", scene )
scene:addEventListener( "enterScene", scene )
scene:addEventListener( "exitScene", scene )
scene:addEventListener( "destroyScene", scene )

return scene