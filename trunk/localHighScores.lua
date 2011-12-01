module(..., package.seeall)
function new()
	local self = display.newGroup()	
	local bg = display.newImage( "highScores.png", true )
	self:insert( bg )
	
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

	--Setup the high score table if it doesn't exist
	local tablesetup = [[CREATE TABLE IF NOT EXISTS tblHighScores (ixHighScore INTEGER PRIMARY KEY, ixUser, dScore, dtCreated);]]
	db:exec( tablesetup )
	
	local usersList = {}
	for row in db:nrows("SELECT ixUser, sName FROM tblUsers") do
		print("adding user "..row.ixUser.." - "..row.sName)
		usersList[row.ixUser] = row
	end
	
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
	local onListItemRelease = function(event)
		--Todo:Open High Score in OpenFeint or play replay
	end
	self.list = tableView.newList{
		data=highScoreData, 
		default="highScoreListItem.png",
		over="highScoreListItem_Over.PNG",
		onRelease=onListItemRelease,
		top=100 + display.screenOriginY,
		bottom=bottomBoundary,
		backgroundColor={ 0, 0, 0 },
		callback=function(row) 
		
			local group = display.newGroup()
			
			group.nameText = display.newText(group, row.sName.." - "..string.format( "%i", row.dScore) .." - "..row.dtCreated, 0, 0, native.systemFontBold, 20)
			group.nameText:setTextColor(255, 255, 100)
			group.nameText.x = math.floor( group.nameText.width / 2) + 10
			group.nameText.y = 20
			
			--[[
			group.descriptionText = display.newText(group, row.description, 0, 0, native.systemFontBold, 12)
			group.descriptionText:setTextColor(65, 65, 65)
			group.descriptionText.x = math.floor( group.descriptionText.width / 2) + 10
			group.descriptionText.y = group.nameText.y +  group.descriptionText.height * 1.5
			--]]
		
		--	group.linkText = display.newText(group, row.link, 0, 0, native.systemFontBold, 10)
		--	group.linkText:setTextColor(0, 0, 128)
		--	group.linkText.x = math.floor( group.linkText.width / 2) + 10
		--	group.linkText.y = 70 --group.height --  group.linkText.height 
				
			return group
		end
	}
	self.list:addScrollBar(200, 200, 200)
	
	
	local backButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )
		director:changeScene("highScores", "moveFromLeft")
	end
	
	local backButton = ui.newButton{
		default = "btn_back.png",
		over = "btn_back.png",
		onRelease = backButtonPress,
		emboss = true,
		x = 450,
		y = 30
	}
	backButton.isVisible = true
	self:insert(backButton)
	
	self:insert(self.list)
	function clean()
		self.list:cleanUp()
	end
	
	return self
end