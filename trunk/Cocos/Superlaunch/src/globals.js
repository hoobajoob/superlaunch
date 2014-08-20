var g_groundHeight = 150;
var g_characterStartX = 180;
var g_characterStartyY = 300;
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
    SpriteTag.grass = 5;
    SpriteTag.lava = 6;
    SpriteTag.quickSand = 7;
    SpriteTag.bomb = 8;
    SpriteTag.jetRefill = 9;
};