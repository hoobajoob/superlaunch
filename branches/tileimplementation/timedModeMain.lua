module(..., package.seeall)

local ui = require("ui")
local tableView = require("tableView")

function new()

	local self = display.newGroup()

	self.back = display.newRect(self, 0, 0, display.contentWidth, display.contentHeight)
	self.list = {}
		
	local topBoundary = display.screenOriginY
	local bottomBoundary = display.screenOriginY
	
	function clean()
	end
	
	local noahButton = nil
	local babyButton = nil
	local dogButton = nil
	
	local function noahButtonPress()
		noahButton.isVisible = false
		babyButton.isVisible = false
		dogButton.isVisible = false		
		director:changeScene("superlaunch", "moveFromRight", {"noah", true})
	end
	
	local function babyButtonPress()
		babyButton.isVisible = false
		noahButton.isVisible = false
		dogButton.isVisible = false
		director:changeScene("superlaunch", "moveFromRight", {"baby", true})
	end
	
	local function dogButtonPress()
		babyButton.isVisible = false
		noahButton.isVisible = false
		dogButton.isVisible = false
		director:changeScene("superlaunch", "moveFromRight", {"dog", true})
	end

	noahButton = ui.newButton{
					default = "noah.png",
					onPress = noahButtonPress,
					emboss = true,
					x = 180,
					y = 200
				}
	self:insert(noahButton)
	babyButton = ui.newButton{
					default = "baby.png",
					onPress = babyButtonPress,
					emboss = true,
					x = 320,
					y = 200
				}
	self:insert(babyButton)
	dogButton = ui.newButton{
					default = "dog.png",
					onPress = dogButtonPress,
					emboss = true,
					x = 250,
					y = 100
				}
	self:insert(dogButton)
	
	return self
	
end