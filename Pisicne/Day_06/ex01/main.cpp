//
// main.cpp for ex_01 in /home/daguen_s/rendu/piscine_cpp_d06/ex01
//
// Made by daguen_s
// Login   <daguen_s@epitech.net>
//
// Started on  Mon Jan 13 09:43:16 2014 daguen_s
// Last update Mon Jan 13 10:18:40 2014 daguen_s
//

#include <iomanip>
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
  std::string scale;
  float temp;
  float result;

  std::cin >> temp >> scale;
  std::cout << std::fixed;
   if (scale == "Celsius")
    {
      result = (temp * 9.0 / 5.0) + 32;
      std::cout << std::setw(16) << std::setprecision(3) << result << std::setw(16) << "Fahrenheit" << std::endl;
    }
  else if (scale == "Fahrenheit")
    {
      result = (5.0 / 9.0 * (temp - 32.0));
      std::cout << std::setw(16) <<std::setprecision(3) << result << std::setw(16) << "Celsius" << std::endl;
    }
  return (0);
}
