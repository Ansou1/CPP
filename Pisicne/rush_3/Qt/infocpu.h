#ifndef INFOCPU_H
#define INFOCPU_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QProgressBar>
#include <sstream>
#include <vector>
#include "IMonitorDisplay.hpp"
#include "cpuinfo.hh"

class InfoCpu : public QWidget, public CpuInfo, public IMonitorDisplay
{
    Q_OBJECT

    QLabel *l_nb;
    QLabel *l_model;
    std::vector<QLabel*> *l_name;
    std::vector<QLabel*> *l_pourc;
    std::vector<QLabel*> *l_mhZ;
    QVBoxLayout *layout;
public:
    QWidget *Page3;
    explicit InfoCpu(QWidget *parent = 0);

signals:

public slots:
    virtual void    refresh();
};

#endif // INFOCPU_H
