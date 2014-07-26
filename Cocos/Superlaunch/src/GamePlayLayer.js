var GamePlayLayer = cc.Layer.extend({
    space:null,
    spriteSheet:null,
    sprite:null,
    onBackEvent:{},
    frameCheck:{},
    applyBoost:null,
    applyLazars:null,
    character:null,
    start:null,
    timerEvents:{},
    launchType:"slingShot",
    hand:null,
    flame:null,
    totalScore:{},
    timeLeft:100,
    startingSkyX1:-45,
    startingSkyX2:515,
    recognizer:null,

    ctor:function (space) {
        this._super();
        this.space = space;
        this._debugNode = cc.PhysicsDebugNode.create(this.space);
        // Parallax ratio and offset
        this.addChild(this._debugNode, 10);
        this.init();
    },
    init:function(){
        this.initAction();
    },

    initAction:function () {
        this._super();

        //1. create PhysicsSprite with a sprite frame name
        this.character = cc.PhysicsSprite.create(res.aryaSprite_png);
        var contentSize = this.character.getContentSize();
        // 2. init the runner physic body
        this.body = new cp.Body(1, cp.momentForBox(1, contentSize.width, contentSize.height));
        //3. set the position of the runner
        this.body.p = cc.p(g_runnerStartX, g_groundHeight + contentSize.height / 2);
        //4. apply impulse to the body
        this.body.applyImpulse(cp.v(200, 0), cp.v(0, 0));//run speed
        //5. add the created body to space
        this.space.addBody(this.body);
        //6. create the shape for the body
        this.shape = new cp.BoxShape(this.body, contentSize.width - 14, contentSize.height);
        //7. add shape to space
        this.space.addShape(this.shape);
        //8. set body to the physic sprite
        this.character.setBody(this.body);
        this.addChild(this.character);
    },

    fireLazars:function(){
        cc.log("==Lazars Fired");
    },

    fireBoost:function(){
        this.body.applyImpulse(cp.v(10, 0), cp.v(20, 0));
    },

    onExit:function() {
        this.applyBoost.release();
        this.applyLazars.release();
        this._super();
    },

    getEyeX:function () {
        return this.character.getPositionX() - g_runnerStartX;
    },

    getEyeY:function () {
        return this.character.getPositionY() - g_runnerStartY;
    },

    applyImpulses:function (impulses) {
        for (var i = 0; i < impulses.length; i++) {
            this.character.body.applyImpulse(impulses[i][0], impulses[i][1]);
        }
    }
});