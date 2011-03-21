module(..., package.seeall)

local ui = require("ui")
local tableView = require("tableView")

function new()

	local self = display.newGroup()

	self.back = display.newRect(self, 0, 0, display.contentWidth, display.contentHeight)
		
	local topBoundary = display.screenOriginY
	local bottomBoundary = display.screenOriginY
	
	timeLeft = 100

	
	function clean()
	end
	
	local noahButton = nil
	local babyButton = nil
	local dogButton = nil
	
	local function noahButtonPress()
		noahButton.isVisible = false
		babyButton.isVisible = false
		dogButton.isVisible = false		
		director:changeScene("noahLauncher", "moveFromRight", {"noah", true})
	end
	
	local function babyButtonPress()
		babyButton.isVisible = false
		noahButton.isVisible = false
		dogButton.isVisible = false
		director:changeScene("noahLauncher", "moveFromRight", {"baby", true})
	end
	
	local function dogButtonPress()
		babyButton.isVisible = false
		noahButton.isVisible = false
		dogButton.isVisible = false
		director:changeScene("noahLauncher", "moveFromRight", {"dog", true})
	end

	noahButton = ui.newButton{
					default = "noah.png",
					onPress = noahButtonPress,
					emboss = true,
					x = 180,
					y = 200
				}
	babyButton = ui.newButton{
					default = "baby.png",
					onPress = babyButtonPress,
					emboss = true,
					x = 320,
					y = 200
				}
	dogButton = ui.newButton{
					default = "dog.png",
					onPress = dogButtonPress,
					emboss = true,
					x = 250,
					y = 100
				}
	
	return self
	
end