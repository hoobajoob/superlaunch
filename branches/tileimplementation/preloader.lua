module(..., package.seeall)

-- Your loading Scene
local loadingScene = "sceneLoad"

function preloader:changeScene(nextLoadScene, effect, arg1, arg2, arg3)
        director:changeScene(loadingScene,effect,arg1,arg2,arg3)
        
        local function finalLoad ()
                director:changeScene(nextLoadScene,effect,arg1,arg2,arg3)
        end
        timer.performWithDelay(210,finalLoad)
end