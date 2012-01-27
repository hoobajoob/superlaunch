module(..., package.seeall)
local ui = require("ui")
local storyboard = require( "storyboard" )
local scene = storyboard.newScene()

function scene:createScene( event )
	local group = self.view
	
	local backButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )
		storyboard.gotoScene("levelModeMain")
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
	
	local levelButtonPress = function(event)		
		--[[
		while group.numChildren > 0	do	
			print("Clearing All "..group.numChildren.."in self")	
			for i=1, group.numChildren do
				if group[i] ~= nil then
					group:remove( i )
				end
			end
		end
		--]]
		Runtime:removeEventListener( "key", onKeyEventLevelMenu );
		table.insert(storyboard.arguments, event.arguments)
		storyboard.gotoScene("levelLaunch")
	end
	
	---[[
	local int row = 1
	local int col = 1
	for level=1,30 do
		print( "inserting button at " .. ( col * 68 ).."-".. ( row * 54 ))
		local thisButton = ui.newButton{				
				defaultSrc = "levelButton.png",
				onEvent = levelButtonPress,
				overSrc = "levelButtonOver.png",
				text = "SlingShot Mode",
				text = level,
				emboss = true,
				x = ( col * 68 ),
				y = ( row * 58 ),
				arguments = level
			}
		thisButton.isVisible = true
		group:insert( thisButton )
		col = col + 1
		if level % 6 == 0 then row = row + 1; col = 1 end
    end
	--]]
	
	group:insert( backButton )
end

function scene:enterScene( event )
	local group = self.view
end

function scene:exitScene( event )
	local group = self.view
end

function scene:destroyScene( event )
	local group = self.view
end

scene:addEventListener( "createScene", scene )
scene:addEventListener( "enterScene", scene )
scene:addEventListener( "exitScene", scene )
scene:addEventListener( "destroyScene", scene )

return scene