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
        this.gamePlayLayer = new GamePlayLayer(this.space)
        this.gameLayer.addChild(this.gamePlayLayer, 0, TagOfLayer.GamePlay);
        this.addChild(this.gameLayer);
        this.statusLayer = new StatusLayer(this.gameLayer.getChildByTag(TagOfLayer.GamePlay));
        this.addChild(this.statusLayer, 0, TagOfLayer.Status);
        this.shapesToRemove = [];
        this.scheduleUpdate();
    },

    // init space of chipmunk
    initPhysics:function() {
        //1. new space object
        this.space = new cp.Space();
        //2. setup the  Gravity
        this.space.gravity = cp.v(0, -350);

        // 3. set up Walls
        var wallBottom = new cp.SegmentShape(this.space.staticBody,
            cp.v(0, g_groundHeight),// start point
            cp.v(4294967295, g_groundHeight),// MAX INT:4294967295
            0);// thickness of wall
        this.space.addStaticShape(wallBottom);

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
    },

    collisionStarBegin:function (arbiter, space) {
        var shapes = arbiter.getShapes();
        // shapes[0] is character
        //TODO:Find a way to pass the shape directly from handler
        this.impulsesToApply.push([cp.v(100,200), cp.v(-2,0)]);
        this.shapesToRemove.push(shapes[1]);
    },

    collisionBaconBegin:function (arbiter, space) {
        cc.log("==game over");
    },

    update:function(dt) {
        //chipmunk step
        this.space.step(dt);

        // Simulation cpSpaceAddPostStepCallback
        for(var i = 0; i < this.shapesToRemove.length; i++) {
            var shape = this.shapesToRemove[i];
            this.gameLayer.getChildByTag(TagOfLayer.Background).removeObjectByShape(shape);
        }
        this.shapesToRemove = [];

        this.gameLayer.getChildByTag(TagOfLayer.GamePlay).applyImpulses(this.impulsesToApply);
        this.impulsesToApply = [];
        var gamePlayLayer = this.gameLayer.getChildByTag(TagOfLayer.GamePlay);
        var eyeX = gamePlayLayer.getEyeX();
        var newX = 30 - eyeX;
        var eyeY = gamePlayLayer.getEyeY();
        var newY = -45
        if (eyeY > 200)
        {
            newY = 155 - eyeY;
        }

        if (this.gamePlayLayer.getPrelaunchStatus() == false)
        {
            //Move Camera to follow player
            this.gameLayer.setPosition(cc.p(newX,newY));
            //Update Distance Label
            this.statusLayer.updateDistance(eyeX);
        }
    }
});