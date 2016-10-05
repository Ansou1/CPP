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
      print("down left")
      if can_move_toward(_map[_pos + 1]) then
	 return enum["RIGHT"]
      elseif can_move_toward(_map[_pos + width]) then
      	 return enum["DOWN"]
      end
   elseif can_move_toward(_map[_pos - 1 + width]) and is_in_danger(_map, _pos - 1 + width) == enum["NONE"] then
      print("down right")
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
      elseif can_move_toward(_map[_pos - 1]) then
	 return enum["LEFT"]
      else
	 return enum["RIGHT"]
      end
   elseif danger == enum["LEFT"] then
      if can_move_toward(_map[_pos - width]) and is_in_danger(_map, _pos - width) == enum["NONE"] then
	 return enum["UP"]
      elseif can_move_toward(_map[_pos + width]) and is_in_danger(_map, _pos + width) == enum["NONE"] then
	 return enum["DOWN"]
      elseif can_move_toward(_map[_pos + 1]) then
	 return enum["RIGHT"]
      else
	 return enum["LEFT"]
      end
   elseif danger == enum["UP"] then
      if can_move_toward(_map[_pos - 1]) and is_in_danger(_map, _pos - 1) == enum["NONE"] then
	 return enum["LEFT"]
      elseif can_move_toward(_map[_pos + 1]) and is_in_danger(_map, _pos + 1) == enum["NONE"] then
	 return enum["RIGHT"]
      elseif can_move_toward(_map[_pos + width]) then
	 return enum["DOWN"]
      else
	 return enum["UP"]
      end
   elseif danger == enum["DOWN"] then
      if can_move_toward(_map[_pos - 1]) and is_in_danger(_map, _pos - 1) == enum["NONE"] then
	 return enum["LEFT"]
      elseif can_move_toward(_map[_pos + 1]) and is_in_danger(_map, _pos + 1) == enum["NONE"] then
	 return enum["RIGHT"]
      elseif can_move_toward(_map[_pos - width]) then
	 return enum["UP"]
      else
	 return enum["DOWN"]
      end
   elseif danger == enum["ON"] then
      return go_to_safe_corner(_map, _pos)
   end
   return enum["NONE"]
end


-- pose de bombes

-- function is_near_a_crate(_pos, _map)
--    print("near_a_create")
--    return (_map[_pos - 1] == case["CRATE"] or
-- 	   _map[_pos + 1] == case["CRATE"] or
-- 	   _map[_pos - width] == case["CRATE"] or
-- 	   _map[_pos + width] == case["CRATE"])
-- end

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

function abs (nb)
   if nb < 0
   then
      return (nb * -1)
   else
      return (nb)
   end
end

function love_bonus (_map, _pos)
   local prev = -1
   for i = 1, #_map do
      if _map[i] == case["BONUS"]
      then
	 if prev == -1
	 then
	    prev = i
	 else
	    if abs(i - _pos) < abs(i - prev)
	    then
	       prev = i
	    end
	 end
      end
   end
   return (prev)
end


function move_r_l(_map, _pos, bonus)
   if bonus < _pos
   then
      if (bonus + width * (_pos / width)) < _pos
      then
	 return (enum["LEFT"])
      else
	 return (enum["RIGHT"])
      end
   else
      if bonus < (_pos + width * (bonus / width) )
      then
	 return (enum["LEFT"])
      else
	 return (enum["RIGHT"])
      end
   end
end

function change_move(_map, _pos, bonus)
   if bonus < _pos
   then
      -- io.write("LEFT\n")
      return (enum["LEFT"])
   else
      -- io.write("RIGHT\n")
      return (enum["RIGHT"])
   end
end

function check_move(_map, _pos, _dir, bonus)
   if _dir == enum["UP"]
   then
      if _map[_pos - width] == case["EMPTY"] or _map[_pos - width] == case["BONUS"]
      then
	 return (_dir)
      else
	 return (move_r_l(_map, _pos, bonus))
      end
   elseif _dir == enum["DOWN"]
   then
      if _map[_pos + width] == case["EMPTY"] or _map[_pos + width] == case["BONUS"]
      then
	 return (_dir)
      else
	 return (move_r_l(_map, _pos, bonus))
      end
   end
end

function rush_bonus(_map, _pos)
   local bonus = love_bonus(_map, _pos)
   if bonus ~= -1
   then
      -- print (bonus)
      -- print (pos)
      -- print (math.floor(bonus / length))
      -- print (math.floor(_pos /length))
      if (math.floor (bonus / length)) < (math.floor (_pos / length))
      then
   	 return (check_move(_map, _pos, enum["UP"], bonus))
      elseif (math.floor (bonus / length)) == (math.floor(_pos / length))
      then
   	 return (change_move(_map, _pos, bonus))
      elseif bonus / length > _pos / length
      then
   	 return (check_move(_map, _pos, enum["DOWN"], bonus))
      end
   else
      return (enum["NONE"])
   end
end

function run (_dir, _pos, _map)
   local ret =  rush_bonus(_map, _pos)
   -- if  ret == enum["NONE"] then
   --    return drop_bomb(_pos, _map)
   -- end
   return (ret)
end

return (run(dir, pos, map))
