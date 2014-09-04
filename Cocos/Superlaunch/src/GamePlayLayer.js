var GamePlayLayer = cc.Layer.extend({
    space:null,
    spriteSheet:null,
    sprite:null,
    onBackEvent:{},
    frameCheck:{},
    applyBoost:null,
    applyLazars:null,
    character:null,
    slingshot:null,
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
    joint:null,
    slingshotStart:null,
    slingshotStrength:5,
    slingshotLeftRope:null,
    slingshotRightRope:null,
    stepListener:null,
    touchPos:null,

    ctor:function (space) {
        this._super();
        this.space = space;
        this.init();
    },
    init:function(){
        this.slingshotStart = cc.p(g_characterStartX, (g_characterStartY / 2) + g_groundHeight / 2);
        this.initAction();
    },

    initAction:function () {
        this._super();

        //Create Slingshot Item
        this.slingshot = cc.PhysicsSprite.create(res.slingshot_png);
        var slingshotBody = new cp.StaticBody();
        slingshotBody.p = this.slingshotStart;
        this.slingshot.setBody(slingshotBody);
        //var contentSize = this.slingshot.getContentSize();
        //var shape = new cp.BoxShape(slingshotBody, contentSize.width, contentSize.height);
        //this.space.addShape(shape);
        this.addChild(this.slingshot);


        //1. create PhysicsSprite with a sprite frame name
        this.character = cc.PhysicsSprite.create(res.aryaSprite_png);
        var contentSize = this.character.getContentSize();
        // 2. init the runner physic body
        var body = new cp.Body(1, cp.momentForBox(1, contentSize.width, contentSize.height));
        //3. set the position of the runner
        body.p = cc.p(g_characterStartX, g_characterStartY); //g_groundHeight + contentSize.height / 2);
        //4. add the created body to space
        this.space.addBody(body);
        //5. create the shape for the body
        var shape = new cp.BoxShape(body, contentSize.width - 14, contentSize.height);
        shape.setElasticity(0);
        //shape.setMass(2.2);
        shape.setFriction(.5);
        body.setMoment(Infinity);
        //6. add shape to space
        this.space.addShape(shape);
        //8. set body to the physic sprite
        this.character.setBody(body);
        this.addChild(this.character);

        this.slingshotLeftRope = new Rope(this, this.space, 0, body, slingshotBody, body.p);
        //this.slingshotLeftRope = new cp.SlideJoint(body, slingshotBody, cc.p(0,0), cc.p(0,0), 1, 5);
        //this.space.addConstraint(this.slingshotLeftRope);


        cc.eventManager.addListener({
            event: cc.EventListener.TOUCH_ONE_BY_ONE,
            swallowTouches: true,
            onTouchBegan: this.onTouchBegan,
            onTouchMoved: this.onTouchMoved,
            onTouchEnded: this.onTouchEnded
        }, this);
        if (g_debugAutoLaunch){this.autoLaunch();}
    },

    fireLazars:function(){
        //TODO:Implement Lazar Firing
    },

    fireBoost:function(){
        this.character.body.applyImpulse(cp.v(10, 10), cp.v(20, 0));
    },

    onExit:function() {
        this._super();
    },

    getEyeX:function () {
        return this.character.getPositionX() - g_characterStartX;
    },

    getEyeY:function () {
        return this.character.getPositionY() - g_characterStartY;
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

    moveCharacterToTouch:function(){
        if (this.touchPos != null)
        {
            this.character.setPosition(this.touchPos);
        }
    },

    onTouchBegan:function(touch, event) {
        var target = event.getCurrentTarget();
        target.touchPos = touch.getLocation();
        target.character.setPosition(target.touchPos);
        return true;
    },

    onTouchMoved:function(touch, event) {
        var target = event.getCurrentTarget();
        target.touchPos = touch.getLocation();
        target.character.setPosition(target.touchPos);
    },

    onTouchEnded:function(touch, event) {
        //var rtn = event.getCurrentTarget().recognizer.endPoint();
        var target = event.getCurrentTarget();
        target.touchPos = touch.getLocation();
        target.character.body.setPos(target.touchPos);
        if ((target.slingshotStart.x - target.touchPos.x > 60) || (target.slingshotStart.y - target.touchPos.y > 60))
        {
            target.touchPos = null;
            target.prelaunch = false;
            //var xImpulse = (target.slingshotStart.x + pos.x) * target.slingshotStrength;
            //var yImpulse = (target.slingshotStart.y - pos.y) * target.slingshotStrength;
            //target.character.body.applyImpulse(cp.v(xImpulse, yImpulse), cp.v(0,0));
            target.slingshotLeftRope.disconnectFromCharacter();
            target.removeChild(target.slingshotLeftRope);
            target.slingshotLeftRope = null;
            //Remove OnTouch Listener
            cc.eventManager.removeListener(this);
        }
    },

    autoLaunch:function(){
        this.prelaunch = false;
        this.slingshotLeftRope.disconnectFromCharacter();
        this.removeChild(this.slingshotLeftRope);
        this.slingshotLeftRope = null;
        this.character.body.applyImpulse(cc.p(1000, 200), cc.p(0,0));
        cc.eventManager.removeAllListeners();
    }
});