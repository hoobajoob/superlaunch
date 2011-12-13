module(..., package.seeall)
local ui = require("ui")

function new()

	local self = display.newGroup()
		
	local bg = display.newImage( "background.png", true )
	self:insert( bg )
	
	local topBoundary = display.screenOriginY
	local bottomBoundary = display.screenOriginY
	
	local noahButton = nil
	local babyButton = nil
	local dogButton = nil
	
	local mainLabel = ui.newLabel{
			bounds = { display.contentWidth /2 - 45, 15 + display.screenOriginY, 100, 24 }, -- align label with right side of current screen
			text = "Select a Character",
			--font = "Trebuchet-BoldItalic",
			textColor = { 255, 200, 100, 255 },
			size = 33,
			align = "center",
			emboss = true
		}
	self:insert( mainLabel )
	
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
	
	local function noahButtonPress()
		noahButton.isVisible = false
		babyButton.isVisible = false
		dogButton.isVisible = false		
		director:changeScene({"noah", true}, "superLaunch", "moveFromRight")
	end
	
	local function babyButtonPress()
		babyButton.isVisible = false
		noahButton.isVisible = false
		dogButton.isVisible = false
		director:changeScene({"baby", true}, "superLaunch", "moveFromRight")
	end
	
	local function dogButtonPress()
		babyButton.isVisible = false
		noahButton.isVisible = false
		dogButton.isVisible = false
		director:changeScene({"dog", true}, "superLaunch", "moveFromRight")
	end

	noahButton = ui.newButton{
					defaultSrc = "noah.png",
					onEvent = noahButtonPress,
					emboss = true,
					x = 180,
					y = 200
				}
	self:insert(noahButton)
	babyButton = ui.newButton{
					defaultSrc = "baby.png",
					onEvent = babyButtonPress,
					emboss = true,
					x = 320,
					y = 200
				}
	self:insert(babyButton)
	dogButton = ui.newButton{
					defaultSrc = "dog.png",
					onEvent = dogButtonPress,
					emboss = true,
					x = 250,
					y = 100
				}
	self:insert(dogButton)
	
	return self	
end