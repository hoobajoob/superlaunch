var GameOverLayer = cc.LayerColor.extend({
    ctor:function () {
        this._super();
        this.init();
    },
    init:function () {
        //this._super(cc.c4b(0, 0, 0, 180));
        var winSize = cc.director.getWinSize();

        var centerPos = cc.p(winSize.width / 2, winSize.height / 2);
        cc.MenuItemFont.setFontSize(30);
        var menuItemRestart = cc.MenuItemSprite.create(
            cc.Sprite.create(res.restart_n),
            cc.Sprite.create(res.restart_s),
            this.onRestart, this);
        var menu = cc.Menu.create(menuItemRestart);
        menu.setPosition(centerPos);
        this.addChild(menu);
    },
    onRestart:function (sender) {
        cc.director.resume();
        cc.director.runScene(new PlayScene());
    }
});