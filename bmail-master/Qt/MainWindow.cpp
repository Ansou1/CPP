#include	<QtGui>
#include	<iostream>
#include	<list>
#include	<sstream>
#include	<QLineEdit>
#include	<QString>
#include	"MainWindow.hh"

void		MainWindow::QInitObj()
{
  this->send = new QWidget;
  this->Ip = new QLineEdit;
  this->Port = new QLineEdit;
  this->From = new QLineEdit;
  this->rec = new QLineEdit;
  this->obj = new QLineEdit;
  this->msg = new QTextEdit;
  this->onglets = new QTabWidget(this);
  this->msgenvoi = new QPushButton("Envoyer");
  this->box = new QFormLayout();
}

void		MainWindow::AddRow()
{
  box->addRow("Ip Serveur:", Ip);
  box->addRow("Port Serveur :", Port);  
  box->addRow("&From :", From);
  box->addRow("&A :", rec);
  box->addRow("&Objet :", obj);
  box->addRow("Message :", msg);
  box->addRow(msgenvoi);
}

void		MainWindow::sendmsg() const
{
  core->sendMail(core, Ip->text().toStdString(), 25, From->text().toStdString(), rec->text().toStdString(), obj->text().toStdString(), msg->toPlainText().toStdString());
  this->From->setText("");
  this->rec->setText("");
  this->obj->setText("");
  this->msg->setText("");
}

MainWindow::MainWindow(Core *c) : QWidget()
{
  this->core = c;
  this->move(200, 0);
  this->QInitObj();
  onglets->setGeometry(50, 50, 700, 500);
  this->Ip->setText("10.42.1.60");
  this->Port->setText("25");
  this->rec->setText("@epitech.eu");
  this->AddRow();
  send->setLayout(box);
  onglets->addTab(send, "Nouveau Message");
  connect(msgenvoi, SIGNAL(clicked()), this, SLOT(sendmsg()));
}
