#include <QApplication>
#include <QTableWidget>
#include <QTimer>
#include "Machine.hh"
#include "cpuinfo.hh"
#include "infomachine.h"
#include "infomemory.h"
#include "infocpu.h"
#include "infonetwork.h"
#include "IMonitorDisplay.hpp"

int	main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QWidget fenetre;
  InfoMachine i(&fenetre);
  infomemory  im(&fenetre);
  InfoCpu     ic(&fenetre);
  InfoNetwork in(&fenetre);

  QTabWidget *onglets = new QTabWidget(&fenetre);

  onglets->setGeometry(30, 20, 800, 500);

  i.refresh();
  onglets->addTab(i.Page1, "Info system");
  onglets->addTab(im.Page2, "Info Memory");
  onglets->addTab(ic.Page3, "Info CPU" );
  onglets->addTab(in.Page4, "Info Network");

  fenetre.show();

  QTimer *timer = new QTimer(&fenetre);
   QObject::connect(timer, SIGNAL(timeout()), &i, SLOT(refresh()));
   QObject::connect(timer, SIGNAL(timeout()), &im, SLOT(refresh()));
   QObject::connect(timer, SIGNAL(timeout()), &ic, SLOT(refresh()));
   QObject::connect(timer, SIGNAL(timeout()), &in, SLOT(refresh()));
      timer->start(1000);

  return app.exec();
}
