var BackgroundLayer = cc.Layer.extend({
    map00:null,
    map01:null,
    mapWidth:0,
    mapIndex:0,
    space:null,
    objects:[],
    mapLoad:false,
    newToys:true,
    spriteSheet:null,

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

        //create the background image and position it at the center of screen
        var centerPos = cc.p(winsize.width / 2, winsize.height / 2);
        this.map00 = cc.Sprite.create(res.sky_png);
        this.map00.setPosition(centerPos);
        this.addChild(this.map00);
        this.mapWidth = this.map00.getContentSize().width;
        this.map01 = cc.Sprite.create(res.sky_png);
        this.map01.setPosition(cc.p(this.map00.getContentSize().width, winsize.height / 2));
        this.addChild(this.map01);
        if (this.mapLoad) {
            this.loadObjects(this.map00, 0);
            this.loadObjects(this.map01, 1);
        }
        else
        {
            this.loadRandomObjects(winsize.width / 2);
        }

        this.scheduleUpdate();
    },

    checkAndReload:function (eyeX) {
        var newMapIndex = parseInt((eyeX + 240) / this.mapWidth);
        if (this.mapIndex == newMapIndex) {
            return false;
        }

        if (0 == newMapIndex % 2) {
            // change mapSecond
            this.map01.setPositionX(this.mapWidth * (newMapIndex + 1));
            if (this.mapLoad){
               this.loadObjects(this.map01, newMapIndex + 1);
            }
            else
            {
                this.loadRandomObjects(eyeX);
            }
        } else {
            // change mapFirst
            this.map00.setPositionX(this.mapWidth * (newMapIndex + 1));
            if (this.mapLoad){

                this.loadObjects(this.map00, newMapIndex + 1);
            }
            else
            {
                this.loadRandomObjects(eyeX);
            }
        }
        this.removeObjects(newMapIndex - 1);
        this.mapIndex = newMapIndex;

        return true;
    },

    update:function (dt) {
        var animationLayer = this.getParent().getChildByTag(TagOfLayer.GamePlay);
        var eyeX = animationLayer.getEyeX();
        this.checkAndReload(eyeX);
    },

    loadObjects:function (map, mapIndex) {
        // add stars
        var starGroup = map.getObjectGroup("star");
        var starArray = starGroup.getObjects();
        for (var i = 0; i < starArray.length; i++) {
            var star = new BackgroundObject(this.spriteSheet,
                this.space,
                cc.p(starArray[i]["x"] + this.mapWidth * mapIndex,starArray[i]["y"])
                , SpriteTag.star);
            star.mapIndex = mapIndex;
            this.objects.push(star);
        }

        // add bacon
        var kegGroup = map.getObjectGroup("keg");
        var kegArray = kegGroup.getObjects();
        for (var i = 0; i < kegArray.length; i++) {
            var rock = new BackgroundObject(this.spriteSheet,
                this.space,
                kegArray[i]["x"] + this.mapWidth * mapIndex, SpriteTag.keg);
            rock.mapIndex = mapIndex;
            this.objects.push(rock);
        }
    },

    loadRandomObjects:function (xScreen) {
        //randomize first location
        Math.random();
        //Load objects in the near future
        if (this.newToys){
            //Insert Star
            var star = new BackgroundObject(this,
                this.space, this.genRandomPos(xScreen),
                SpriteTag.star);
            this.objects.push(star);
            //Todo:Insert Bacon
            if (Math.random() < .85)
            {
                if (Math.random() < (3/5))
                {
                    //Todo:Insert Trampoline
                    //Just genRandomX
                }
                else
                {
                    //Todo:Insert Ramp
                    //Just genRandomX
                }
            }
            else
            {
                if (Math.random < 3/5)
                {
                    //Todo:Insert Spikewall
                }
                else
                {
                    //Todo:Insert Keg
                }
            }
            if (Math.random < 1/5)
            {
                //Todo:Insert Bomb
            }
            if (Math.random < 1/2)
            {
                //Todo:Insert JetRefill
            }
            if (Math.random < 1/10)
            {
                //Todo:Insert Rooster
            }
        }
    },

    genRandomPos:function(posX){
        var xRand = Math.random();
        if (xRand <= (10 / 480)){ xRand = 10} else { xRand = xRand * 480};
        var yRand = Math.random();
        if (yRand <= (40 / 480)){ yRand = 40} else { yRand = yRand * 480};
        var result = cc.p(posX + 960 + xRand, cc.director.getWinSize().height / 2);
        return result;
    },

    removeObjects:function (mapIndex) {
        while((function (obj, index) {
            for (var i = 0; i < obj.length; i++) {
                if (obj[i].mapIndex == index) {
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