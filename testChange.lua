module(..., package.seeall)

function new( arguments )
	local self = display.newGroup()

	self.back = display.newRect(self, 0, 0, display.contentWidth, display.contentHeight)
		
	local topBoundary = display.screenOriginY
	local bottomBoundary = display.screenOriginY
	function clean()
	end
	director:changeScene("noahLauncher", "crossFade", arguments)
	return self
end