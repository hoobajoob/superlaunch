module(..., package.seeall)

local ui = require("ui")
local tableView = require("tableView")

function new()

	local self = display.newGroup()

	self.back = display.newRect(self, 0, 0, display.contentWidth, display.contentHeight)
	
	
	local onListItemRelease = function(event)
		_G["map"] = event.target.data --"mainLevel.tmx"
		if _G["map"].name == "Noah Launcher" then
			director:changeScene("timedModeMain", "moveFromRight")
		else
			director:changeScene("screen_Map", "moveFromRight")
		end
	end
	
	local maps = lime.utils.readInTable("maps.json", system.ResourceDirectory)
		
	local topBoundary = display.screenOriginY
	local bottomBoundary = display.screenOriginY
	--[[
	local menuButton = ui.newButton{
				default = "buttonRed.png",
				over = "buttonRedOver.png",
				onPress = menuButtonPress,
				text = "Return To Menu",
				emboss = true,
				x = 240,
				y = 155
			}
	menuButton.isVisible = false;
	--]]
	-- create the list of items
	self.list = tableView.newList{
		data=maps, 
		default="listItemBg.png",
		over="listItemBg_over.png",
		onRelease=onListItemRelease,
		top=topBoundary,
		bottom=bottomBoundary,
		backgroundColor={ 255, 255, 255 },
		callback=function(row) 
		
			local group = display.newGroup()
			
			group.nameText = display.newText(group, row.name, 0, 0, native.systemFontBold, 20)
			group.nameText:setTextColor(0, 0, 0)
			group.nameText.x = math.floor( group.nameText.width / 2) + 10
			group.nameText.y = 46
			
			group.descriptionText = display.newText(group, row.description, 0, 0, native.systemFontBold, 12)
			group.descriptionText:setTextColor(65, 65, 65)
			group.descriptionText.x = math.floor( group.descriptionText.width / 2) + 10
			group.descriptionText.y = group.nameText.y +  group.descriptionText.height * 1.5
		
		--	group.linkText = display.newText(group, row.link, 0, 0, native.systemFontBold, 10)
		--	group.linkText:setTextColor(0, 0, 128)
		--	group.linkText.x = math.floor( group.linkText.width / 2) + 10
		--	group.linkText.y = 70 --group.height --  group.linkText.height 
				
			return group
		end
	}

	self:insert(self.list)
	
	function clean()
		self.list:cleanUp()
	end
	
	return self
	
end