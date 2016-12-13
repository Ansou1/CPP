#ifndef INFOMEMORY_H
#define INFOMEMORY_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QProgressBar>
#include <sstream>
#include "Memory.hh"
#include "IMonitorDisplay.hpp"

class infomemory : public QWidget, public Memory, public IMonitorDisplay
{
    QLabel *l_memory_max;
    QLabel *l_memory_free;
    QLabel *l_memory_swap;
    QLabel *l_memory_cached;
    QVBoxLayout *layout;
    Q_OBJECT
public:
    QWidget *Page2;
    explicit infomemory(QWidget *parent = 0);

signals:

public slots:
    virtual void   refresh();
};

#endif // INFOMEMORY_H
