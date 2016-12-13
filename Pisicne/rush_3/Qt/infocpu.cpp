#include "infocpu.h"
#include <QDebug>
#include <QString>

InfoCpu::InfoCpu(QWidget *parent) :
    QWidget(parent), CpuInfo()
{
    l_nb = new QLabel(parent);
    l_model = new QLabel(parent);
    layout = new QVBoxLayout;
    Page3 = new QWidget;

    l_name = new std::vector<QLabel*>(nb);
    l_pourc = new std::vector<QLabel*>(nb);
    l_mhZ = new std::vector<QLabel*>(nb);
    int i = 0;
   while (i < nb)
   {
      (*l_name)[i] = (new QLabel(parent));
      i++;
   }
  i = 0;
  while (i < nb)
  {
     (*l_pourc)[i] = (new QLabel(parent));
     i++;
  }
  i = 0;
  while (i < nb)
  {
     (*l_mhZ)[i] = (new QLabel(parent));
     i++;
  }
}

void    InfoCpu::refresh()
{
    this->CpuInfo::update();
    std::ostringstream oss;
    oss << "Number of Core: " << nb;
     l_nb->setText(QString::fromStdString(oss.str()));
    layout->addWidget(l_nb);
    std::string tmp;
    tmp = "Model: ";
    tmp.append((_model.data()));
    l_model->setText(tmp.data());
    layout->addWidget(l_model);
    oss.str("");
    int i;
    i = 0;
    while (i < nb)
    {
        oss << "Cpu n°" << i << " Name: " << lcpu[i].getName();
        (*l_name)[i]->setText(QString::fromStdString(oss.str()));
         layout->addWidget((*l_name)[i]);
        oss.str("");
        oss.clear();
        oss << lcpu[i].getPourc() << "%";
        (*l_pourc)[i]->setText(QString::fromStdString(oss.str()));
        layout->addWidget((*l_pourc)[i]);
        oss.str("");
        oss.clear();
        oss << "Fréquence: " << lcpu[i].getMhz();
        (*l_mhZ)[i]->setText(QString::fromStdString(oss.str()));
        layout->addWidget((*l_mhZ)[i]);
        oss.str("");
        oss.clear();
       i++;
    }

    Page3->setLayout(layout);
}
