-- Import preloader class
local preloader = require "preloader"

-- Import director class
local director = require("director")

-- Create a main group
local mainGroup = display.newGroup()

-- Main function
local function main()

        -- Add the group from director class
        mainGroup:insert(director.directorView)

        -- Change scene with effects and preloading
        -- The loading screen and final screen will be moved in with the animation you choose
        -- Only preload where necessary! A briefly displayed load screen is annoying to users.
        -- 0.5s delay is recommended as the minimum load time to use preloading for
        
        preloader:changeScene("sceneMainMenu","fade")
        
        return true
end

-- Begin
main()
