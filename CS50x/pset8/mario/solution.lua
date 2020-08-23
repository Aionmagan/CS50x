--all code that was not added or edited was removed
--this will not work without the rest of the code
--which can be found in the cs50 2020 game track 

-- pole 
POLE_TOP = 8
POLE_MIDDLE = 12
POLE_BOTTOM = 16

-- pole flag
POLE_FLAG = 13

local CREATE_PYRAMID = 5
local PYRAMID_LINE = 1

-- constructor for our map object
function Map:init()


    -- begin generating the terrain using vertical scan lines
    local x = 1
    while x < self.mapWidth do
        
        -- create pyramid at the end of the level (15 squared before the end of mad width)
        if x >= self.mapWidth - 11 and CREATE_PYRAMID > 0 then

            for i = 1, PYRAMID_LINE do
            self:setTile(x, self.mapHeight / 2 - i, TILE_BRICK)
            end

            PYRAMID_LINE = PYRAMID_LINE + 1
            CREATE_PYRAMID = CREATE_PYRAMID - 1
        end

        if x == self.mapWidth - 3 then 
            self:setTile(x, self.mapHeight / 2 - 1, POLE_BOTTOM)
            self:setTile(x, self.mapHeight / 2 - 2, POLE_MIDDLE)
            self:setTile(x, self.mapHeight / 2 - 3, POLE_TOP)
            self:setTile(x + 1, self.mapHeight / 2 - 3, POLE_FLAG)
            
        end

        -- 5% chance to generate a mushroom
        -- need to add the self.mapWidth to prevent overlapping map generation 
        if math.random(20) == 1 and x < self.mapWidth - 14 then
	   --some code 
   
        -- 10% chance to generate bush, being sure to generate away from edge
        -- need to add the self.mapWidth to prevent overlapping map generation 
        elseif math.random(10) == 1 and x < self.mapWidth - 14 then
           --some code

        -- 10% chance to not generate anything, creating a gap
        -- need to add the self.mapWidth to prevent overlapping map generation 
        elseif math.random(10) ~= 1 or x > self.mapWidth - 14 then 
  	   --some code
            -- chance to create a block for Mario to hit
            -- need to add the self.mapWidth to prevent overlapping map generation 
            if math.random(15) == 1 and x < self.mapWidth - 14 then



end
