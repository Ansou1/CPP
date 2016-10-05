#include "gui.hh"

int my_putchar(int i)
{
  return write(1, &i, sizeof(int));
}

Gui::Gui()
{
  this->kitchens = NULL;
  this->wait_list = NULL;
  this->finish_list = NULL;
  int mode;

  mode = fcntl(0, F_GETFL, 0);
  mode |= O_NONBLOCK;
  fcntl(0, F_SETFL, mode);
  this->input = "";
  if(tcgetattr(0, &this->old) < 0)
    std::cerr << "error in gui" << std::endl;
  flush_stream = true;
  rawMode(0);
  if ((this->term = getenv("TERM")) == NULL)
    {
      std::cerr << "Impossible de déterminer le terminal" <<std::endl;
      exit(1);
    }
  if (tgetent(0, this->term) != 1)
    {
      std::cerr << "error tgetent" << std::endl;
    }
  this->home = tgetstr("home", NULL);
}

int Gui::rawMode(const int fd)
{
  struct termios newtermios;

  newtermios = old;
  newtermios.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
  newtermios.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
  newtermios.c_cflag &= ~(CSIZE | PARENB);
  newtermios.c_cflag |= CS8;
  newtermios.c_oflag &= ~(OPOST);
  newtermios.c_cc[VMIN] = 1;
  newtermios.c_cc[VTIME] = 0;
  if(tcsetattr(fd, TCSAFLUSH, &newtermios) < 0)
    return(-1);
  return(0);
}

Gui::~Gui()
{
  tcsetattr(0, TCSAFLUSH, &this->old);
}

void Gui::reload(Manage_kitchen &k)
{
  this->kitchens = k.getKitchens();
  this->wait_list = k.getWait();
  this->finish_list = k.getFinish();
  k.update();
  printf("%c[2J", 27);
  tputs(this->home, 1, my_putchar);
  std::cout << "command:" + this->input << "\r\n";
  for (std::list<std::string 	*>::iterator i = this->wait_list->begin(); i != this->wait_list->end(); ++i){
    std::cout << **i << "\r\n";
  }
}

std::string &Gui::get_input()
{
  int c;
  char buf[10];

  std::string *ret = new std::string;
  if (this->flush_stream)
    this->input = "";
  this->flush_stream = false;
  c = read(0, buf, 4);
  if (buf[0] == 13){
    *ret = this->input;
    this->input = "";
    return (*ret);
  }
  if (c > 0)
    this->input += buf[0];
  *ret = "";
  return *ret;
}
