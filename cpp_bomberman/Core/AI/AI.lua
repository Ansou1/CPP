enum = {}
enum["UP"] = 0
enum["DOWN"] = 2
enum["LEFT"] = 3
enum["RIGHT"] = 1
enum["ON"] = 100
enum["NONE"] = 5
enum["BOMB"] = 4

case = {}
case["EMPTY"] = 10
case["WALL"] = 20
case["CRATE"] = 30
case["BONUS"] = 40
case["BOOM"] = 50
case["BOMB"] = 60
case["PLAYER"] = 70


pos = width * (posY - 1) + posX

--evitement des bombes

function can_move_toward(val)
   return (val == case["EMPTY"] or val == case["BONUS"] or val == case["PLAYER"])
end

function check_danger_line(_val, _tab_bool, _id)
   if _val == case["WALL"] or _val == case["CRATE"] then
      _tab_bool[_id] = false
   elseif _val == case["BOMB"] then
      return true
   end
   return false
end

function is_in_danger(_map, _pos)

   --pos
   if _map[_pos] == case["BOMB"] then
      return enum["ON"]
   end

   local tab_bool = {true, true, true, true}

   for i = 1, 3 do

      --droite
      if tab_bool[1] and check_danger_line(_map[_pos + i], tab_bool, 1) then
	 return enum["RIGHT"]
      end

      --gauche
      if tab_bool[2] and check_danger_line(_map[_pos - i], tab_bool, 2) then
	 return enum["LEFT"]
      end

      --haut
      if _pos > width * i then
	 if tab_bool[3] and check_danger_line(_map[_pos - width * i], tab_bool, 3) then
	    return enum["UP"]
	 end
      end

      --bas
      if (_pos + i * width) < (width * length) then
	 if tab_bool[4] and check_danger_line(_map[_pos + width * i], tab_bool, 4) then
	    return enum["DOWN"]
	 end
      end
   end
   return enum["NONE"]
end

function go_to_safe_corner(_map, _pos)
   if can_move_toward(_map[_pos - 1 - width]) and is_in_danger(_map, _pos - 1 - width) == enum["NONE"] then
      if can_move_toward(_map[_pos - 1]) then
	 return enum["LEFT"]
      elseif can_move_toward(_map[_pos - width]) then
      	 return enum["UP"]
      end
   elseif can_move_toward(_map[_pos + 1 - width]) and is_in_danger(_map, _pos + 1 - width) == enum["NONE"] then
      if can_move_toward(_map[_pos + 1]) then
	 return enum["RIGHT"]
      elseif can_move_toward(_map[_pos - width]) then
      	 return enum["UP"]
      end
   elseif can_move_toward(_map[_pos + 1 + width]) and is_in_danger(_map, _pos + 1 + width) == enum["NONE"] then
      if can_move_toward(_map[_pos + 1]) then
	 return enum["RIGHT"]
      elseif can_move_toward(_map[_pos + width]) then
      	 return enum["DOWN"]
      end
   elseif can_move_toward(_map[_pos - 1 + width]) and is_in_danger(_map, _pos - 1 + width) == enum["NONE"] then
      if can_move_toward(_map[_pos - 1]) then
	 return enum["LEFT"]
      elseif can_move_toward(_map[_pos + width]) then
      	 return enum["DOWN"]
      end
   end
   return enum["NONE"]
end

function escape_bomb(_map, _pos)
   local danger = is_in_danger(_map, _pos)

   if danger == enum["RIGHT"] then
      if can_move_toward(_map[_pos - width]) and is_in_danger(_map, _pos - width) == enum["NONE"] then
	 return enum["UP"]
      elseif can_move_toward(_map[_pos + width]) and is_in_danger(_map, _pos + width) == enum["NONE"] then
	 return enum["DOWN"]
      else
	 return go_to_safe_corner(_map, _pos)
      end
   elseif danger == enum["LEFT"] then
      if can_move_toward(_map[_pos - width]) and is_in_danger(_map, _pos - width) == enum["NONE"] then
	 return enum["UP"]
      elseif can_move_toward(_map[_pos + width]) and is_in_danger(_map, _pos + width) == enum["NONE"] then
	 return enum["DOWN"]
      else
	 return go_to_safe_corner(_map, _pos)
      end
   elseif danger == enum["UP"] then
      if can_move_toward(_map[_pos - 1]) and is_in_danger(_map, _pos - 1) == enum["NONE"] then
	 return enum["LEFT"]
      elseif can_move_toward(_map[_pos + 1]) and is_in_danger(_map, _pos + 1) == enum["NONE"] then
	 return enum["RIGHT"]
      else
	 return go_to_safe_corner(_map, _pos)
      end
   elseif danger == enum["DOWN"] then
      if can_move_toward(_map[_pos - 1]) and is_in_danger(_map, _pos - 1) == enum["NONE"] then
	 return enum["LEFT"]
      elseif can_move_toward(_map[_pos + 1]) and is_in_danger(_map, _pos + 1) == enum["NONE"] then
	 return enum["RIGHT"]
      else
	 return go_to_safe_corner(_map, _pos)
      end
   elseif danger == enum["ON"] then
      return go_to_safe_corner(_map, _pos)
   end
   return enum["NONE"]
end


-- pose de bombes

function is_near_something_destructible(_pos, _map)
   for i = 1, range do
      if _pos - i > 0 and (_map[_pos - i] == case["CRATE"] or _map[_pos - i] == case["PLAYER"]) then
	 return true
      end
      if _pos - i * width > 0 and (_map[_pos - width * i] == case["CRATE"] or _map[_pos - width * i] == case["PLAYER"]) then
	 return true
      end
      if _pos + i < width * length and (_map[_pos + i] == case["CRATE"] or _map[_pos + i] == case["PLAYER"]) then
	 return true
      end
      if _pos + i * width < width * length and (_map[_pos + width * i] == case["CRATE"] or _map[_pos + width * i] == case["PLAYER"]) then
	 return true
      end
   end
   return false
end

function can_drop_bomb(_pos, _map)
   local prev = _map[_pos]
   _map[_pos] = case["BOMB"];
   if go_to_safe_corner(_map, _pos) == enum["NONE"] then
      _map[_pos] = prev;
      return false
   end
   _map[_pos] = prev;
   return true
end

function drop_bomb(_pos, _map)
   if is_near_something_destructible(_pos, _map) and can_drop_bomb(_pos, _map) then
      return enum["BOMB"]
   end
   return enum["NONE"]
end


-- search for target

function move_to_target(_pos, _map)
   for i = 2, 10 do
      if _pos + i < width * length and (_map[_pos + i] == case["CRATE"] or _map[_pos + i] == case["PLAYER"]) and is_in_danger(_map, _pos + 1) == enum["NONE"] and can_move_toward(_map[_pos + 1]) then
	 return enum["RIGHT"]
      end
      if _pos + i * width < width * length and (_map[_pos + i * width] == case["CRATE"] or _map[_pos + i * width] == case["PLAYER"]) and is_in_danger(_map, _pos + width) == enum["NONE"] and can_move_toward(_map[_pos + width]) then
	 return enum["DOWN"]
      end
      if _pos - i > 0 and (_map[_pos - i] == case["CRATE"] or _map[_pos - i] == case["PLAYER"]) and is_in_danger(_map, _pos - 1) == enum["NONE"] and can_move_toward(_map[_pos - 1])then
	 return enum["LEFT"]
      end
      if _pos - i * width < 0 and (_map[_pos - i * width] == case["CRATE"] or _map[_pos - i *width] == case["PLAYER"]) and is_in_danger(_map, _pos - width) == enum["NONE"] and can_move_toward(_map[_pos - width]) then
	 return enum["UP"]
      end
   end
   return enum["NONE"]
end

-- recup de bonus

-- function check_move(_map, _pos, _dir)
--    if _dir == enum["UP"]
--    then
--       if _map[_pos - width] ~= case["EMPTY"]
--       then
-- 	 return (change_move(_map, _pos))
--       else
-- 	 return (enum["UP"])
--       end
--    elseif _dir == enum["DOWN"]
--    then
--       if _map[_pos + width] ~= case["EMPTY"]
--       then
-- 	 return (change_move(_map, _pos))
--       else
-- 	 return (enum["DOWN"])
--       end
--    elseif _dir == enum["RIGHT"]
--    then
--       if _map[_pos + 1] ~= case["EMPTY"]
--       then
-- 	 return (change_move(_map, _pos))
--       else
-- 	 return (enum["RIGHT"])
--       end
--    elseif _dir == enum["LEFT"]
--    then
--       if _map[_pos - 1] ~= case["EMPTY"]
--       then
-- 	 return (change_move(_map, _pos))
--       else
-- 	 return (enum["LEFT"])
--       end
--    end
-- end

-- function rush_bonus(_map, _pos)
--    local bonus = love_bonus(_map, _pos)
--    if bonus ~= enum["NONE"]
--    then
--       io.write("erteg")
--       io.write("bonus = ", bonus, "\n")
--       if bonus % length < _pos % length
--       then
-- 	 io.write("UP\n")
-- 	 return (check_move(_map, _pos, enum["UP"]))
--       elseif bonus % length == _pos % length
--       then
-- 	 if bonus < _pos
-- 	 then
-- 	    io.write("LEFT\n")
-- 	    return (check_move(_map, _pos, enum["LEFT"]))
-- 	 else
-- 	    io.write("RIGHT\n")
-- 	    return (check_move(_map, _pos, enum["RIGHT"]))
-- 	 end
--       else
-- 	 io.write("DOWN\n")
-- 	 return (check_move(_map, _pos, enum["DOWN"]))
--       end
--    else
--       return (bonus)
--    end
-- end

function run (_dir, _pos, _map)
   local ret = escape_bomb(_map, _pos)
   if ret == enum["NONE"] then
      local ret2 = drop_bomb(_pos, _map)
      if ret2 == enum["NONE"] then
	 return move_to_target(_pos, _map)
      else
	 return ret2
      end
   else
      return ret
   end
end

return (run(dir, pos, map))
