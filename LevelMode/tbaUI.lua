-- tbaUI.lua (currently includes Bar Class)

-- Version 1.0

module(..., package.seeall)
--------------
-- Bar class

function newBar( params )
	local bar
	local size, lineColor
	local group = display.newGroup()
	
	if ( params.bounds ) then
		local bounds = params.bounds
		local left = bounds[1]
		local top = bounds[2]
		local width = bounds[3]
		local height = bounds[4]
	
		if ( params.size and type(params.size) == "number" ) then size=params.size else size=20 end
		if ( params.lineColor ) then lineColor=params.lineColor else lineColor={ 0, 255, 50, 255 } end
		if ( params.offset and type(params.offset) == "number" ) then offset=params.offset else offset = 0 end
		if ( params.align ) then align = params.align else align = "center" end
		
		bar = display.newLine( left, top, left + size, top )
		bar.width = width
		group:insert( bar )
		
		if params.beautyBar then
			local topLine = display.newLine( left - 2, top - 4, left + size + 2, top - 4 )
			topLine.width = 3
			topLine:setColor ( 200, 200, 200, 255 )
			local bottomLine = display.newLine( left - 2, top + width - 1, left + size + 2, top + width - 1)
			bottomLine.width = 3
			bottomLine:setColor ( 200, 200, 200, 255 )
			local leftLine = display.newLine( left - 1, top - 5, left - 1, top + width )
			leftLine.width = 3
			leftLine:setColor ( 200, 200, 200, 255 )
			local rightLine = display.newLine( left + size + 1, top - 5, left + size + 1, top + width )
			rightLine.width = 3
			rightLine:setColor ( 200, 200, 200, 255 )
			group:insert( topLine )
			group:insert( bottomLine )
			group:insert( leftLine )
			group:insert( rightLine )
		end

		-- Public methods
		function group:setSize( newSize )
			if ( newSize ) then
				bar:removeSelf()
				bar = display.newLine( left, top, left + newSize, top )
				bar.width = width
				if newSize > 60 then
					bar:setColor( 0, 255, 50, 255 )
				elseif newSize > 40 then
					bar:setColor( 255, 255, 0, 255 )
				elseif newSize > 20 then
					bar:setColor( 255, 165, 0, 255 )
				else
					bar:setColor( 255, 50, 0, 255 )
				end
			end
		end
		
		function group:setColor( theColor )
			if ( theColor and type(theColor) == "table" ) then
				self:setColor( theColor[1], theColor[2], theColor[3], theColor[4] )
			end
		end
	end
	
	return group
	-- Return instance
	
end

-- Convert from CSV string to table
function fromCSV (s)
  local t = {}        -- table to collect fields
  if s ~= nil then
	  s = s .. ','        -- ending comma
	  local fieldstart = 1
	  repeat
		-- next field is quoted? (start with `"'?)
		if string.find(s, '^"', fieldstart) then
		  local a, c
		  local i  = fieldstart
		  repeat
			-- find closing quote
			a, i, c = string.find(s, '"("?)', i+1)
		  until c ~= '"'    -- quote not followed by quote?
		  if not i then error('unmatched "') end
		  local f = string.sub(s, fieldstart+1, i-1)
		  table.insert(t, (string.gsub(f, '""', '"')))
		  fieldstart = string.find(s, ',', i) + 1
		else                -- unquoted; find next comma
		  local nexti = string.find(s, ',', fieldstart)
		  table.insert(t, string.sub(s, fieldstart, nexti-1))
		  fieldstart = nexti + 1
		end
	  until fieldstart > string.len(s)
  end
  return t
end