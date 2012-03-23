module(..., package.seeall)
local ui = require("ui")
local storyboard = require( "storyboard" )
local ls = require( "loadingScreen" )
local backgroundMusicChannel

local scene = storyboard.newScene()

-- Handler that gets notified when the alert closes
local function onQuitComplete( event )
	if "clicked" == event.action then
		local i = event.index
		if 1 == i then							
			native.requestExit()
		end
	end
	return true
end

local function onKeyEvent( event )
	if (event.keyName == "back" and event.phase == "down") then 
		local alert = native.showAlert( "SuperLaunch", "Are you sure you want to exit?", 
									{ "YES", "NO" }, onQuitComplete )
		return true
	end
end	

local function startMusic( )
	if storyboard.playSounds then
		local backgroundMusic = audio.loadStream("soundtrack.mp3")
		backgroundMusicChannel = audio.play( backgroundMusic, { channel=14, loops=-1, fadein=50 }  )  -- play the background music on channel 1, loop infinitely, and fadein over 5 seconds 
	end
end	

local function addKeyEvent()
	print( "adding Key Listener" )
	Runtime:addEventListener( "key", onKeyEvent )
end
	 
--Handle the applicationExit event to close the db
function onSystemEvent( event )
	if( event.type == "applicationExit" ) then              
		db:close()
	end
end
 
--setup the system listener to catch applicationExit
Runtime:addEventListener( "system", onSystemEvent )	
	

-----------------------------------------------------------------------------------------
-- BEGINNING OF YOUR IMPLEMENTATION
-- 
-- NOTE: Code outside of listener functions (below) will only be executed once,
--		 unless storyboard.removeScene() is called.
-- 
-----------------------------------------------------------------------------------------

-- Called when the scene's view does not exist:
function scene:createScene( event )		
	if storyboard.playSounds then
		local introMusic = audio.loadStream("intro.mp3")
		local introMusicChannel = audio.play( introMusic, { channel=1 }  ) 
	end
	local splash = ls.newLoadingScreen{
		srcImage = "splashWIcons.png",
		duration = 3000,
		fadeOut = true
	}
	print("creating mainmenu")
	local group = self.view	
	
	local bg = display.newImage( "background.png", true )
	group:insert( bg )
	
	--Open GameData.sqlite.  If the file doesn't exist it will be created
	local path = system.pathForFile("GameData.sqlite", system.DocumentsDirectory)
	db = sqlite3.open( path )   
	
	--Setup the user table if it doesn't exist
	local tablesetup = [[CREATE TABLE IF NOT EXISTS tblUsers (ixUser INTEGER PRIMARY KEY, sName, fTutorial INTEGER, fLatestUser INTEGER);]]
	db:exec( tablesetup )
	
	local fTutorialExists = false
	local fLatestUserExists = false
	for row in db:nrows("SELECT * FROM tblUsers LIMIT 1") do
		if row.fTutorial ~= nil then fTutorialExists = true end
		if row.fLatestUser ~= nil then fLatestUserExists = true end
	end
	
	if not fTutorialExists then
		print("adding fTutorial column")
		tablesetup = [[ALTER TABLE tblUsers ADD COLUMN fTutorial INTEGER DEFAULT 1 NOT NULL]]
		db:exec( tablesetup )
	end
	if not fLatestUserExists then
		print("adding fLatestUser column")
		tablesetup = [[ALTER TABLE tblUsers ADD COLUMN fLatestUser INTEGER DEFAULT 0 NOT NULL]]
		db:exec( tablesetup )
	end
	
	for row in db:nrows("SELECT ixUser, sName, fTutorial FROM tblUsers WHERE fLatestUser = 1 LIMIT 1") do
		storyboard.userIndex = row.ixUser
		storyboard.userName = row.sName
		if row.fTutorial == 1 then storyboard.tutorialEnabled = true end
	end
	
	if storyboard.userIndex == 0 then	
		for row in db:nrows("SELECT ixUser, sName FROM tblUsers WHERE sName = '"..storyboard.userName.."' LIMIT 1") do
			storyboard.userIndex = row.ixUser 
		end
		local tablefill = [[UPDATE tblUsers SET fLatestUser = 1 WHERE ixUser = ]]..storyboard.userIndex..[[;]]
		db:exec( tablefill )
	end
	
	if storyboard.userIndex == 0 then		
		local tablefill = [[INSERT INTO tblUsers VALUES (NULL, ']]..storyboard.userName..[[', 1, 1);]]
		db:exec( tablefill )
		for row in db:nrows("SELECT ixUser, sName FROM tblUsers WHERE sName = '"..storyboard.userName.."' LIMIT 1") do
			storyboard.userIndex = row.ixUser 
		end
		storyboard.tutorialEnabled = true
	end
	
	if storyboard.userIndex == 0 then print( "Database Error: Failed to retrieve User Information" ) end
	
	local playButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )
		storyboard.arguments = "superLaunch"
		storyboard.gotoScene("timedModeMain")
	end
	local soundButton
	
	local soundButtonPress = function( event )
		if event.phase =="began" then
			if storyboard.playSounds == true then
				audio.stop()
				storyboard.playSounds = false
				soundButton = display.newImage( "soundOffButton.png", true )
				group:insert(soundButton)
				soundButton.x = 460; soundButton.y = 300
			else
				storyboard.playSounds = true
				startMusic()
				soundButton:removeSelf()
				soundButton = display.newImage( "soundButton.png", true )
				group:insert(soundButton)
				soundButton.x = 460; soundButton.y = 300
			end
		end
	end
	
	soundButton = display.newImage( "soundButton.png", true )
	soundButton.x = 460; soundButton.y = 300
	soundButton:addEventListener ( "touch", soundButtonPress )
	
	local loginButtonPress = function( event )
		storyboard.gotoScene("localLogin")
	end
	
	local highScoresButtonPress = function( event )
		storyboard.gotoScene("highScores")
	end
	
	local helpButtonPress = function( event )
		ads.hide()
		storyboard.gotoScene("help")
	end
	
	local playButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				x = 240,
				y = 90,
				overSrc = "buttonRedOver.png",
				onRelease = playButtonPress,
				text = "Play",
				emboss = true
			}
	playButton.isVisible = true
	
	local loginButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				x = 240,
				y = 150,
				overSrc = "buttonRedOver.png",
				onRelease = loginButtonPress,
				text = "Login",
				emboss = true
			}
	loginButton.isVisible = true	
	
	local highScoresButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				x = 240,
				y = 210,
				overSrc = "buttonRedOver.png",
				onRelease = highScoresButtonPress,
				text = "High Scores and Achievements",
				emboss = true
			}
	highScoresButton.isVisible = true
	
	local helpButton = ui.newButton{
				defaultSrc = "buttonRed.png",
				x = 240,
				y = 270,
				overSrc = "buttonRedOver.png",
				onRelease = helpButtonPress,
				text = "Help",
				emboss = true
			}
	helpButton.isVisible = true

	function moveBack(where, how, arguments)
		storyboard.arguments = arguments
		storyboard.gotoScene(where, how)
	end
	
	-- all display objects must be inserted into group
	group:insert(playButton)
	group:insert(loginButton)
	group:insert(highScoresButton)
	group:insert(helpButton)
	group:insert(soundButton)
	
	splash.loadingFinished()
end

-- Called immediately after scene has moved onscreen:
function scene:enterScene( event )
	print("entering mainmenu")
	
	-- INSERT code here (e.g. start timers, load audio, start listeners, etc.)
	local group = self.view
	storyboard.removeScene( "superLaunch" )
	-- Add the back key callback
	timer.performWithDelay( 1, addKeyEvent )
	timer.performWithDelay( 6500, startMusic )
	
	-- iPhone, iPod touch, iPad, android etc
	ads.show( "banner", { x=0, y=0, interval=10 } )
end

-- Called when scene is about to move offscreen:
function scene:exitScene( event )
	local group = self.view
	Runtime:removeEventListener( "key", onKeyEvent )
	
	-- INSERT code here (e.g. stop timers, remove listenets, unload sounds, etc.)
	
end

-- If scene's view is removed, scene:destroyScene() will be called just prior to:
function scene:destroyScene( event )
	local group = self.view
	Runtime:removeEventListener( "key", onKeyEvent )
end

-----------------------------------------------------------------------------------------
-- END OF YOUR IMPLEMENTATION
-----------------------------------------------------------------------------------------

-- "createScene" event is dispatched if scene's view does not exist
scene:addEventListener( "createScene", scene )

-- "enterScene" event is dispatched whenever scene transition has finished
scene:addEventListener( "enterScene", scene )

-- "exitScene" event is dispatched whenever before next scene's transition begins
scene:addEventListener( "exitScene", scene )

-- "destroyScene" event is dispatched before view is unloaded, which can be
-- automatically unloaded in low memory situations, or explicitly via a call to
-- storyboard.purgeScene() or storyboard.removeScene().
scene:addEventListener( "destroyScene", scene )

-----------------------------------------------------------------------------------------

return scene