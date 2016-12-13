#include "infomemory.h"
#include "Memory.hh"

infomemory::infomemory(QWidget *parent) :
    QWidget(parent), Memory()
{
    l_memory_max = new QLabel(parent);
    l_memory_free = new QLabel(parent);
    l_memory_swap = new QLabel(parent);
    l_memory_cached = new QLabel(parent);
    layout = new QVBoxLayout;
    Page2 = new QWidget;
}
void    infomemory::refresh()
{
    std::string tmp("Memory max :");
    this->Memory::update();
    tmp.append(_memory_max);
    l_memory_max->setText(tmp.data());
    layout->addWidget(l_memory_max);
    tmp = "Memory free: ";
    tmp.append(_memory_free);
    l_memory_free->setText(tmp.data());
    layout->addWidget(l_memory_free);
    tmp = "Memory Swap: ";
    tmp.append(_memory_swap);
    l_memory_swap->setText(tmp.data());
    layout->addWidget(l_memory_swap);
    tmp = "Memory cached: ";
    tmp.append(_memory_cached);
    l_memory_cached->setText(tmp.data());
    layout->addWidget(l_memory_cached);
    Page2->setLayout(layout);
}
