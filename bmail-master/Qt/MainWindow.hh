#ifndef		__MAINWINDOW_HH__
#define		__MAINWINDOW_HH__

#include	<QtGui>
#include	<iostream>
#include	<list>
#include	"../headers/Core.hh"

class		MainWindow : public QWidget
{
  Q_OBJECT
  
  public:
  MainWindow(Core *c);
  void	  QInitObj();
  void	  AddRow();

private slots:
  void	sendmsg() const;

private:
  Core		*core;
  QFormLayout	*box;
  QTabWidget	*onglets;
  QWidget	*boxmail;
  QCheckBox	*m;
  QWidget	*send;
  QLineEdit	*Ip;
  QLineEdit	*Port;
  QLineEdit	*rec;
  QLineEdit	*From;
  QLineEdit	*obj;
  QTextEdit	*msg;
  QPushButton	*msgenvoi;
};

#endif
