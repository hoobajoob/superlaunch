module(..., package.seeall)
function new()
	local self = display.newGroup()	

	local bg = display.newImage( "background.png", true )
	self:insert( bg )
	
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
		director:changeScene("mainMenu", "moveFromLeft")
	end
	
	local submitButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )
		if username ~= defaultField.text then updateUser(tostring( defaultField.text )) end		
		defaultField:removeSelf()
		director:changeScene("mainMenu", "moveFromLeft")
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

	local submitButton = ui.newButton{
		default = "btn_achievements.png",
		over = "btn_achievementsA.png",
		onRelease = submitButtonPress,
		emboss = true,
		x = 240,
		y = 280
	}
	submitButton.isVisible = true
	self:insert(submitButton)
	
	function clean()
	end
	
	return self
end