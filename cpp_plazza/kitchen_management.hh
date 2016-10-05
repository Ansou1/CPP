#ifndef _KITCHEN_MANAGEMENT_H_
# define _KITCHEN_MANAGEMENT_H_

class Kitchen_management
{
private:
  const int	_id;
  const int	_nbcook;

public:
  int	_nbpizza;
  Kitchen_management(int, int);
  Kitchen_management(const Kitchen_management &old);
  Kitchen_management	&operator=(const Kitchen_management &old);
  virtual		~Kitchen_management();

  int		getId() const;
  int		getCook() const;
  int			getPizza() const;
  int		getMax() const;
  void			add_pizza();
  void			del_pizza();
};

#endif /* _KITCHEN_MANAGEMENT_H_ */
