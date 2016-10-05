#ifndef MESSAGE_H
#define MESSAGE_H

#include "Pool_thread.h"
#include "Plazza.hh"
#include "NamedPipe.hh"
#include "package.hh"
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include "Parser.h"

class Message{
private:
	NamedPipe 	*kitchen;
	NamedPipe 	*reception;
	Package 	*pack;

public:
	Message(const int id);
	~Message();
	bool 	receive_kitchen(Parser &p) const;
	void 	send_reception_command(const TypePizza pizza, const TaillePizza size) const;
	void 	send_reception_fridge(const Fridge & f) const;
	void 	send_cooker_cook(void) const;
	void 	receive_recpetion(Fridge **f, std::string **s) const;
	void 	send_kitchen_command(const std::string & name) const;
	void 	receive_recpetion(Fridge **f, std::string **s, bool &cook_start) const;
};

#endif
