/*
** label_error.c for label in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/src/
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Fri Mar 25 17:19:31 2016 Nicolas Loriot
** Last update Sat Mar 26 11:07:39 2016 Nicolas Loriot
*/

#include "nico.h"
#include "gab.h"

void	label_exit(char *name, int line)
{
  my_putstr("label ", STDERR_FILENO);
  my_putstr(name, STDERR_FILENO);
  my_putstr(" undefine line ", STDERR_FILENO);
  my_put_nbr(line);
}

unsigned int	label_exist(char *name, t_label *label, int line)
{
  if (label->next == NULL)
    {
      if (label->prev == NULL)
	label_exit(name, line);
    }
  while (label->prev != NULL)
    {
      if (my_strcmp(label->name, name) == 0)
	return (label->pos_lbl);
      label = label->prev;
    }
  return (0);
}

int		double_label(t_label *label)
{
  t_label	*tmp;

  while (label->prev != NULL && label != NULL)
    {
      tmp = label;
      while (tmp->prev != NULL)
	{
	  if ((my_strcmp(label->name, label->prev->name)) == 0)
	    return (1);
	  else
	    tmp = tmp->prev;
	}
      label = label->prev;
    }
  return (0);
}
