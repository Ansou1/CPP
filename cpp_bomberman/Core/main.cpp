#include "../BomberGUI/BomberGUI.hh"

int		main()
{
  try
    {
      BomberGUI	bb;
      bb.createWindow(1680, 1050);
      bb.intro();
      bb.menu();
    }
  catch (my_exception e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
