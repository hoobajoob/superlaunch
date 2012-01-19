module(..., package.seeall)
local ui = require("ui")
local storyboard = require( "storyboard" )
local scene = storyboard.newScene()

function scene:createScene( event )
	local group = self.view

	local bg = display.newImage( "background.png", true )
	
	local defaultField, numberField -- forward reference (needed for Lua closure)
	
	--Open GameData.sqlite.  If the file doesn't exist it will be created
	local path = system.pathForFile("GameData.sqlite", system.DocumentsDirectory)
	db = sqlite3.open( path )   
	 
	--Handle the applicationExit event to close the db
	function onSystemEvent( event )
		if( event.type == "applicationExit" ) then              
			db:close()
		end
	end
	 
	--setup the system listener to catch applicationExit
	Runtime:addEventListener( "system", onSystemEvent )	
 
	local function updateUser( stringName )
		userName = stringName
		for row in db:nrows("SELECT ixUser, sName FROM tblUsers WHERE sName = '"..userName.."'") do
			userIndex = row.ixUser break 
		end
	end
 
	-- TextField Listener
	local function fieldHandler( getObj )
			
	-- Use Lua closure in order to access the TextField object
	 
			return function( event )
	 
					print( "TextField Object is: " .. tostring( getObj() ) )
					
					if ( "began" == event.phase ) then
							-- This is the "keyboard has appeared" event
					
					elseif ( "ended" == event.phase ) then
							-- This event is called when the user stops editing a field:
							-- for example, when they touch a different field or keyboard focus goes away
					
							print( "Text entered = " .. tostring( getObj().text ) )         -- display the text entered
							updateUser(tostring( getObj().text ))
							
							
					elseif ( "submitted" == event.phase ) then
							-- This event occurs when the user presses the "return" key
							-- (if available) on the onscreen keyboard
							
							-- Hide keyboard
							native.setKeyboardFocus( nil )
					end
					
			end     -- "return function()"
	 
	end
	 
	-- Create our Text Field
	defaultField = native.newTextField( 10, 30, 180, 30,
			fieldHandler( function() return defaultField end ) )    -- passes the text field object
	
	local backButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )
		defaultField:removeSelf()
		storyboard.gotoScene("mainMenu")
	end
	
	local submitButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )
		if defaultField ~= nil then
			if username ~= defaultField.text then updateUser(tostring( defaultField.text )) end		
			defaultField.isVisible = false
			defaultField = nil
		end
		native.showAlert( "SuperLaunch", "User Index is "..userIndex.." and Username is "..userName, 
									{ "OK" } )
		storyboard.gotoScene("mainMenu")
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
	
	local submitButton = ui.newButton{
		defaultSrc = "btn_achievements.png",
		x = 240,
		y = 280,
		overSrc = "btn_achievementsA.png",
		onEvent = submitButtonPress,
		emboss = true
	}
	submitButton.isVisible = true
	
	group:insert( bg )
	group:insert(backButton)
	group:insert(submitButton)
	
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