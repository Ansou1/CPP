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
