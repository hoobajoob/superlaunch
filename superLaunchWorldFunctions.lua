module(..., package.seeall)
function AddSection(physics, worldLength, game)
	worldLength = worldLength + 1
	local addition = 160 + ( (worldLength - 1) * 960 )
	
	local dgrass
	if worldLength > 1 and math.random(5) < 3 then
		dgrass = display.newImage( "lava.png", true )
		dgrass.bodyName = "lava"..worldLength
		dgrass.x = addition; dgrass.y = groundReferencePoint
		physics.addBody( dgrass, "static", { friction=0.7, bounce=0.2 } )
	else
		dgrass = display.newImage( "grass.png", true )
		dgrass.bodyName = "grass"..worldLength
		dgrass.x = addition; dgrass.y = groundReferencePoint
		physics.addBody( dgrass, "static", { friction=0.1, bounce=0.25 } )
	end
	
	game:insert( dgrass )

	if worldLength > 2 then		
		if math.random(5) < 4 then
			if math.random(5) < 4 then
				local trampoline = display.newImage( "ramp.png" )
				trampoline.x = addition + math.random( 40, 920 ); trampoline.y = groundReferencePoint - 40
				trampoline.bodyName = "trampoline"..worldLength
				physics.addBody( trampoline, "static", { friction=0, bounce=6, shape={ 20,0, -20,0, -20,0, 20,0 } } )	
				game:insert( trampoline )		
			else						
				local ramp = display.newImage( "ramp.png" )
				ramp.x = addition + math.random( 40, 920 ); ramp.y = groundReferencePoint - 65
				ramp.bodyName = "ramp"..worldLength
				physics.addBody( ramp, "static", { friction=0, bounce=.2, shape={ 40,25, -40,25, 40,-31 } } )	
				game:insert( ramp )		
			end
		else 
			if math.random(5) <4 then
				local spikeWall = display.newImage( "spikewall.png" )
				spikeWall.x = addition - math.random( 40, 920 ); spikeWall.y = groundReferencePoint - 80
				spikeWall.bodyName = "spikeWall"..worldLength
				physics.addBody( spikeWall, "static", { density=10, friction=1, bounce=0, shape={ -20,-43, 38,40, 22,40, -36,-43 } } )
				game:insert( spikeWall )
			else
				local keg = display.newImage( "keg.png" )
				keg.x = addition - math.random( 40, 920 ); keg.y = groundReferencePoint - 65
				keg.bodyName = "keg"..worldLength
				physics.addBody( keg, "static", { friction=1, bounce=0 } )
				game:insert( keg )
			end
		end
			
		local star = display.newImage( "star.png" )
		star.x = addition + math.random( 40, 920 ); star.y = math.random( -500, 140 )
		star.bodyName = "star"
		physics.addBody( star, "static", { friction=0, bounce=0 } )
		star.isSensor = true
		game:insert( star )
		
		local bacon = display.newImage( "bacon.png" )
		bacon.x = addition + math.random( 40, 920 ); bacon.y = math.random( -500, 140 )
		bacon.bodyName = "bacon"
		physics.addBody( bacon, "static", { friction=0, bounce=0 } )
		bacon.isSensor = true
		game:insert( bacon )
	end
end

function createFirstSection( physics, game )
		
			sky = display.newImage( "sky.png", true )
			game:insert( sky )
			sky:setReferencePoint( display.CenterLeftReferencePoint )
			sky.x = -60; sky.y = 140
			msky = display.newImage( "skymiddle.png", true )
			game:insert( msky )
			msky:setReferencePoint( display.CenterLeftReferencePoint )
			msky.x = -60; msky.y = -180
			tsky = display.newImage( "skytop.png", true )
			game:insert( tsky )
			tsky:setReferencePoint( display.CenterLeftReferencePoint )
			tsky.x = -60; tsky.y = -500
			ttsky = display.newImage( "skytransition.png", true )
			game:insert( ttsky )
			ttsky:setReferencePoint( display.CenterLeftReferencePoint )
			ttsky.x = -60; ttsky.y = -820
			sky2 = display.newImage( "sky.png", true )
			game:insert( sky2 )
			sky2:setReferencePoint( display.CenterLeftReferencePoint )
			sky2.x = 420; sky2.y = 140
			msky2 = display.newImage( "skymiddle.png", true )
			game:insert( msky2 )
			msky2:setReferencePoint( display.CenterLeftReferencePoint )
			msky2.x = 420; msky2.y = -180
			tsky2 = display.newImage( "skytop.png", true )
			game:insert( tsky2 )
			tsky2:setReferencePoint( display.CenterLeftReferencePoint )
			tsky2.x = 420; tsky2.y = -500
			ttsky2 = display.newImage( "skytransition.png", true )
			game:insert( ttsky2 )
			ttsky2:setReferencePoint( display.CenterLeftReferencePoint )
			ttsky2.x = 420; ttsky2.y = -820

			local grass = display.newImage( "grass.png", true )
			game:insert( grass )
			grass.x = 160; grass.y = groundReferencePoint
			physics.addBody( grass, "static", { friction=0.1, bounce=0.25 } )
			grass.bodyName = "grass1"
		end