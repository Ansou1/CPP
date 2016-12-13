//
// Memory.hh for  in /home/daguen_s/rendu/piscine_cpp_rush3
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Sat Jan 25 13:48:53 2014 daguen_s
// Last update Sat Jan 25 21:38:33 2014 florian
//

#ifndef _MEMORY_H_
# define _MEMORY_H_

#include "Machine.hh"

class Memory : public Machine
{
protected:
    std::string		_memory_max;
    std::string		_memory_free;
    std::string		_memory_swap;
    std::string		_memory_cached;

public:
    Memory();
    Memory(const Memory &);
    virtual ~Memory();

    Memory		&operator=(Memory const &);

    std::string		getM() const;
    std::string		getF() const;
    std::string		getS() const;
    std::string		getC() const;

    void		setM();
    void		setF();
    void		setS();
    void		setC();

    void		update();
};

#endif /* _MEMORY_H_ */

