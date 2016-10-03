/*
** main.c for main in /home/daguen_s/rendu/piscine_cpp_d01/ex01
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Wed Jan  8 11:08:33 2014 daguen_s
** Last update Wed Jan  8 16:03:58 2014 daguen_s
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "bitmap.h"
#include "drawing.h"

void	menger(unsigned int **img, int square_size, int level, int x, int y);

int	my_atoi(char *str)
{
  int	nbr;

  if (*str == '-')
    return (-my_atoi(str + 1));
  if (*str == '+')
    return (my_atoi(str + 1));
  nbr = 0;
  while (*str >= '0' && *str <= '9')
    nbr = nbr * 10 + (*(str++) - '0');
  return (nbr);
}

int			main(int ac, char **av)
{
  t_bmp_header		header;
  t_bmp_info_header	info;
  size_t		size;
  size_t		level;
  unsigned int		*buffer;
  unsigned int		**img;
  int			fd;
  t_point		p = {0,0};

  if (ac != 4)
    {
      write(1, "menger_face file_name size level\n", 33);
      return 1;
    }
  size = my_atoi(av[2]);
  level = my_atoi(av[3]);
  make_bmp_header(&header, size);
  make_bmp_info_header(&info, size);

  buffer = malloc(size * size * sizeof(*buffer));
  img = malloc(size * sizeof(*img));
  memset(buffer, 0, size * size * sizeof(*buffer));
  for (size_t i = 0; i < size; ++i)
    img[i] = buffer + i * size;

  draw_square(img, &p, size, 0x00000000);

  menger(img, size, level, 0, 0);

  fd = open(av[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
  write(fd, &header, sizeof(header));
  write(fd, &info, sizeof(info));
  write(fd, buffer, size * size * sizeof(*buffer));
  close(fd);
  return 0;
}
