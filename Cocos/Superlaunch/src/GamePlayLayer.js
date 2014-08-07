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
    _debugNode:null,
    prelaunch:true,

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

        //Create Slingshot Item
        /*var slingshot = cc.PhysicsSprite.create(res.ramp_png);
        var slingshotBody = new cp.Body(1, cp.momentForBox(1, 10, g_characterStartyY - g_groundHeight));
        slingshotBody.p = cc.p(g_characterStartX, (g_characterStartyY / 2) + g_groundHeight + 100);
        slingshotBody.setMass(1000);
        this.space.addBody(slingshotBody);
        var slingshotShape = new cp.BoxShape(slingshotBody, 10, g_characterStartyY - g_groundHeight);
        this.space.addShape(slingshotShape);
        slingshot.setBody(slingshotBody);
        this.addChild(slingshot);*/

        //1. create PhysicsSprite with a sprite frame name
        this.character = cc.PhysicsSprite.create(res.aryaSprite_png);
        var contentSize = this.character.getContentSize();
        // 2. init the runner physic body
        var body = new cp.Body(1, cp.momentForBox(1, contentSize.width, contentSize.height));
        //3. set the position of the runner
        body.p = cc.p(g_characterStartX, g_characterStartyY); //g_groundHeight + contentSize.height / 2);
        //4. apply impulse to the body
        //body.applyImpulse(cp.v(300, 0), cp.v(0, 0));//run speed
        //5. add the created body to space
        this.space.addBody(body);
        //6. create the shape for the body
        var shape = new cp.BoxShape(body, contentSize.width - 14, contentSize.height);
        //7. add shape to space
        this.space.addShape(shape);
        //8. set body to the physic sprite
        this.character.setBody(body);
        this.addChild(this.character);

        //Create Damped Spring Joint between Character and Slingshot
        //var zeroPoint = slingshotBody.p;
        //var joint = new cp.DampedSpring(slingshotBody, body, zeroPoint, zeroPoint, 10, 100, 10);
        //this.space.addConstraint(joint);
        //this.addChild(joint);

        cc.eventManager.addListener({
            event: cc.EventListener.TOUCH_ONE_BY_ONE,
            swallowTouches: true,
            onTouchBegan: this.onTouchBegan,
            onTouchMoved: this.onTouchMoved,
            onTouchEnded: this.onTouchEnded
        }, this);
    },

    fireLazars:function(){
        cc.log("==Lazars Fired");
    },

    fireBoost:function(){
        this.character.body.applyImpulse(cp.v(10, 0), cp.v(20, 0));
    },

    onExit:function() {
        this.applyBoost.release();
        this.applyLazars.release();
        this._super();
    },

    getEyeX:function () {
        return this.character.getPositionX() - g_characterStartX;
    },

    getEyeY:function () {
        return this.character.getPositionY() - g_characterStartyY;
    },

    getVelocity:function() {
        return this.character.body.getVel();
    },

    getPrelaunchStatus:function(){
        return this.prelaunch;
    },

    applyImpulses:function (impulses) {
        for (var i = 0; i < impulses.length; i++) {
            this.character.body.applyImpulse(impulses[i][0], impulses[i][1]);
        }
    },

    onTouchBegan:function(touch, event) {
        var pos = touch.getLocation();
        event.getCurrentTarget().character.body.setPos(pos);
        return true;
    },

    onTouchMoved:function(touch, event) {
        var pos = touch.getLocation();
        event.getCurrentTarget().character.body.setPos(pos);
    },

    onTouchEnded:function(touch, event) {
        //var rtn = event.getCurrentTarget().recognizer.endPoint();
        event.getCurrentTarget().prelaunch = false;
    }
});