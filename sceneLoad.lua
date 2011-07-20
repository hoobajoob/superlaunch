-- Your Loading Scene
-- This is displayed while the next scene loads
-- You can customize it at will as long as it returns a localGroup for director

module(..., package.seeall)

-- Main function - MUST return a display.newGroup()
function new()
        local localGroup = display.newGroup()
        
        -- Code Start --
        
        local text = display.newText("Loading...", 0, 0, native.systemFont, 90)
        text:setTextColor(255,255,255)
        localGroup:insert(text)
        text.x = display.contentWidth / 2
        text.y = display.contentHeight / 2
        
        -- Code End --

        return localGroup
end