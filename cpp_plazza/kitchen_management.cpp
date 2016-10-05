#include	"kitchen_management.hh"

int	Kitchen_management::getId() const
{
  return (this->_id);
}

int	Kitchen_management::getPizza() const
{
  return (this->_nbpizza);
}

int	Kitchen_management::getCook() const
{
  return (this->_nbcook);
}

void	Kitchen_management::add_pizza()
{
  this->_nbpizza++;
}

void	Kitchen_management::del_pizza()
{
  this->_nbpizza--;
}

int	Kitchen_management::getMax() const
{
  return (_nbcook * 2);
}

Kitchen_management::Kitchen_management(int id, int nbcook) : _id(id), _nbcook(nbcook)
{
  this->_nbpizza = 0;
}

Kitchen_management::Kitchen_management(const Kitchen_management &old) : _id(old.getId()), _nbcook(old.getCook())
{

}

Kitchen_management &Kitchen_management::operator=(const Kitchen_management &old)
{
  this->_nbpizza = old.getPizza();
  return (*this);
}

Kitchen_management::~Kitchen_management()
{
}

