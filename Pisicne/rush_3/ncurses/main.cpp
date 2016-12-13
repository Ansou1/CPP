//
// main.cpp for  in /home/daguen_s/rendu/piscine_cpp_rush3
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sun Jan 26 03:43:24 2014 daguen_s
// Last update Sun Jan 26 09:52:34 2014 daguen_s
//

#include <string>
#include <unistd.h>
#include <ncurses.h>
#include <ncurses/panel.h>
#include <sstream>

#include "IMonitorModule.hpp"
#include "IMonitorModule.hpp"
#include "Machine.hh"
#include "Memory.hh"
#include "NcursesWindow.hh"
#include "Network.hh"
#include "cpuinfo.hh"
#include "NcursesWindow.hh"

int		main()
{
  initscr();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_BLUE, COLOR_WHITE);
  init_pair(3, COLOR_RED, COLOR_WHITE);
  curs_set(0);
  noecho();
  keypad(stdscr,TRUE);

  IMonitorModule	*machine = new Machine();
  IMonitorModule	*cpu = new CpuInfo();
  IMonitorModule	*net = new Network(0);
  IMonitorModule	*net1 = new Network(1);
  IMonitorModule	*net2 = new Network(2);
  IMonitorModule	*net3 = new Network(3);
  IMonitorModule	*net4 = new Network(4);
  IMonitorModule	*memory = new Memory();

  NcursesWindow		CpuWindow(LINES / 3, 4 * (COLS / 4), 0, (LINES / 3));
  NcursesWindow		HddWindow(LINES / 3, 4 * (COLS / 4), 0, 2 * (LINES / 3));
  NcursesWindow		NetWindow(LINES / 3, COLS / 4, 3 * (COLS / 4), 0);
  NcursesWindow		RamWindow(LINES / 3, COLS / 4, 2 * (COLS / 4), 0);
  NcursesWindow		TimeWindow(LINES / 3, COLS / 4, (COLS / 4), 0);
  NcursesWindow		UserWindow(LINES / 3, COLS / 4, 0, 0);

  CpuWindow.setTitre("| CPU |");
  HddWindow.setTitre("| Miscellanous |");
  NetWindow.setTitre("| Network |");
  RamWindow.setTitre("| Ram Memory |");
  TimeWindow.setTitre("| Time Infos |");
  UserWindow.setTitre("| Basic Infos |");

  UserWindow.setBkgd(COLOR_PAIR(2));
  TimeWindow.setBkgd(COLOR_PAIR(1));
  RamWindow.setBkgd(COLOR_PAIR(1));
  CpuWindow.setBkgd(COLOR_PAIR(2));
  NetWindow.setBkgd(COLOR_PAIR(2));
  HddWindow.setBkgd(COLOR_PAIR(1));

  while (1)
    {
      ((CpuInfo*)cpu)->update();
      ((Network*)net)->update(0);
      ((Network*)net1)->update(1);
      ((Network*)net2)->update(2);
      ((Network*)net3)->update(3);
      ((Network*)net4)->update(4);
      ((Memory*)memory)->update();
      ((Machine*)machine)->update();

      UserWindow.clearWindow();
      UserWindow.putText("User: " + ((Machine*)machine)->getName());
      UserWindow.putText("\nHost: " +((Machine*)machine)->getUname());
      UserWindow.putText("\nKernel: " + ((Machine*)machine)->getKernel());
      UserWindow.displayWindow();

      CpuWindow.clearWindow();
      CpuWindow.putText(((CpuInfo*)cpu)->getModel());
      std::ostringstream tmp;
      tmp << ((CpuInfo *)cpu)->getNb();
      CpuWindow.putText("\nNbr Processor => " + tmp.str());
      std::vector<Cpu>::const_iterator it = ((CpuInfo *)cpu)->getLcpu().begin();
      int a;
      a = 0;

      while (a < ((CpuInfo *)cpu)->getNb())
	{
	  CpuWindow.putText("\nName Processor => " + (*it).getName());
	  CpuWindow.putText("\nfrequence => " + (*it).getMhz());
	  std::ostringstream tmp;
	  tmp << (*it).getPourc();
	  CpuWindow.putText("\nPurcent => " + tmp.str());
	  it++;
	  a++;
	}
      CpuWindow.displayWindow();

      NetWindow.clearWindow();
      NetWindow.putText("HWaddr =>\t" + ((Network*)net)->getHWaddr());
      NetWindow.putText("\ntx Packet =>\t" + ((Network*)net2)->gettxPacket());
      NetWindow.putText("\nrx Packet =>\t" + ((Network*)net1)->getrxPacket());
      NetWindow.putText("\ntx Bytes =>\t" + ((Network*)net4)->gettxBytes());
      NetWindow.putText("\nrx Bytes =>\t" + ((Network*)net3)->getrxBytes());
      NetWindow.putText("\n\nIP =>\t\t" + ((Network*)net1)->getIpAdd());
      NetWindow.putText("\nIP =>\t\t" + ((Network*)net2)->getIpAdd());
      NetWindow.displayWindow();

      RamWindow.clearWindow();
      RamWindow.putText(" Memory Max =>\t\t" + ((Memory*)memory)->getM());
      RamWindow.putText("\n Memory Free =>\t\t" + ((Memory*)memory)->getF());
      RamWindow.putText("\n Memory Swap =>\t\t" + ((Memory*)memory)->getS());
      RamWindow.putText("\n Memory cached =>\t" + ((Memory*)memory)->getC());
      RamWindow.displayWindow();

      TimeWindow.clearWindow();
      TimeWindow.putText("Date: " + ((Machine*)machine)->getDate());
      TimeWindow.displayWindow();

      HddWindow.clearWindow();
      HddWindow.putText(" Present Battery =>\t" + ((Machine*)machine)->getPresent_Battery());
      HddWindow.putText("\n Current Battery =>\t" + ((Machine*)machine)->getCurrent_Battery());
      HddWindow.putText("\n Full Battery =>\t" + ((Machine*)machine)->getFull_Battery());
      HddWindow.putText("\n Battery Percent =>\t" + ((Machine*)machine)->getPer());
      HddWindow.displayWindow();

      sleep(1);
    }
  endwin();

  return (0);
}
