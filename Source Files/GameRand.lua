require('crypto')
 
local digest=crypto.digest
local md5=crypto.md5
 
GameRand = {
        my_step=1,
        my_seed=false,
        digest='',
        pos=1
}
 
function GameRand:new(o)
        o = o or {}
        setmetatable(o, self)
        self.__index = self
        return o
end
 
function GameRand:seed(s)
        self.my_seed=s
        self.my_step=0
        self.pos=1
        self.digest=digest(md5,self.my_seed,true)
end
 
function GameRand:step(step)
        local i
        for i=1, step do
                self:rand09()
        end
end
 
function GameRand:rand09()
        if self.pos>16 then
                self.digest=digest(md5,self.digest,true)
                self.pos=1
        end
 
        local x=math.floor(string.byte(string.sub(self.digest,self.pos,self.pos))*10/256)
        self.pos=self.pos+1
        self.my_step=self.my_step+1
        return x
end