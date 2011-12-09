module(..., package.seeall)

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
			text = "High Scores",
			--font = "Trebuchet-BoldItalic",
			textColor = { 255, 200, 100, 255 },
			size = 33,
			align = "center"
		}
	self:insert( mainLabel )
	mainLabel:setText( "Select a Character" )
	
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