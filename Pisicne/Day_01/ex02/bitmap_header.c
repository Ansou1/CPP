/*
** bitmap_header.c for header in /home/daguen_s/rendu/piscine_cpp_d01/ex02
**
** Made by daguen_s
** Login   <daguen_s@epitech.net>
**
** Started on  Wed Jan  8 17:31:02 2014 daguen_s
** Last update Wed Jan  8 17:31:04 2014 daguen_s
*/

#include <stdlib.h>
#include "bitmap.h"

void	make_bmp_header(t_bmp_header *header, size_t size)
{
  header->magic = 0x4D42;
  header->size = size * size * 4 + sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
  header->_app1 = 0;
  header->_app2 = 0;
  header->offset =  sizeof(t_bmp_header) + sizeof(t_bmp_info_header);
}

void	make_bmp_info_header(t_bmp_info_header *header, size_t size)
{
  header->size = 40;
  header->width = size;
  header->height = size;
  header->planes = 1;
  header->bpp = 32;
  header->compression = 0;
  header->raw_data_size = size * size * 4;
  header->h_resolution = 0;
  header->v_resolution = 0;
  header->palette_size = 0;
  header->important_colors = 0;
}
