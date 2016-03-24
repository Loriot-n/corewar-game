/*
** get_next_line.c for  in /home/cabane_g/rendu/Elem_prog/CPE_2015_getnextline
**
** Made by cabanes gabriel
** Login   <cabane_g@epitech.net>
**
** Started on  Mon Jan  4 13:34:05 2016 cabanes gabriel
** Last update Thu Jan 21 14:21:40 2016 Gabriel Cabanes
*/

#include "gab.h"

char	*my_strcat(char *dest, char *src)
{
  int i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i++;
  while (src[j] != '\0')
    dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}

char		*i(char	*str, int to_alloc, int try)
{
  char          *cpy;
  unsigned int	i;

  i = 0;
  if (try)
    str = "\0";
  if ((cpy = malloc(sizeof(char) * (to_alloc + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      cpy[i] = str[i];
      i++;
    }
  cpy[i] = '\0';
  return (cpy);
}

char		*get_next_line(const int fd)
{
  static int	already_read = 0;
  static int	to_read = 0;
  static char	buff[1 + 1] = "\0";
  static char	*line = "\0";
  static int	cmp = 0;
  static int	to_alloc = 1;
  static int	quit = 0;
  char		*tmp;

  if (to_read >= already_read)
    {
      (1) ? (to_read = 0), (line = i(line, to_alloc++, 0)) : 0;
      if ((already_read = read(fd, buff, 1)) <= 0)
	return ((line[0] == '\0') ? (quit = 1) : (quit = 0),
		(tmp = i(tmp, to_alloc, 1)), (my_strcat(tmp, line)), (line = "\0"),
		(quit) ? (NULL) : (tmp));
    }
  if (buff[to_read] == '\n' || buff[to_read] == '\0')
    {
      (1) ? (tmp = i(tmp, to_alloc, 1)), (cmp = 0), (to_read++),
	(my_strcat(tmp, line)), (line = i(line, to_alloc++, 1)): 0;
      return (tmp);
    }
  line[cmp++] = buff[to_read++];
  return (get_next_line(fd));
}
