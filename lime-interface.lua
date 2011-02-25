-- Project: Lime
--
-- Date: 18-Feb-2011
--
-- Version: 2.8
--
-- File name: lime-interface.lua
--
-- Author: Graham Ranson 
--
-- Support: www.justaddli.me
--
-- Copyright (C) 2011 MonkeyDead Studios Limited. All Rights Reserved.

----------------------------------------------------------------------------------------------------
----									POLITE NOTICE / PSA										----
----------------------------------------------------------------------------------------------------
----																							----
----	I have put a lot of work into this library and plan to support it for a very, very		---- 
----	long time so please don't give the code to anyone else. I doubt that anyone would as	----
----	we are all developers in the same boat but I just thougt I would put this here in 		----
----	case any one wondered if it was ok to share.											----
----																							----
----	If you did get this code through less than legitimate means then please consider		----
----	buying it legally, it is (I think) affordably priced and you will get free updates		----
----	and support	for life.																	----
----																							----
----	I hope you enjoy using it as much as I have enjoyed writing it and I also hope that		----
----    you will support me and the development of Lime by telling your friends about it etc	----
----	although naturally I don't require any link backs of any kind, it is completely up		----
----	to you.																					----
----																							----
----	If you have any additions or fixes that you would like included in the main releases	----
----	please contact me via the forums or email - graham@grahamranson.co.uk					----
----																							----
----------------------------------------------------------------------------------------------------

module(..., package.seeall)

----------------------------------------------------------------------------------------------------
----									MODULE VARIABLES										----
----------------------------------------------------------------------------------------------------

version = 2.8
defaultTextColour = {234, 0, 0, 255}

----------------------------------------------------------------------------------------------------
----									LOCALISED VARIABLES										----
----------------------------------------------------------------------------------------------------

local utils = lime.utils

----------------------------------------------------------------------------------------------------
----									REQUIRED MODULES										----
----------------------------------------------------------------------------------------------------

local ui = utils.loadModuleSafely("ui")

----------------------------------------------------------------------------------------------------
----									PRIVATE METHODS											----
----------------------------------------------------------------------------------------------------

local onLabelObject = function(object)
	
	local textColour = utils.stringToIntTable(object.textColor, ",")    
	
	-- Force full alpha if none present
	if textColour then
		if not textColour[4] then
			textColour[4] = 255
		end
	end
	
	object.sprite = ui.newLabel
	{
    	textColor = textColour or defaultTextColour,
        bounds = { object.x, object.y, object.width, object.height },
        text = object.text or object.name or "",
        align = object.align,
        size = object.size and tonumber(object.size),
        font = object.font,
        offset = object.offset and tonumber(object.offset)
    }
 	
 	utils.copyPropertiesToObject(object, object.sprite, {"width", "height", "x", "y"})
 	
    object.objectLayer.group:insert(object.sprite)    
end

local onButtonObject = function(object)

	local textColour = utils.stringToIntTable(object.textColor, ",")    
	
	-- Force full alpha if none present
	if textColour then
		if not textColour[4] then
			textColour[4] = 255
		end
	end
	
	object.sprite = ui.newButton
	{
        default = object.default,
        over = object.over,
      --  onEvent = buttonHandler,
        text = object.text or object.name or "",
        font = object.font,
        textColor = textColour or defaultTextColour,
        size = object.size and tonumber(object.size),
        emboss = utils.stringToBool(object.emboss)
	}
	
	utils.copyPropertiesToObject(object, object.sprite, {"width", "height"})
	
	object.sprite.x = object.sprite.x + object.sprite.width / 2
	object.sprite.y = object.sprite.y + object.sprite.height / 2

	object.objectLayer.group:insert(object.sprite)  
end

----------------------------------------------------------------------------------------------------
----									PUBLIC METHODS											----
----------------------------------------------------------------------------------------------------

--- Register a map object so that an interface will be created from it. 
-- @param map - The map object. 
function register(map)

	if ui then
	
		map:addObjectListener("UILabel", onLabelObject)
		map:addObjectListener("UIButton", onButtonObject)
		
	end
end