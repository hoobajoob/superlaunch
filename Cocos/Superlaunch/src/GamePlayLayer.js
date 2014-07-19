var GamePlayLayer = cc.Layer.extend({
    space:null,
    spriteSheet:null,
    runningAction:null,
    sprite:null,
    onBackEvent:{},
    frameCheck:{},
    applyJetpackBoost:{},
    applyLazars:{},
    endJets:null,
    endLazars:null,
    character:null,
    start:null,
    timerEvents:{},
    launchType:"slingShot",
    mainCharacter:null,
    hand:null,
    flame:null,
    startingSkyX1:-45,
    startingSkyX2:515,

    ctor:function (space) {
        this._super();
        this.space = space;
        this.init();
    },
    init:function () {
        this._super();


        //load spritesheet
        cc.spriteFrameCache.addSpriteFrames(res.aryaSprite_plist);
        this.spriteSheet = cc.SpriteBatchNode.create(res.aryaSprite_png);
        this.addChild(this.spriteSheet);

        //create spriteframe array
        var animFrames = [];
        for (var i = 0; i < 4; i++) {
            var str = "arya" + i + ".png";
            var frame = cc.spriteFrameCache.getSpriteFrame(str);
            animFrames.push(frame);
        }
        //3.create a animation with the spriteframe array along with a period time
        var animation = cc.Animation.create(animFrames, 0.2);

        //4.wrap the animate action with a repeat forever action
        this.runningAction = cc.RepeatForever.create(cc.Animate.create(animation));
        this.sprite = cc.Sprite.create(res.aryaSprite_png);
        this.sprite.attr({x:66, y:68});
        this.sprite.runAction(this.runningAction);

        //1. create PhysicsSprite with a sprite frame name
        this.sprite = cc.PhysicsSprite.create(res.aryaSprite_png);
        var contentSize = this.sprite.getContentSize();
        // 2. init the runner physic body
        this.body = new cp.Body(1, cp.momentForBox(1, contentSize.width, contentSize.height));
        //3. set the position of the runner
        this.body.p = cc.p(g_runnerStartX, g_groundHeight + contentSize.height / 2);
        //4. apply impulse to the body
        this.body.applyImpulse(cp.v(10, 0), cp.v(0, 0));//run speed
        //5. add the created body to space
        this.space.addBody(this.body);
        //6. create the shape for the body
        this.shape = new cp.BoxShape(this.body, contentSize.width - 14, contentSize.height);
        //7. add shape to space
        this.space.addShape(this.shape);
        //8. set body to the physic sprite
        this.sprite.setBody(this.body);
        this.spriteSheet.addChild(this.sprite);
    },

    createRandomScene:function () {
        cc.log("Creating Random Scene");

    }
});