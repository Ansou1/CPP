#include "Machine.hh"
#include <sstream>

enum NetType{ETH, WLAN, LO};

class Network: public Machine{
private:
  std::string HWaddr;
  std::string rxPacket;
  std::string txPacket;
  std::string rxBytes;
  std::string txBytes;
  std::string IpAdd;

public:
  Network(const int &);
  ~Network();

  void update(const int &);
  std::string getHWaddr() const;
  std::string getrxPacket() const;
  std::string gettxPacket() const;
  std::string getrxBytes() const;
  std::string gettxBytes() const;
  std::string getIpAdd() const;
  void setHWaddr(const std::string &, size_t &);
  void setrxBytes(const std::string &, size_t &);
  void settxBytes(const std::string &, size_t &);
  void setIpAdd(const std::string &, size_t &);
};
