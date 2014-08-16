var GamePlayLayer = cc.Layer.extend({
    space:null,
    spriteSheet:null,
    sprite:null,
    onBackEvent:{},
    frameCheck:{},
    applyBoost:null,
    applyLazars:null,
    character:null,
    staticCharacter:null,
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

    ctor:function (space) {
        this._super();
        this.space = space;
        this.init();
    },
    init:function(){
        this.slingshotStart = cc.p(g_characterStartX, (g_characterStartyY / 2) + g_groundHeight);
        this.initAction();
    },

    initAction:function () {
        this._super();

        //Create Slingshot Item
        this.slingshot = cc.PhysicsSprite.create(res.slingshot_png);
        var slingshotBody = new cp.StaticBody();
        slingshotBody.p = this.slingshotStart;
        this.slingshot.setBody(slingshotBody);
        this.addChild(this.slingshot);

        //this.slingshotLeftRope =

        //1. create PhysicsSprite with a sprite frame name
        this.character = cc.PhysicsSprite.create(res.aryaSprite_png);
        var contentSize = this.character.getContentSize();
        // 2. init the runner physic body
        var body = new cp.Body(1, cp.momentForBox(1, contentSize.width, contentSize.height));
        //3. set the position of the runner
        body.p = cc.p(g_characterStartX, g_characterStartyY); //g_groundHeight + contentSize.height / 2);
        //4. add the created body to space
        this.space.addBody(body);
        //5. create the shape for the body
        var shape = new cp.BoxShape(body, contentSize.width - 14, contentSize.height);
        //6. add shape to space
        this.space.addShape(shape);
        //8. set body to the physic sprite
        this.character.setBody(body);
        this.addChild(this.character);

        this.staticCharacter = cc.Sprite.create(res.aryaSprite_png);
        this.staticCharacter.visible = false;
        this.addChild(this.staticCharacter);

        //Create Damped Spring Joint between Character and Slingshot
        //var zeroPoint = cc.p(0,0);
        //this.joint = new cp.DampedSpring(body, slingshotBody, zeroPoint, zeroPoint, 10, 50, 5);
        //this.space.addConstraint(this.joint);
        //this.addChild(this.joint);

        this.slingshotLeftRope = new Rope(this, this.space, 6, slingshotBody, body);
        this.slingshotRightRope = new Rope(this, this.space, 6, slingshotBody, body);


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
        var target = event.getCurrentTarget();
        target.character.visible = false;
        target.staticCharacter.setPosition(pos);
        target.staticCharacter.visible = true;
        target.space.removeConstraint(target.joint);
        target.joint = null;
        return true;
    },

    onTouchMoved:function(touch, event) {
        var pos = touch.getLocation();
        var target = event.getCurrentTarget();
        target.staticCharacter.setPosition(pos);
    },

    onTouchEnded:function(touch, event) {
        //var rtn = event.getCurrentTarget().recognizer.endPoint();
        var pos = touch.getLocation();
        var target = event.getCurrentTarget();
        target.staticCharacter.visible = false;
        target.character.body.setPos(pos);
        target.character.visible = true;
        if ((target.slingshotStart.x - pos.x > 60) || (target.slingshotStart.y - pos.y > 60))
        {
            target.prelaunch = false;
            target.removeChild(target.staticCharacter);
            target.staticCharacter = null;
            var xImpulse = (target.slingshotStart.x + pos.x) * target.slingshotStrength;
            var yImpulse = (target.slingshotStart.y - pos.y) * target.slingshotStrength;
            target.character.body.applyImpulse(cp.v(xImpulse, yImpulse), cp.v(0,0));
            //Remove OnTouch Listener
            cc.eventManager.removeListener(this);
        }
        else if(target.prelaunch == true)
        {
            //Create Damped Spring Joint between Character and Slingshot
            var zeroPoint = cc.p(0,0);
            var target = event.getCurrentTarget();
            target.joint = new cp.DampedSpring(body, target.character.getBody(), zeroPoint, zeroPoint, 10, 50, 5);
            target.space.addConstraint(target.joint);
        }
    }
});