#include "Network.hh"
#include <unistd.h>
#include <algorithm>

Network::Network(const int &type){
  this->HWaddr = "Not defined";
  this->rxPacket = "Not defined";
  this->txPacket = "Not defined";
  this->rxBytes = "Not defined";
  this->txBytes = "Not defined";
  update(type);
}

Network::~Network(){

}

//slpit a string and return the n position
std::string explode_at(const std::string& str, int pos)
{
  std::istringstream split(str);
  std::vector<std::string> tokens;
  for (std::string each; std::getline(split, each, ':'); tokens.push_back(each));
  std::vector<std::string>::iterator it = tokens.begin();
  int i(0);
  for(i=0;i != pos;++it){
    ++i;
  }
  char *tmp = const_cast<char *>((*it).c_str());
  for(i=0;((tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == '.');++i);
  tmp[i] = '\0';
  std::string ret(tmp);
  return ret;
}

//reload the Network attribute.
void Network::update(const int &type){
  char buff[4096];
  FILE *f;
  size_t pos;
  std::string each;

  if (type == ETH)
    f = popen("ifconfig | sed -n '/eth0/,/^$/ p'", "r");
  else if (type == WLAN)
    f = popen("ifconfig | sed -n '/wlan0/,/^$/ p'", "r");
  else
    f = popen("ifconfig | sed -n '/lo/,/^$/ p'", "r");

  while (fgets(buff, sizeof(buff), f) != NULL){
    each = buff;
    if ((pos = each.find("HWaddr")) != std::string::npos)
      this->HWaddr = each.substr(pos + 7, each.size() - pos);
    else if ((pos = each.find("RX packets:")) != std::string::npos)
      this->rxPacket = explode_at(each, 1);
    setHWaddr(each, pos);
    setrxBytes(each, pos);
    settxBytes(each, pos);
    setIpAdd(each, pos);
  }
  pclose(f);
}

std::string Network::getHWaddr() const{
  return this->HWaddr;
}

std::string Network::getrxPacket() const{
  return this->rxPacket;
}

std::string Network::gettxPacket() const{
  return this->txPacket;
}

std::string Network::getrxBytes() const{
  return this->rxBytes;
}

std::string Network::gettxBytes() const{
  return this->txBytes;
}

std::string Network::getIpAdd() const{
  return this->IpAdd;
}

void Network::setHWaddr(const std::string &each, size_t &pos){
  if ((pos = each.find("TX packets:")) != std::string::npos)
    this->txPacket = explode_at(each, 1);
}

void Network::setrxBytes(const std::string &each, size_t &pos){
  if ((pos = each.find("inet addr:")) != std::string::npos)
    this->IpAdd = explode_at(each, 1);
}

void Network::settxBytes(const std::string &each, size_t &pos){
  if ((pos = each.find("RX bytes:")) != std::string::npos)
    this->rxBytes = explode_at(each, 1);
}

void Network::setIpAdd(const std::string &each, size_t &pos){
  if ((pos = each.find("TX bytes:")) != std::string::npos)
    this->txBytes = explode_at(each.substr(pos, each.size() - pos), 1);
}
