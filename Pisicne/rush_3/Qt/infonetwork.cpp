#include "infonetwork.h"
#include <QDebug>
InfoNetwork::InfoNetwork(QWidget *parent) :
    QWidget(parent), Network(1)
{
    l_HWaddr = new QLabel(parent);

    l_rxPacket = new QLabel(parent);


    l_txPacket = new QLabel(parent);


    l_rxBytes = new QLabel(parent);


    l_txBytes = new QLabel(parent);


    l_IpAdd = new QLabel(parent);


    layout = new QGridLayout;
    Page4 = new QWidget;

}

void    InfoNetwork::refresh()
{
    std::string tmp("HWaddr :");

    this->Network::update(1);

    tmp.append(HWaddr);

    l_HWaddr->setText(tmp.data());

    layout->addWidget(l_HWaddr, 0, 0);

    tmp = "rxPacket: ";
    tmp.append(rxPacket);

    l_rxPacket->setText(tmp.data());
    layout->addWidget(l_rxPacket, 1, 0);

    tmp = "txPacket: ";
    tmp.append(txPacket);
    l_txPacket->setText(tmp.data());
    layout->addWidget(l_txPacket, 2, 0);

    tmp = "rxBytes: ";
    tmp.append(rxBytes);
    l_rxBytes->setText(tmp.data());
    layout->addWidget(l_rxBytes, 3, 0);
    tmp = "txBytes: ";
    tmp.append(txBytes);
    l_txBytes->setText(tmp.data());
    layout->addWidget(l_txBytes, 4 , 0);
    tmp = "IpAdd: ";
    tmp.append(IpAdd);
    l_IpAdd->setText(tmp.data());
    layout->addWidget(l_IpAdd, 5, 0);

    Page4->setLayout(layout);

}
