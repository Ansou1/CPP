function abs (nb)
   if nb < 0
   then
      return (nb * -1)
   else
      return (nb)
   end
end

function run (_dir, _pos, _map)
   -- local danger = is_in_danger
   -- if danger == 1 then 

   local bonus = love_bonus(_map, _pos)
   print(bonus)
   print(_pos)
   if bonus ~= -1
   then
      if bonus < _pos
      then
	 if bonus % length ~= _pos % length
	 then
	    return (go_up())
	 else
	    if bonus < _pos
	    then
	       return (go_left)
	    else
	       return (go_right)
	    end
	 end
      else
	 if bonus % length ~= _pos % length
	 then
	    return (go_down())
	 else
	    if bonus < _pos
	    then
	       return (go_left())
	    else
	       return (go_right())
	    end
	 end
      end
   end
end

print(abs(-125))
print(abs(12))
