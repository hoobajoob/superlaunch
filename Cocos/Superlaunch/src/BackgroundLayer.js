var BackgroundLayer = cc.Layer.extend({
    sky1:null,
    sky2:null,
    skyMid1:null,
    skyMid2:null,
    skyTop1:null,
    skyTop2:null,
    skyTrans1:null,
    skyTrans2:null,
    mapWidth:0,
    mapXIndex:0,
    mapHeight:0,
    mapYIndex:0,
    space:null,
    objects:[],
    mapLoad:false,
    newToys:true,
    mapMovedIndex:null,
    firstReverse:null,
    firstReverseChanged:false,

    ctor:function (space, mapLoad) {
        this._super();
        this.objects = [];
        this.space = space;
        this.mapLoad = mapLoad;
        this.init();
    },

    init:function () {
        this._super();
        var winsize = cc.director.getWinSize();

        //TODO:Either merge all sky's to 1 image or implement collecting offscreen verticals and re-creating
        //create the background image and position it at the center of screen
        var midHeight = winsize.height / 2;
        this.sky1 = cc.Sprite.create(res.sky_png);
        this.sky1.setPosition(cc.p(0, midHeight));
        this.addChild(this.sky1);
        this.mapWidth = this.sky1.getContentSize().width;
        this.mapHeight = this.sky1.getContentSize().height;
        this.skyMid1 = cc.Sprite.create(res.skyMiddle_png);
        this.skyMid1.setPosition(cc.p(0, midHeight + this.sky1.height));
        this.addChild(this.skyMid1);
        this.skyTop1 = cc.Sprite.create(res.skyTop_png);
        this.skyTop1.setPosition(cc.p(0, midHeight + this.sky1.height + this.skyMid1.height));
        this.addChild(this.skyTop1);
        this.skyTrans1 = cc.Sprite.create(res.skyTransition_png);
        this.skyTrans1.setPosition(cc.p(0, midHeight + this.sky1.height + this.skyMid1.height + this.skyTop1.height));
        this.addChild(this.skyTrans1);
        this.sky2 = cc.Sprite.create(res.sky_png);
        this.sky2.setPosition(cc.p(this.sky1.getContentSize().width, midHeight));
        this.addChild(this.sky2);
        this.skyMid2 = cc.Sprite.create(res.skyMiddle_png);
        this.skyMid2.setPosition(cc.p(this.skyMid1.getContentSize().width, midHeight + this.sky2.height));
        this.addChild(this.skyMid2);
        this.skyTop2 = cc.Sprite.create(res.skyTop_png);
        this.skyTop2.setPosition(cc.p(this.skyTop1.getContentSize().width, midHeight + this.sky2.height + this.skyMid2.height));
        this.addChild(this.skyTop2);
        this.skyTrans2 = cc.Sprite.create(res.skyTransition_png);
        this.skyTrans2.setPosition(cc.p(this.skyTrans1.getContentSize().width, midHeight + this.sky2.height + this.skyMid2.height + this.skyTop2.height));
        this.addChild(this.skyTrans2);
        if (this.mapLoad) {
            this.loadObjects(this.sky1, 0);
            this.loadObjects(this.sky2, 1);
            this.loadObjects(this.skyMid1, 3);
            this.loadObjects(this.skyMid2, 4);
        }
        else
        {
            this.loadGroundObjects(-1, true);
            this.loadGroundObjects(0, true);
            this.loadGroundObjects(1, true);
            //TODO:Change so that Ground Objects are put to back, rather than loading earlier
            this.loadGroundObjects(2, true);
            this.loadRandomObjects(winsize.width / 2);
        }

        this.scheduleUpdate();
    },

    checkAndReload:function (eyeX, eyeY, velocity) {
        var newXMapIndex = parseInt((eyeX + g_screenAdvance) / this.mapWidth);
        var newYMapIndex = parseInt((eyeY + 160) / this.mapHeight);
        if (velocity.x < 0){
            //load previous horizontal background if necessary
            if (this.firstReverse == null) {this.firstReverse = newXMapIndex};
            if (this.mapMovedIndex == null)
            {
                this.mapMovedIndex == newXMapIndex + 1;
            }
            var mapRemain = (eyeX + 120) % this.mapWidth;
            var mapLessThanHalf = (mapRemain < (this.mapWidth / 2));
            if ((this.firstReverseChanged && this.firstReverse == newXMapIndex && mapLessThanHalf) || this.firstReverse != newXMapIndex && this.mapMovedIndex != newXMapIndex){
                this.firstReverseChanged = true;
                this.mapMovedIndex = newXMapIndex;
                var curLocation = this.mapWidth * (newXMapIndex - 1) + this.mapWidth;
                if (0 == newXMapIndex % 2) {
                    this.sky1.setPositionX(curLocation);
                    this.skyMid1.setPositionX(curLocation);
                    this.skyTop1.setPositionX(curLocation);
                    this.skyTrans1.setPositionX(curLocation);
                } else {
                    this.sky2.setPositionX(curLocation);
                    this.skyMid2.setPositionX(curLocation);
                    this.skyTop2.setPositionX(curLocation);
                    this.skyTrans2.setPositionX(curLocation);
                }
                return true;
            }
        }
        else
        {
            this.firstReverseChanged = false;
            this.firstReverse = null;
        }
        if (this.mapXIndex == newXMapIndex) {
            return false;
        }

        //load next horizontal background if necessary and load/remove objects
        if (0 == newXMapIndex % 2) {
            // change mapSecond
            this.sky2.setPositionX(this.mapWidth * (newXMapIndex + 1));
            this.skyMid2.setPositionX(this.mapWidth * (newXMapIndex + 1));
            this.skyTop2.setPositionX(this.mapWidth * (newXMapIndex + 1));
            this.skyTrans2.setPositionX(this.mapWidth * (newXMapIndex + 1));
            if (this.mapLoad){
               this.loadObjects(this.sky2, newXMapIndex + 1);
            }
            else
            {
                this.loadGroundObjects(newXMapIndex + 2);
                this.loadRandomObjects(eyeX);
            }
        } else {
            // change mapFirst
            this.sky1.setPositionX(this.mapWidth * (newXMapIndex + 1));
            this.skyMid1.setPositionX(this.mapWidth * (newXMapIndex + 1));
            this.skyTop1.setPositionX(this.mapWidth * (newXMapIndex + 1));
            this.skyTrans1.setPositionX(this.mapWidth * (newXMapIndex + 1));
            if (this.mapLoad){

                this.loadObjects(this.sky1, newXMapIndex + 1);
            }
            else
            {
                this.loadGroundObjects(newXMapIndex + 2);
                this.loadRandomObjects(eyeX);
            }
        }
        this.removeObjects(newXMapIndex - 1);
        this.mapXIndex = newXMapIndex;

        return true;
    },

    update:function (dt) {
        var gamePlayLayer = this.getParent().getChildByTag(TagOfLayer.GamePlay);
        var eyeX = gamePlayLayer.getEyeX();
        var eyeY = gamePlayLayer.getEyeY();
        var velocity = gamePlayLayer.getVelocity();
        this.checkAndReload(eyeX, eyeY, velocity);
    },

    loadObjects:function (map, mapIndex) {
        // add stars
        var starGroup = map.getObjectGroup("star");
        var starArray = starGroup.getObjects();
        for (var i = 0; i < starArray.length; i++) {
            var star = new BackgroundObject(this,
                this.space,
                cc.p(starArray[i]["x"] + this.mapWidth * mapIndex,starArray[i]["y"])
                , SpriteTag.star);
            star.mapIndex = mapIndex;
            this.objects.push(star);
        }

        // add keg
        var kegGroup = map.getObjectGroup("keg");
        var kegArray = kegGroup.getObjects();
        for (var i = 0; i < kegArray.length; i++) {
            var rock = new BackgroundObject(this,
                this.space,
                kegArray[i]["x"] + this.mapWidth * mapIndex, SpriteTag.keg);
            rock.mapIndex = mapIndex;
            this.objects.push(rock);
        }
    },

    loadGroundObjects:function (mapIndex, grassOnly) {
        //Load ground objects
        if (grassOnly || Math.random() < 4/5)
        {
            //Insert Grass
            var grass = new BackgroundObject(this,
                this.space, cc.p(mapIndex * this.mapWidth + g_screenAdvance, g_groundHeight),
                SpriteTag.grass);
            this.objects.push(grass);
        }
        else
        {
            //if (Math.random() < 3/5)
            //{
                //Insert Lava
                var lava = new BackgroundObject(this,
                    this.space, cc.p(mapIndex * this.mapWidth + g_screenAdvance, g_groundHeight),
                    SpriteTag.lava);
                this.objects.push(lava);
            //}
            //else
            //{
                //Todo:Insert QuickSand
            //}
        }
    },

    loadRandomObjects:function (xScreen) {


        //Load objects in the near future
        if (this.newToys){
            //Insert Star
            var star = new BackgroundObject(this,
                this.space, this.genRandomPos(xScreen),
                SpriteTag.star);
            this.objects.push(star);
            var bacon = new BackgroundObject(this,
                this.space, this.genRandomPos(xScreen),
                SpriteTag.bacon);
            this.objects.push(bacon);
            if (Math.random() < .85)
            {
                if (Math.random() < (3/5))
                {
                    //Todo:Insert Trampoline
                    //Just genRandomX
                }
                else
                {
                    var ramp = new BackgroundObject(this,
                        this.space, this.genRandomPos(xScreen),
                        SpriteTag.ramp);
                    this.objects.push(ramp);
                }
            }
            else
            {
                if (Math.random < 1)
                {
                    //Todo:Insert Spikewall
                }
                else
                {
                    var keg = new BackgroundObject(this,
                        this.space, this.genRandomPos(xScreen),
                        SpriteTag.keg);
                    this.objects.push(keg);
                }
            }
            if (Math.random < 1/5)
            {
                var bomb = new BackgroundObject(this,
                    this.space, this.genRandomPos(xScreen),
                    SpriteTag.bomb);
                this.objects.push(bomb);
            }
            if (Math.random < 1/2)
            {
                var jetRefill = new BackgroundObject(this,
                    this.space, this.genRandomPos(xScreen),
                    SpriteTag.jetRefill);
                this.objects.push(jetRefill);
            }
            if (Math.random < 1/10)
            {
                //Todo:Insert Rooster
            }
        }
    },

    genRandomPos:function(posX){
        var xRand = Math.random();
        var yMin = 100;
        var yMax = 1080;
        var xMin = 10;
        var xMax = 480;
        if (xRand <= (xMin / xMax)){ xRand = xMin} else { xRand = xRand * xMax};
        var yRand = Math.random();
        if (yRand <= (yMin / yMax)){ yRand = yMin} else { yRand = yRand * yMax};
        var result = cc.p(posX + 960 + xRand, yRand);
        return result;
    },

    removeObjects:function (mapIndex) {
        while((function (obj, index) {
            for (var i = 0; i < obj.length; i++) {
                if (obj[i].mapXIndex == index) {
                    obj[i].removeFromParent();
                    obj.splice(i, 1);
                    return true;
                }
            }
            return false;
        })(this.objects, mapIndex));
    },

    removeObjectByShape:function (shape) {
        for (var i = 0; i < this.objects.length; i++) {
            if (this.objects[i].getShape() == shape) {
                this.objects[i].removeFromParent();
                this.objects.splice(i, 1);
                break;
            }
        }
    }
});