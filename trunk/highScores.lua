module(..., package.seeall)

function new()
	local self = display.newGroup()	

	local bg = display.newImage( "background.png", true )
	self:insert( bg )	

	-- Handler that gets notified when the alert closes
	local function onQuitComplete( event )
			if "clicked" == event.action then
					local i = event.index
					if 1 == i then							
						native.requestExit()
					elseif 2 == i then
						-- Do nothing; dialog will simply dismiss
					end
			end
	end
		
	-- Back Key listener
	local function onKeyEvent( event )
		local phase = event.phase
		local keyName = event.keyName
		
		-- Show alert with five buttons
		if (keyName == "back") then 
			local alert = native.showAlert( "SuperLaunch", "Are you sure you want to exit?", 
										{ "YES", "NO" }, onQuitComplete )
		else			
			local alert = native.showAlert( "SuperLaunch", "You pressed the "..keyName.." button.", 
										{ "YES", "NO" } )
		end
		return true
	end
	
	local openFeintButtonPress = function( event )
		gameNetwork.show("leaderboards")
	end
	
	local achievementsButtonPress = function( event )
		gameNetwork.show("achievements")
	end
	
	local localButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent );
		director:changeScene("localHighScores", "moveFromRight")
	end
	
	local openFeintButton = ui.newButton{
		default = "btn_leaderboard.png",
		over = "btn_leaderboardA.png",
		onRelease = openFeintButtonPress,
		emboss = true,
		x = 80,
		y = 280
	}
	openFeintButton.isVisible = true
	self:insert(openFeintButton)

	local achievementsButton = ui.newButton{
		default = "btn_achievements.png",
		over = "btn_achievementsA.png",
		onRelease = achievementsButtonPress,
		emboss = true,
		x = 240,
		y = 280
	}
	achievementsButton.isVisible = true
	self:insert(achievementsButton)
	
	local localButton = ui.newButton{
				default = "btn_localHS.png",
				over = "btn_localHSA.png",
				onPress = localButtonPress,
				emboss = true,
				x = 400,
				y = 280
			}			
	localButton.isVisible = true
	self:insert(localButton)
	
	local backButtonPress = function( event )
		Runtime:removeEventListener( "key", onKeyEvent )		
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
	
	function clean()
	end
	
	return self
end