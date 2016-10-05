//
// main.cpp<2> for lol in /home/lerman_v/Git/C++/cpp_bomberman/BomberGUI
// 
// Made by lerman_v
// Login   <lerman_v@epitech.net>
// 
// Started on  Mon May 26 16:15:49 2014 lerman_v
// Last update Fri Jun 13 15:43:04 2014 Boulot
//

#include "BomberGUI.hh"

int	main()
{
  BomberGUI	GUI;

  GUI.createWindow(1680, 1050);
  GUI.setCamera(glm::vec3(40,25,100));
  GUI.intro();
  while (GUI.update())
    {
      GUI.draw();
    }
  return 0;
}
