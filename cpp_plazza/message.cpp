#include "message.h"

Message::Message(const int id){
  this->kitchen = new NamedPipe(SSTR(id) + FILE1);
  this->reception = new NamedPipe(SSTR(id) + FILE2);
  this->pack = new Package();
}

Message::~Message(){
  delete (this->kitchen);
  delete (this->reception);
  delete (this->pack);
}

bool Message::receive_kitchen(Parser &p) const{
  std::string response;
  int fd;

  fd = open("log", O_WRONLY | O_CREAT | O_APPEND, 0777);
  if (this->kitchen->reads(response) == false){
    return (false);
  }
  p.commands(response);
  write(fd, "{", 1);
  write(fd, response.c_str(), response.size());
  write(fd, "}", 1);
  write(fd, "\n", 1);
  write(fd, SSTR(p.getSize()).c_str(), 1);
  write(fd, "\n", 1);
  close(fd);
  return (true);
}

void 	Message::send_reception_command(const TypePizza pizza, const TaillePizza size) const{
  std::string str;
  int fd;

  fd = open("log", O_WRONLY | O_CREAT| O_APPEND, 0777);
  str = this->pack->getCommandByType(pizza, size);
  write(fd, "send recep commande\n", 19);
  write(fd, str.c_str(), str.size());
  write(fd, "\n", 1);
  close(fd);
  this->reception->writes(str);
}

void 	Message::send_reception_fridge(const Fridge & f) const
{
  std::string str;

  str = this->pack->pack_fridge(f);
  this->reception->writes(str);
}

void 	Message::send_cooker_cook(void) const
{
  std::string tmp;

  this->reception->writes(this->pack->packCook());
}

void 	Message::receive_recpetion(Fridge **f, std::string **s, bool &cook_start) const{
  std::string tmp;

  this->reception->reads(tmp);
  this->pack->unpack(tmp, f, s, cook_start);
}

void 	Message::send_kitchen_command(const std::string & name) const
{
  this->kitchen->writes(name);
}
