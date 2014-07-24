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
            this.sprite = cc.PhysicsSprite.create(res.star);
        }
        else if (type == SpriteTag.keg){
            this.sprite = cc.PhysicsSprite.create(res.keg);
        }
            // init physics
        var radius = 0.95 * this.sprite.getContentSize().width / 2;
        var width = this.sprite.getContentSize().width;
        var height = this.sprite.getContentSize().height;
        body = new cp.StaticBody();
        body.setPos(pos);
        this.sprite.setBody(body);

        if (type == SpriteTag.star){
            this.shape = new cp.CircleShape(body, radius, cp.vzero);
            this.shape.setCollisionType(SpriteTag.star);
            //Sensors only call collision callbacks, and never generate real collisions
            this.shape.setSensor(true);
        }
        else if (type == SpriteTag.keg){
            this.shape = new cp.BoxShape(body, width, height);
            this.shape.setCollisionType(SpriteTag.keg);
        }
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