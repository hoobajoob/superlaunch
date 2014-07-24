var BackgroundLayer = cc.Layer.extend({
    map00:null,
    map01:null,
    mapWidth:0,
    mapIndex:0,
    space:null,
    objects:[],
    mapLoad:false,
    newToys:true,

    ctor:function (space, mapLoad) {
        this._super();
        this.init();
        this.objects = [];
        this.space = space;
        this.mapLoad = mapLoad;
    },

    init:function () {
        this._super();
        var winsize = cc.director.getWinSize();

        //create the background image and position it at the center of screen
        var centerPos = cc.p(winsize.width / 2, winsize.height / 2);
        this.map00 = cc.Sprite.create(res.sky_png);
        this.map00.setPosition(centerPos - 45);
        this.addChild(this.map00);
        this.mapWidth = this.map00.getContentSize().width;
        this.map01 = cc.Sprite.create(res.sky_png);
        this.map01.setPosition(cc.p(centerPos + 515, winsize.height / 2));
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
        var newMapIndex = parseInt(eyeX / this.mapWidth);
        if (this.mapIndex == newMapIndex) {
            return false;
        }

        if (0 == newMapIndex % 2) {
            // change mapSecond
            this.map01.setPositionX(this.mapWidth * (newMapIndex + 1));
            this.loadObjects(this.map01, newMapIndex + 1);
        } else {
            // change mapFirst
            this.map00.setPositionX(this.mapWidth * (newMapIndex + 1));
            this.loadObjects(this.map00, newMapIndex + 1);
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
        math.random();
        //Load objects in the near future
        if (this.newToys){
            var curRand = math.random();
            if (curRand <= (10 / 480)){ curRand = 10} else { curRand = curRand * 480};
            var xLocation = xScreen + 960 + curRand;
            if (math.random() < (3/5))
            {
                if (math.random() < (4/5))
                {

                }
            }
        }
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