//
// main.cpp for lo in /home/dell-a_f//projets/suicide/src
// 
// Made by florian dell-aiera
// Login   <dell-a_f@epitech.net>
// 
// Started on  Sun Mar 10 10:52:50 2013 florian dell-aiera
// Last update Sun Mar 10 16:32:30 2013 florian dell-aiera
//

#include	<QtGui>
#include	<QApplication>
#include	"MainWindow.hh"
#include	"../headers/Core.hh"

int		main(int ac, char **av)
{
  QApplication	app(ac, av);
  Core		*c;

  c = new Core();
  MainWindow	*window = new MainWindow(c);
  window->show();
  return app.exec();
}
