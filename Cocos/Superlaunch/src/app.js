
var MenuLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();
    },
    init : function(){
        //call super class's super function
        this._super();

        //2. get screen size of game canvas
        var winsize = cc.director.getWinSize();

        //calculate center point
        var centerpos = cc.p(winsize.width / 2, winsize.height / 2);

        //create background image and set it's pos to center of screen
        var spritebg = cc.Sprite.create(res.HelloWorld_png);
        spritebg.setPosition(centerpos);
        this.addChild(spritebg);

        //set font size
        cc.MenuItemFont.setFontSize(60);

        //create menu and assign onPlay event callback to it
        var menuItemPlay= cc.MenuItemSprite.create(
            cc.Sprite.create(res.CloseNormal_png),
            cc.Sprite.create(res.CloseSelected_png),
            this.onPlay, this
        );
        var menu = cc.Menu.create(menuItemPlay);
        menu.setPosition(centerpos);
        this.addChild(menu);
    },

    onPlay : function(){
        cc.log("==onPlay clicked");
        cc.director.runScene(new PlayScene());
    }
});

var MenuScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new MenuLayer();
        layer.init();
        this.addChild(layer);
    }
});

