/*
** str_func.c for corewar_asm in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Tue Mar 22 10:56:01 2016 Nicolas Loriot
** Last update Tue Mar 22 15:44:25 2016 Nicolas Loriot
*/

#include "gab.h"
#include "nico.h"
#include "label.h"

int	whereis(char *to_find, int fd, char *file_name, int yolo)
{
  int	i;
  int	ishere;
  char	buff[my_strlen(to_find)];

  ishere = 0;
  if ((lseek(fd, yolo, SEEK_SET)) < 0)
    raise_err("File ", file_name, " not accessible\n");
  while ((read(fd, buff, 1) > 0 && ++ishere))
    {
      if (buff[0] == to_find[0])
	{
	  i = 0;
	  while (i < my_strlen(to_find) && read(fd, buff, 1) > 0)
	    {
	      i++;
	      if (buff[0] != to_find[i])
		break ;
	      else if ((i == my_strlen(to_find) - 1))
		return (ishere - 1);
	    }
	}
      if ((lseek(fd, ishere + yolo, SEEK_SET)) < 0)
       raise_err("File ", file_name, " not accessible\n");
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
  int	i;

  i = 0;
  if (!str)
    return ;
  while (str[i])
    {
      if (out == STDERR_FILENO)
	write(STDERR_FILENO, &str[i], 1);
      else if (out == STDOUT_FILENO)
	write(STDOUT_FILENO, &str[i], 1);
      else
	write(out, &str[i], 1);
      i++;
    }
}

void	raise_err(char *err, char *name, char *err2)
{
  my_putstr(err, STDERR_FILENO);
  my_putstr(name, STDERR_FILENO);
  my_putstr(err2, STDERR_FILENO);
  my_putchar('\n');
  exit(EXIT_FAILURE);
}

char	*my_calloc(int size)
{
  int	i;
  char	*str;

  i = 0;
  if (!(str = malloc(sizeof(char) * size)))
    raise_err("Can't perform malloc\n", NULL, NULL);
  while (str[i])
    str[i++] = 0;
  return (str);
}
