var g_groundHeight = 57;
var g_runnerStartX = 80;
if(typeof TagOfLayer == "undefined") {
    var TagOfLayer = {};
    TagOfLayer.Background = 0;
    TagOfLayer.GamePlay = 1;
    TagOfLayer.Status = 2;
};

// collision type for chipmunk
if(typeof SpriteTag == "undefined") {
    var SpriteTag = {};
    SpriteTag.character = 0;
    SpriteTag.star = 1;
    SpriteTag.bacon = 2;
    SpriteTag.keg = 3;
    SpriteTag.ramp = 4;
};