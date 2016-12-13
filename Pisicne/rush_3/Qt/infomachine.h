#ifndef INFOMACHINE_H
#define INFOMACHINE_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QProgressBar>
#include <sstream>
#include "Machine.hh"
#include "IMonitorDisplay.hpp"

class InfoMachine :  public QWidget, public Machine, public IMonitorDisplay
{
   QLabel *l_date;
   QLabel *l_name;
   QLabel *l_uname;
   QLabel *l_kernel;
   QVBoxLayout *layout;

   Q_OBJECT
public:
   QWidget *Page1;
public:
    explicit InfoMachine(QWidget *parent = 0);

signals:

public slots:
     void refresh();
};

#endif // INFOMACHINE_H
