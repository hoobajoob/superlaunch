module(..., package.seeall)
local ui = require("ui")
local storyboard = require( "storyboard" )
local scene = storyboard.newScene()
local widget = require("widget")
-- Back Key listener
-- Back Key listener
local function onBackEvent( event )
	local phase = event.phase
	local keyName = event.keyName
	
	if (keyName == "back" and phase == "up") then 
		storyboard.gotoScene("highScores")
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
	
	local bg = display.newImage( "highScores.png", true )
	
	--Open GameData.sqlite.  If the file doesn't exist it will be created
	local path = system.pathForFile("GameData.sqlite", system.DocumentsDirectory)
	db = sqlite3.open( path )   
	 
	--Handle the applicationExit event to close the db
	local function onSystemEvent( event )
		if( event.type == "applicationExit" ) then              
			db:close()
		end
	end
	 
	--setup the system listener to catch applicationExit
	Runtime:addEventListener( "system", onSystemEvent )
	
	local onListItemRelease = function(event)
		--Todo:Open High Score in OpenFeint or play replay
	end	
	
	local backButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )
		storyboard.gotoScene("highScores")
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
	--[[
	local highScoreData = {}
	curRow = 1
	for row in db:nrows("SELECT ixHighScore, ixUser, dScore, dtCreated FROM tblHighScores ORDER BY dScore DESC") do
		if usersList[row.ixUser] == nil then
			row.sName = "Anonymous" 
		else 
			row.sName = usersList[row.ixUser].sName 
		end
		highScoreData[curRow] = row
		curRow = curRow + 1
	end
	--]]

	--Setup the high score table if it doesn't exist
	local tablesetup = [[CREATE TABLE IF NOT EXISTS tblHighScores (ixHighScore INTEGER PRIMARY KEY, ixUser, dScore, dtCreated);]]
	db:exec( tablesetup )
	
	local usersList = {}
	for row in db:nrows("SELECT ixUser, sName FROM tblUsers") do
		print("adding user "..row.ixUser.." - "..row.sName)		
		usersList[row.ixUser] = row
	end
	
	local list = widget.newTableView{
		top = 100 + display.screenOriginY,
		bgColor = { 0, 0, 0, 255 },
		height = 220,
		--maskFile = "mask220x480.png"
	}
	--list:sync( highScoreData )
	---[[
	--local curHeight = 100
	for row in db:nrows("SELECT ixHighScore, ixUser, dScore, dtCreated FROM tblHighScores ORDER BY dScore DESC") do	
		local function onRowRender( event )
		local curRow = event.target
			if usersList[row.ixUser] == nil then
				row.sName = "Anonymous" 
			else 
				row.sName = usersList[row.ixUser].sName 
			end
			local text = display.newRetinaText(event.view,  row.sName.." - "..string.format( "%i", row.dScore) .." - "..row.dtCreated, 0, 0, native.systemFontBold, 16)
			text:setReferencePoint( display.CenterLeftReferencePoint )
			text.x = 25
			text.y = curRow.height * 0.5
			--text.y = curHeight + (curRow.height * 0.5)
			--curHeight = curHeight + curRow.height
			--event.view:insert( text )
		end
		list:insertRow{
			id = "index "..row.ixHighScore,
			height = 20,
			rowColor = { 0, 0, 0, 255 },
			onRender = onRowRender
		}
	end
	--]]
	group:insert(list)
	group:insert( bg )
	group:insert(backButton)
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