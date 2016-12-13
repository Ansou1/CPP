#ifndef INFONETWORK_H
#define INFONETWORK_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QProgressBar>
#include <sstream>
#include "Network.hh"
#include "IMonitorDisplay.hpp"

class InfoNetwork : public QWidget, public Network, public IMonitorDisplay
{
    Q_OBJECT
    QLabel *l_HWaddr;
    QLabel *l_rxPacket;
    QLabel *l_txPacket;
    QLabel *l_rxBytes;
    QLabel *l_txBytes;
    QLabel *l_IpAdd;

    QGridLayout *layout;
public:
    QWidget *Page4;
    explicit InfoNetwork(QWidget *parent = 0);

signals:

public slots:
    virtual void   refresh();

};

#endif // INFONETWORK_H
