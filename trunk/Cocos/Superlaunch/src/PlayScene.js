var PlayScene = cc.Scene.extend({
    space:null,
    gamePlayLayer:null,
    gameLayer:null,
    shapesToRemove:[],

    onEnter:function () {
        this._super();
        this.initPhysics();
        this.gameLayer = cc.Layer.create();
        //add the three layers in the correct order
        this.gameLayer.addChild(new BackgroundLayer(this.space), 0, TagOfLayer.Background);
        this.gameLayer.addChild(new GamePlayLayer(this.space), 0, TagOfLayer.GamePlay);
        this.addChild(this.gameLayer);
        this.addChild(new StatusLayer(this.gameLayer.getChildByTag(TagOfLayer.GamePlay)), 0, TagOfLayer.Status);
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

        // setup chipmunk CollisionHandler
        this.space.addCollisionHandler(SpriteTag.character, SpriteTag.star,
            this.collisionStarBegin.bind(this), null, null, null);
        this.space.addCollisionHandler(SpriteTag.character, SpriteTag.bacon,
            this.collisionBaconBegin.bind(this), null, null, null);
    },

    collisionStarBegin:function (arbiter, space) {
        var shapes = arbiter.getShapes();
        // shapes[0] is runner
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

        var animationLayer = this.gameLayer.getChildByTag(TagOfLayer.GamePlay);
        var eyeX = animationLayer.getEyeX();

        this.gameLayer.setPosition(cc.p(-eyeX,0));
    }
});