#include	"../headers/Core.hh"

Core::Parse::Parse()
{
  
}

void				Core::Parse::parsing(Core *c)
{
  std::ifstream			fichier("server.conf", std::ios::in);
  std::string			content;
  int				id;
  const std::string		sub_str = ":";
  std::vector<std::string>	infos;
  int				i = 0;
  
  if (fichier)
    {
      while (getline(fichier, content))
	{
	  if ((id = content.find(sub_str, 0)))
	    {
	      id += 2;
	      infos.push_back(content.substr(id, content.size()));
	      i++;
	    }
	}
      if (i == 4)
	{
	  std::stringstream         ss;
	  short unsigned int        port;
	  
	  ss << infos[3];
	  ss >> port;
	  c->setLogin(infos[0]);
	  c->setMdp(infos[1]);
	  c->setIp(infos[2]);
	  c->setPort(port);
	}
      fichier.close();
    }
  else
    std::cerr << "Unable to open: server.conf" << std::endl;
}
