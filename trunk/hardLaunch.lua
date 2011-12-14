module(..., package.seeall)
local ui = require("ui")

function new()

	local self = display.newGroup()
		
	local w, h = display.contentWidth, display.contentHeight
	local background = display.newImage( "background.png" )
	background.xScale = 0.8
	background.yScale = 0.8
	background.alpha = 0.95
	local title = display.newText( "POP UP - Touch to go back", 0, 0, native.systemFontBold, 16 )
	
	------------------
	-- Listeners
	------------------
	
	local touched = function ( event )
		if event.phase == "ended" then
			director:closePopUp()
		end
	end
	
	--====================================================================--
	-- INITIALIZE
	--====================================================================--
	
	local function initVars ()
		
		------------------
		-- Inserts
		------------------
		
		self:insert( background )
		self:insert( title )
		
		------------------
		-- Positions
		------------------
		
		title.x = 160
		title.y = 240
		
		------------------
		-- Colors
		------------------
		
		title:setTextColor( 255,255,255 )
		
		------------------
		-- Listeners
		------------------
		
		background:addEventListener( "touch" , touched )
		
	end
	
	------------------
	-- Initiate variables
	------------------
	
	initVars()
	
	return self	
end