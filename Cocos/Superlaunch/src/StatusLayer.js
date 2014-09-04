var StatusLayer = cc.Layer.extend({
    labelTime:null,
    labelDistance:null,
    lifeBar:null,
    boostBar:null,
    lazarBar:null,
    coins:0,
    life:100,
    boost:100,
    lazar:100,
    lifeLabel:"Life",
    timeLabel:"Time:",
    distanceLabel:"Meters",
    boostLabel:"Boost",
    lazarLabel:"Lazar",
    lazarButton:null,
    lazarButtonX:430,
    lazarButtonY:70,
    lazarButtonAlpha:.5,
    boostButton:null,
    boostButtonX:50,
    boostButtonY:70,
    boostButtonAlpha:.5,
    gamePlayLayer:null,
    touchPos:null,
    boostOn:false,
    lazarOn:false,

    ctor:function (gamePlayLayer) {
        this._super();
        this.gamePlayLayer = gamePlayLayer;
        this.init();
    },

    init:function () {
        this._super();

        var winsize = cc.director.getWinSize();

        this.labelTime = cc.LabelTTF.create(this.timeLabel + "100", "Helvetica", 20);
        this.labelTime.setColor(cc.color(0,0,0));//black color
        this.labelTime.setPosition(cc.p(70, winsize.height - 20));
        this.addChild(this.labelTime);

        this.labelDistance = cc.LabelTTF.create("0" + this.distanceLabel, "Helvetica", 20);
        this.labelDistance.setPosition(cc.p(winsize.width - 70, winsize.height - 20));
        this.addChild(this.labelDistance);

        this.lifeBar = cc.LabelTTF.create(this.life + this.lifeLabel, "Helvetica", 20);
        this.lifeBar.setPosition(cc.p(winsize.width / 2, 20));
        this.addChild(this.lifeBar);

        //create Lazar Button and assign onPlay event callback to it
        /*var boostMenuItem= cc.MenuItemSprite.create(
            cc.Sprite.create(res.jetPack),
            cc.Sprite.create(res.jetPackOver),
            this.fireBoost(), this
        );
        this.boostButton = cc.Menu.create(boostMenuItem);*/
        this.boostButton = cc.Sprite.create(res.jetPack_png);
        this.boostButton.setPosition({x:this.boostButtonX, y:this.boostButtonY, a:this.boostButtonAlpha});
        this.addChild(this.boostButton);

        this.boostBar = cc.LabelTTF.create(this.boost + this.boostLabel, "Helvetica", 20);
        this.boostBar.setPosition(cc.p(70 , 20));
        this.addChild(this.boostBar);

        //create Lazar Button
        this.lazarButton = cc.Sprite.create(res.lazarGun_png);
        this.lazarButton.setPosition({x:this.lazarButtonX, y:this.lazarButtonY, a:this.lazarButtonAlpha});
        this.addChild(this.lazarButton);

        this.lazarBar = cc.LabelTTF.create(this.lazar + this.lazarLabel, "Helvetica", 20);
        this.lazarBar.setPosition(cc.p(winsize.width - 70, 20));
        this.addChild(this.lazarBar);

        cc.eventManager.addListener({
            event: cc.EventListener.TOUCH_ONE_BY_ONE,
            swallowTouches: true,
            onTouchBegan: this.onTouchBegan,
            onTouchEnded: this.onTouchEnded
        }, this);
    },

    fireBoost:function(){
        cc.log("==Boost Fired");
        this.gamePlayLayer.fireBoost();
    },

    fireLazars:function(){
        cc.log("==Lazars Fired");
        this.gamePlayLayer.fireLazars();
    },

    updateDistance:function (pixels){
        this.labelDistance.setString(parseInt(pixels / 10) + this.distanceLabel);
    },

    updateTime:function (timeRemaining) {
        this.labelTime.setString(this.timeLabel + parseInt(timeRemaining));
    },

    updateLife:function (change) {
        this.life = this.life + parseInt(change);
        if (this.life > 100)
        {
            this.life = 100;
        }
        else if (this.life < 0)
        {
            this.life = 0;
        }
        this.lifeBar.setString(this.life + this.lifeLabel);
    },

    getLife:function(){
        return this.life;
    },

    updateBoost:function (change) {
        this.boost = this.boost + parseInt(change);
        if (this.boost > 100)
        {
            this.boost = 100;
        }
        else if (this.boost < 0)
        {
            this.boost = 0;
        }
        this.boostBar.setString(this.boost + this.boostLabel);
    },

    getBoost:function(){
        return this.boost;
    },

    updateLazar:function (change) {
        this.lazar = this.lazar + parseInt(change);
        if (this.lazar > 100)
        {
            this.lazar = 100;
        }
        else if (this.lazar < 0)
        {
            this.lazar = 0;
        }
        this.lazarBar.setString(this.lazar + this.lazarLabel);
    },
    onTouchBegan:function(touch, event) {
        var target = event.getCurrentTarget();
        target.touchPos = touch.getLocation();
        var boostDiffX = target.boostButtonX - target.touchPos.x;
        var boostDiffY = target.boostButtonY - target.touchPos.y;
        if ( -20 < boostDiffX && boostDiffX < 20 && -20 < boostDiffY  && boostDiffY< 20)
        {
            target.boostOn = true;
        }
        var lazarDiffX = target.lazarButtonX - target.touchPos.x;
        var lazarDiffY = target.lazarButtonY - target.touchPos.y;
        if ( -20 < lazarDiffX && lazarDiffX < 20 && -20 < lazarDiffY  && lazarDiffY< 20)
        {
            target.lazarOn = true;
        }
        return true;
    },

    onTouchEnded:function(touch, event) {
        var target = event.getCurrentTarget();
        target.touchPos = touch.getLocation();
        var boostDiffX = target.boostButtonX - target.touchPos.x;
        var boostDiffY = target.boostButtonY - target.touchPos.y;
        if ( -20 < boostDiffX && boostDiffX < 20 && -20 < boostDiffY  && boostDiffY< 20)
        {
            target.boostOn = false;
        }
        var lazarDiffX = target.lazarButtonX - target.touchPos.x;
        var lazarDiffY = target.lazarButtonY - target.touchPos.y;
        if ( -20 < lazarDiffX && lazarDiffX < 20 && -20 < lazarDiffY  && lazarDiffY< 20)
        {
            target.lazarOn = false;
        }
        return true;
    },

    getBoostStatus:function()
    {
        return (this.boost > 0 && this.boostOn);
    },

    getLazarStatus:function()
    {
        return this.lazarOn;
    }
});