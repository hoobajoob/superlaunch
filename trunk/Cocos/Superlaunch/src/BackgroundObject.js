var BackgroundObject = cc.Class.extend({
    space:null,
    sprite:null,
    shape:null,
    type:null,
    _mapIndex:0,// which map belongs to
    get mapIndex() {
        return this._mapIndex;
    },
    set mapIndex(index) {
        this._mapIndex = index;
    },

    /** Constructor
     * @param {cc.SpriteBatchNode *}
     * @param {cp.Space *}
     * @param {cc.p}
     */
    ctor:function (spriteSheet, space, pos, type) {
        this.space = space;

        /*// init object animation
        var animFrames = [];
        for (var i = 0; i < 8; i++) {
            var str = "coin" + i + ".png";
            var frame = cc.spriteFrameCache.getSpriteFrame(str);
            animFrames.push(frame);
        }

        var animation = cc.Animation.create(animFrames, 0.2);
        var action = cc.RepeatForever.create(cc.Animate.create(animation));*/

        this.type = type;
        if (type == SpriteTag.star){
            this.sprite = cc.PhysicsSprite.create(res.star_png);
        }
        else if (type == SpriteTag.keg){
            this.sprite = cc.PhysicsSprite.create(res.keg_png);
        }
        else if (type == SpriteTag.grass){
            this.sprite = cc.PhysicsSprite.create(res.grass_png);
        }
        else if (type == SpriteTag.lava){
            this.sprite = cc.PhysicsSprite.create(res.lava_png);
        }
        else if (type == SpriteTag.quickSand){
            this.sprite = cc.PhysicsSprite.create(res.quickSand_png);
        }
        else if (type == SpriteTag.ramp){
            this.sprite = cc.PhysicsSprite.create(res.ramp_png);
        }
        else if (type == SpriteTag.bomb){
            this.sprite = cc.PhysicsSprite.create(res.bomb_png);
        }
        else if (type == SpriteTag.bacon){
            this.sprite = cc.PhysicsSprite.create(res.bacon_png);
        }
        else if (type == SpriteTag.trampoline){
            this.sprite = cc.PhysicsSprite.create(res.trampoline_png);
        }
        else if (type == SpriteTag.spikeWall){
            this.sprite = cc.PhysicsSprite.create(res.spikewall_png);
        }
            // init physics
        var radius = 0.95 * this.sprite.getContentSize().width / 2;
        var width = this.sprite.getContentSize().width;
        var height = this.sprite.getContentSize().height;

        if (type == SpriteTag.keg || type == SpriteTag.ramp || type == SpriteTag.spikeWall)
        {
            pos = cc.p(pos.x, g_groundHeight - height / 2);
        }
        else if (type == SpriteTag.trampoline)
        {
            pos = cc.p(pos.x, g_groundHeight - g_groundSpriteOffset - height / 2.5);
        }
        else if (type == SpriteTag.grass || type == SpriteTag.lava || type == SpriteTag.quickSand)
        {
            pos = cc.p(pos.x, g_groundHeight - height + g_groundSpriteOffset);
        }

        var body = new cp.StaticBody();
        body.setPos(pos);
        this.sprite.setBody(body);

        if (type == SpriteTag.star || type == SpriteTag.bomb){
            this.shape = new cp.CircleShape(body, radius, cp.vzero);
            //Sensors only call collision callbacks, and never generate real collisions
            this.shape.setSensor(true);
        }
        else if (type == SpriteTag.bacon || type == SpriteTag.jetRefill){
            this.shape = new cp.BoxShape(body, width, height);
            this.shape.setSensor(true);
        }
        else if (type == SpriteTag.keg){
            this.shape = new cp.BoxShape(body, width, height);
        }
        else if (type == SpriteTag.ramp)
        {
            this.shape = new cp.PolyShape(body, [ 32,-25, -40,-25, 32,29], cc.p(0,-8) );
            this.shape.setFriction(.001);
            this.shape.setElasticity(.2);
        }
        else if (type == SpriteTag.spikeWall)
        {
            this.shape = new cp.PolyShape(body, [ 20,-43, -38,40, -22,40, 36,-43], cc.p(0,-8) );
            this.shape.setSensor(true);
        }
        else if (type == SpriteTag.trampoline)
        {
            this.shape = new cp.PolyShape(body, [ 20,-7, -20,-5, -20,-4, 20,0], cc.p(0,-2) );
            this.shape.setFriction(.001);
            this.shape.setElasticity(5);
        }
        else if (type == SpriteTag.grass || type == SpriteTag.lava || type == SpriteTag.quickSand)
        {
            var halfWidth = width / 2;
            var halfHeight = height / 2;
            this.shape = new cp.PolyShape(body, [ -halfWidth,-halfHeight, -halfWidth,halfHeight - 3, -halfWidth + 10, halfHeight,  halfWidth, halfHeight, halfWidth, -halfHeight], cc.p(0, -g_groundSpriteOffset));

            if (type == SpriteTag.grass)
            {
                this.shape.setFriction(.025);
                this.shape.setElasticity(.25);
            }
            if (type == SpriteTag.lava)
            {
                this.shape.setFriction(.1);
                this.shape.setElasticity(.2);
            }
            else if (type == SpriteTag.quickSand)
            {
                this.shape.setFriction(.25);
                this.shape.setElasticity(0);
            }
        }

        this.shape.setCollisionType(type);

        this.space.addStaticShape(this.shape);

        // add sprite to sprite sheet
        //this.sprite.runAction(action);
        spriteSheet.addChild(this.sprite, 1);
    },

    removeFromParent:function () {
        this.space.removeStaticShape(this.shape);
        this.shape = null;
        this.sprite.removeFromParent();
        this.sprite = null;
    },

    getShape:function () {
        return this.shape;
    },

    getType:function () {
        return this.type;
    }
});