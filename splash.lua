module(..., package.seeall)

function new()
	local result = display.newGroup()
	local splashImage = display.newImage( "splash.jpg" )
	return result
end