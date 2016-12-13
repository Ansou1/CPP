#include "infomachine.h"
#include <QDebug>
#include <QString>

InfoMachine::InfoMachine(QWidget *parent) :
    QWidget(parent), Machine()
{
   l_date = new QLabel(parent);
   l_name = new QLabel(parent);
   l_uname = new QLabel(parent);
   l_kernel = new QLabel(parent);
   layout = new QVBoxLayout;
   Page1 = new QWidget;
}

void    InfoMachine::refresh()
{
    this->init();
    l_date->setText(_date.data());
    layout->addWidget(l_date);
    l_name->setText(_name.data());
    layout->addWidget(l_name);
    l_uname->setText(_uname.data());
    layout->addWidget(l_uname);
    l_kernel->setText(_kernel.data());
    layout->addWidget(l_kernel);
    Page1->setLayout(layout);
}
