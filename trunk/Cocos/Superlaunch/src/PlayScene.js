var PlayScene = cc.Scene.extend({
    space:null,
    statusLayer:null,
    gameLayer:null,
    gamePlayLayer:null,
    shapesToRemove:[],
    impulsesToApply:[],
    lastUpdateTime:null,

    onEnter:function () {
        this._super();
        this.initPhysics();
        this.gameLayer = cc.Layer.create();
        //add the three layers in the correct order
        this.gameLayer.addChild(new BackgroundLayer(this.space), 0, TagOfLayer.Background);
        this.gamePlayLayer = new GamePlayLayer(this.space);
        this.gameLayer.addChild(this.gamePlayLayer, 0, TagOfLayer.GamePlay);
        // Parallax ratio and offset
        this.gameLayer.addChild(this._debugNode, 10);
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
        //2. setup the  Gravity
        this.space.gravity = cp.v(0, -350);

        var wallBack = new cp.SegmentShape(this.space.staticBody,
            cp.v(-125, 0),// start point
            cp.v(-125, 1000),
            20);// thickness of wall
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
        this.space.setDefaultCollisionHandler(null, null,this.collisionImpactPostSolve.bind(this), null);
    },

    collisionStarBegin:function (arbiter, space) {
        var shapes = arbiter.getShapes();
        // shapes[0] is character
        //TODO:Find a way to pass the shape directly from handler
        this.impulsesToApply.push([cp.v(50,500), cp.v(-2,0)]);
        this.shapesToRemove.push(shapes[1]);
        cc.log("==Hit Star");
        //prevent any further collision processing
        return false;
    },

    collisionBaconBegin:function (arbiter, space) {
        var shapes = arbiter.getShapes();
        // shapes[0] is character
        //TODO:Find a way to pass the shape directly from handler
        this.impulsesToApply.push([cp.v(20,500), cp.v(-2,0)]);
        this.shapesToRemove.push(shapes[1]);
        this.statusLayer.updateLife(25);
        cc.log("==Hit Bacon");
        //prevent any further collision processing
        return false;
    },

    collisionBombBegin:function (arbiter, space) {
        var shapes = arbiter.getShapes();
        // shapes[0] is character
        //TODO:Find a way to pass the shape directly from handler
        this.impulsesToApply.push([cp.v(-200,-200), cp.v(-2,0)]);
        this.shapesToRemove.push(shapes[1]);
        this.statusLayer.updateLife(15);
        cc.log("==Hit Bomb");
        //prevent any further collision processing
        return false;
    },

    collisionJetRefillBegin:function (arbiter, space) {
        var shapes = arbiter.getShapes();
        this.shapesToRemove.push(shapes[1]);
        this.statusLayer.updateBoost(40);
        cc.log("==Hit Jet Refill");
        //prevent any further collision processing
        return false;
    },

    collisionImpactPostSolve:function (arbiter, space) {
        if (arbiter.isFirstContact()) {
            var impact = arbiter.totalImpulse();
            var damage = 0;
            if (Math.abs(impact.x) > Math.abs(impact.y))
            {
                damage = Math.abs(impact.x) - Math.abs(impact.y);
            }
            else
            {
                damage = Math.abs(impact.y) - Math.abs(impact.x);
            }
            cc.log("==Character Impact" + damage.toString());
            this.statusLayer.updateLife(-damage / 100);
        }
    },

    update:function(dt) {
        //chipmunk step
        this.space.step(dt);

        var gamePlayLayer = this.gamePlayLayer;
        var statusLayer = this.statusLayer;

        if (this.gamePlayLayer.getPrelaunchStatus() == true)
        {
            gamePlayLayer.moveCharacterToTouch();
        }
        else
        {
            if (statusLayer.getLife() <= 0)
            {
                cc.log("==game over by life");
                cc.director.pause();
                this.addChild(new GameOverLayer());
            }
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
            var newX = 0;
            if (eyeX > -g_characterStartX / 2)
            {
                newX = (-g_characterStartX / 2) - eyeX;
            }
            var eyeY = gamePlayLayer.getEyeY();
            var newY = 0;
            if (eyeY > 0)
            {
                newY = -eyeY;
            }
            //Move Camera to follow player
            this.gameLayer.setPosition(cc.p(newX,newY));

            var velocity = gamePlayLayer.getVelocity();
            //Check and reduce life if going backwards
            if(velocity.x > 0)
            {
                //Update Distance Label
                if(velocity.x > 0 && eyeX > 0)
                {
                    this.statusLayer.updateDistance(eyeX);
                }
            }
            var curTime = new Date().getTime();
            if (this.lastUpdateTime == null || (curTime - this.lastUpdateTime) > 50)
            {
                if (velocity.x <= 0)
                {
                        this.statusLayer.updateLife(-1);
                }

                if (statusLayer.getBoostStatus())
                {
                    cc.log("==Boost Fired");
                    gamePlayLayer.fireBoost();
                    statusLayer.updateBoost(-1);
                }

                if (statusLayer.getLazarStatus())
                {
                    cc.log("==Lazars Fired");
                    gamePlayLayer.fireLazars();
                    statusLayer.updateLazar(-1);
                }
            }
        }
    }
});