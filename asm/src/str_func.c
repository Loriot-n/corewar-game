/*
** str_func.c for corewar_asm in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Tue Mar 22 10:56:01 2016 Nicolas Loriot
** Last update Tue Mar 22 12:55:09 2016 Nicolas Loriot
*/

#include "gab.h"

int	whereis(char *to_find, int fd)
{
  int	i;
  int	ishere;
  char	buff[my_strlen(to_find)];

  ishere = 0;
  ((lseek(fd, 0, SEEK_SET)) < 0) ? exit(EXIT_FAILURE) : 0;
  while (read(fd, buff, 1) > 0)
    {
      if (buff[0] == to_find[0])
	{
	  i = 0;
	  while (i < my_strlen(to_find) && read(fd, buff, 1) > 0)
	    {
	      i++;
	      if (buff[0] != to_find[i])
		break ;
	      else if (i == my_strlen(to_find) - 1)
		return (ishere);
	    }
	}
      ((lseek(fd, ishere + 1, SEEK_SET)) < 0) ? exit(EXIT_FAILURE) : 0;
      ishere++;
    }
  return (-1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putstr(char *str, int out)
{
  if (out == STDERR_FILENO)
    write(STDERR_FILENO, &str, my_strlen(str));
  else if (out == STDOUT_FILENO)
    write(STDOUT_FILENO, &str, my_strlen(str));
  else
    write(out, &str, my_strlen(str));
}

void	raise_err(char *err)
{
  int	i;

  i = 0;
  while (err[i])
    {
      my_putstr(err, STDERR_FILENO);
      i++;
    }
  exit(1);
}

char	*my_calloc(int size)
{
  int	i;
  char	*str;

  i = 0;
  if (!(str = malloc(sizeof(char) * size)))
    raise_err("Can't perform malloc\n");
  while (str[i])
    str[i++] = 0;
  return (str);
}
