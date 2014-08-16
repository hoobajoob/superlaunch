var Rope = cc.Class.extend({
    space:null,
    shape:null,
    startJoint:null,
    endJoint:null,
    dampening:1,
    length:20,
    stiffness:15,
    links:[],


    /** Constructor
     * @param {cc.SpriteBatchNode *}
     * @param {cp.Space *}
     * @param {cc.p}
     */
    ctor:function (spriteSheet, space, length, startBody, endBody) {
        this.space = space;
        var sprite = cc.PhysicsSprite.create(res.chainlink_png);
        // init physics
        var width = sprite.getContentSize().width;
        var height = sprite.getContentSize().height;

        var body = new cp.Body(1, cp.momentForBox(1, width, height));
        sprite.setBody(body);
        spriteSheet.addChild(sprite);
        this.space.addBody(body);

        var zeroPoint = cc.p(0,0);
        var leftPoint = cc.p(-width / 2,0);
        var rightPoint = cc.p(width / 2,0);
        this.startJoint = new cp.DampedSpring(body, startBody, leftPoint, rightPoint, this.length, this.stiffness, this.dampening);
        this.space.addConstraint(this.startJoint);
        spriteSheet.addChild(this.startJoint);

        this.links.push(body);
        for (var i = 0; i < length; i++)
        {
            var sprite = cc.PhysicsSprite.create(res.chainlink_png);
            body = new cp.Body(1, cp.momentForBox(1, width, height));
            sprite.setBody(body);
            spriteSheet.addChild(sprite);
            this.space.addBody(body);
            var midJoint = new cp.DampedSpring(body, this.links[i], zeroPoint, zeroPoint, this.length, this.stiffness, this.dampening);
            this.space.addConstraint(midJoint);
            spriteSheet.addChild(midJoint);
            this.links.push(body);
        }

        this.endJoint = new cp.DampedSpring(endBody, body, zeroPoint, zeroPoint, this.length, this.stiffness, this.dampening);
        this.space.addConstraint(this.endJoint);
        spriteSheet.addChild(this.endJoint);
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