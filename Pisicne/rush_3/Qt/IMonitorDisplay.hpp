//
// IMonitorDisplay.hpp for  in /home/daguen_s/rendu/piscine_cpp_rush3
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sat Jan 25 21:21:19 2014 daguen_s
// Last update Sat Jan 25 22:47:08 2014 daguen_s
//

#ifndef _IMONITORDISPLAY_H_
# define _IMONITORDISPLAY_H_

class IMonitorDisplay
{
public:
  virtual ~IMonitorDisplay(){};

  virtual void  refresh() = 0;
};

#endif /* _IMONITORDISPLAY_H_ */
