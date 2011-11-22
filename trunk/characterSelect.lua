module(..., package.seeall)

function new( arguments )

	local self = display.newGroup()
	local nextScene = arguments[1]
		
	local topBoundary = display.screenOriginY
	local bottomBoundary = display.screenOriginY
	
	local noahButton = nil
	local babyButton = nil
	local dogButton = nil
		
	--[[ Back Key listener
	local function onKeyEventChar( event )
		local phase = event.phase
		local keyName = event.keyName
		
		if (phase == "up" and keyName == "back") then 
			Runtime:removeEventListener( "key", onKeyEventChar );
				timer.performWithDelay(100, moveBack("mainMenu", "moveFromLeft", {}), 1)
		end
		return true
	end
	--]]
	local function noahButtonPress()
		noahButton.isVisible = false
		babyButton.isVisible = false
		dogButton.isVisible = false		
		--Runtime:removeEventListener( "back", onKeyEventChar );
		director:changeScene(nextScene, "moveFromRight", {"noah", true})
	end
	
	local function babyButtonPress()
		babyButton.isVisible = false
		noahButton.isVisible = false
		dogButton.isVisible = false
		--Runtime:removeEventListener( "back", onKeyEventChar );
		director:changeScene(nextScene, "moveFromRight", {"baby", true})
	end
	
	local function dogButtonPress()
		babyButton.isVisible = false
		noahButton.isVisible = false
		dogButton.isVisible = false
		--Runtime:removeEventListener( "back", onKeyEventChar );
		director:changeScene(nextScene, "moveFromRight", {"dog", true})
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
	
	-- Add the back key callback
	--Runtime:addEventListener( "key", onKeyEventChar );
		
	
	local alert = native.showAlert("Superlaunch", "Argument passed is "..nextScene, { "OK" } )
	return self	
end