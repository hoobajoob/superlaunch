module(..., package.seeall)
local ui = require("ui")
local scrollView = require("scrollView")
local util = require("util")
 
function new()
	local self = display.newGroup()
	local background = display.newRect(0, 0, display.contentWidth, display.contentHeight)
	self:insert( background )
	background:setFillColor(140, 140, 140)
	-- Setup a scrollable content group
	local topBoundary = display.screenOriginY
	local bottomBoundary = display.screenOriginY
	local scrollView = scrollView.new{ top=topBoundary, bottom=bottomBoundary }
	self:insert( scrollView )
	 
	local myText = display.newText("Move Up to Scroll", 0, 0, native.systemFontBold, 16)
	myText:setTextColor(0, 0, 0)
	myText.x = math.floor(display.contentWidth*0.5)
	myText.y = 48
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
		director:changeScene("mainMenu", "moveFromLeft")
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
	self:insert(backButton)
	
	function clean()
	end
	
	return self
end