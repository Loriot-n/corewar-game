/*
** header_error.c for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/src/
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Sun Mar 27 11:35:13 2016 Nicolas Loriot
** Last update Sun Mar 27 11:35:13 2016 Nicolas Loriot
*/

#include "nico.h"
#include "gab.h"
#include "label.h"

int	check_quotes(int fd, char *to_find, char *file)
{
  char	buff[1];
  int	offset;

  ((lseek(fd, whereis(to_find, fd, file, 1) + my_strlen(to_find), SEEK_SET)) < 0)
  ? exit(5): 0;
  while ((read(fd, buff, 1)) > 0)
    {
      if (buff[0] == ' ' || buff[0] == '\t');
      else if (buff[0] == '\"')
	{
	  offset = 0;
	  while (read(fd, buff, 1) > 0)
	    {
	      if (offset == 0 && buff[0] == '\"')
		raise_err("Error : ", to_find, " command empty");
	      else
		return (1);
	    }
	}
      else
	raise_err("Error : Missing quotes in ", to_find, " command");
    }
  return (1);
}

void	check_null(int fd, char *to_find, char *file)
{
  char	buff[1];

  ((lseek(fd, whereis(to_find, fd, file, 1), SEEK_SET)) < 0) ?
  raise_err("Error : No ", to_find, " specified") : 0;
  while (read(fd, buff, 1) > 0)
    {
      if (buff[0] < 33)
	{
	  if (buff[0] != '\n')
	    raise_err("Invalid ", to_find, "command");
	}
      else
	return ;
    }
}

void	check_double_def(int fd, char *to_find, char *file)
{
  if (whereis(to_find, fd, file, 2) == -2)
    raise_err("Error : Multiple definition of ", to_find, " command");
}
