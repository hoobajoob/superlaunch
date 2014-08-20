var PlayScene = cc.Scene.extend({
    space:null,
    statusLayer:null,
    gameLayer:null,
    gamePlayLayer:null,
    shapesToRemove:[],
    impulsesToApply:[],

    onEnter:function () {
        this._super();
        this.initPhysics();
        this.gameLayer = cc.Layer.create();
        //add the three layers in the correct order
        this.gameLayer.addChild(new BackgroundLayer(this.space), 0, TagOfLayer.Background);
        this.gamePlayLayer = new GamePlayLayer(this.space);
        this.gameLayer.addChild(this.gamePlayLayer, 0, TagOfLayer.GamePlay);
        this.addChild(this.gameLayer);
        this.statusLayer = new StatusLayer(this.gameLayer.getChildByTag(TagOfLayer.GamePlay));
        this.addChild(this.statusLayer, 0, TagOfLayer.Status);
        this.shapesToRemove = [];
        //randomize math
        Math.random();
        this.scheduleUpdate();
    },

    // init space of chipmunk
    initPhysics:function() {
        //1. new space object
        this.space = new cp.Space();
        this._debugNode = cc.PhysicsDebugNode.create(this.space);
        // Parallax ratio and offset
        this.addChild(this._debugNode, 10);
        //2. setup the  Gravity
        this.space.gravity = cp.v(0, -350);

        var wallBack = new cp.SegmentShape(this.space.staticBody,
            cp.v(0, g_groundHeight),// start point
            cp.v(0, 1000),
            0);// thickness of wall
        this.space.addStaticShape(wallBack);

        // setup chipmunk CollisionHandler
        this.space.addCollisionHandler(SpriteTag.character, SpriteTag.star,
            this.collisionStarBegin.bind(this), null, null, null);
        this.space.addCollisionHandler(SpriteTag.character, SpriteTag.bacon,
            this.collisionBaconBegin.bind(this), null, null, null);
        this.space.addCollisionHandler(SpriteTag.character, SpriteTag.bomb,
            this.collisionBombBegin.bind(this), null, null, null);
        this.space.addCollisionHandler(SpriteTag.character, SpriteTag.jetRefill,
            this.collisionJetRefillBegin.bind(this), null, null, null);
    },

    collisionStarBegin:function (arbiter, space) {
        var shapes = arbiter.getShapes();
        // shapes[0] is character
        //TODO:Find a way to pass the shape directly from handler
        this.impulsesToApply.push([cp.v(50,300), cp.v(-2,0)]);
        this.shapesToRemove.push(shapes[1]);
        cc.log("==Hit Star");
    },

    collisionBaconBegin:function (arbiter, space) {
        var shapes = arbiter.getShapes();
        // shapes[0] is character
        //TODO:Find a way to pass the shape directly from handler
        this.impulsesToApply.push([cp.v(20,50), cp.v(-2,0)]);
        this.shapesToRemove.push(shapes[1]);
        //TODO: Adjust Health
        cc.log("==Hit Bacon");
    },

    collisionBombBegin:function (arbiter, space) {
        var shapes = arbiter.getShapes();
        // shapes[0] is character
        //TODO:Find a way to pass the shape directly from handler
        this.impulsesToApply.push([cp.v(-200,-200), cp.v(-2,0)]);
        this.shapesToRemove.push(shapes[1]);
        //TODO: Adjust Health
        cc.log("==Hit Bomb");
    },

    collisionJetRefillBegin:function (arbiter, space) {
        var shapes = arbiter.getShapes();
        this.shapesToRemove.push(shapes[1]);
        //TODO: Adjust Boost Level
        cc.log("==Hit Jet Refill");
    },

    update:function(dt) {
        //chipmunk step
        this.space.step(dt);

        var gamePlayLayer = this.gameLayer.getChildByTag(TagOfLayer.GamePlay);

        if (this.gamePlayLayer.getPrelaunchStatus() == true)
        {
            gamePlayLayer.moveCharacterToTouch();
        }
        else
        {
            gamePlayLayer.applyImpulses(this.impulsesToApply);
            this.impulsesToApply = [];
            var backgroundLayer = this.gameLayer.getChildByTag(TagOfLayer.Background);
            // Simulation cpSpaceAddPostStepCallback
            for(var i = 0; i < this.shapesToRemove.length; i++) {
                var shape = this.shapesToRemove[i];
                backgroundLayer.removeObjectByShape(shape);
            }
            this.shapesToRemove = [];
            var eyeX = gamePlayLayer.getEyeX();
            var newX = 30 - eyeX;
            var eyeY = gamePlayLayer.getEyeY();
            var newY = -45
            if (eyeY > 0)
            {
                newY = (-45) - eyeY;
            }
            //Move Camera to follow player
            this.gameLayer.setPosition(cc.p(newX,newY));
            //Update Distance Label
            if(gamePlayLayer.getVelocity().x > 0 && eyeX > 0)
            {
                this.statusLayer.updateDistance(eyeX);
            }
        }
    }
});