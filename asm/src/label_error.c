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
#include "label.h"
#include "gab.h"

void	label_exit(char *name, int line)
{
  my_putstr("label ", STDERR_FILENO);
  my_putstr(name, STDERR_FILENO);
  my_putstr(" undefine line ", STDERR_FILENO);
  my_put_nbr(line);
}

unsigned int	label_exist(char *name, t_label *lbl, int line)
{
  t_label	*label;

  label = lbl;
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

void		double_label(t_label *label)
{
  t_label	*tmp;

  while (label->prev != NULL && label != NULL)
    {
      tmp = label;
      while (tmp->prev != NULL)
	{
	  if ((my_strcmp(label->name, label->prev->name)) == 0)
	    raise_err("Multiple definition", "of label", label->name);
	  else
	    tmp = tmp->prev;
	}
      label = label->prev;
    }
}

void		check_label_chars(char *label)
{
  int		i;
  int		j;
  int		b;

  i = 0;
  while (label[i])
    {
      j = 0;
      b = 0;
      while (LABEL_CHARS[j] && b == 0)
	{
	  if (label[i] == LABEL_CHARS[j])
	    b = 1;
	  else
	    j++;
	}
      i++;
    }
}

void	ommited_cmd(char **parse)
{
  int	y;
  int	lol;

  y = 0;
  lol = 1;
  for (int i = 0 ; parse[i] ; i++)
    printf("%s\n", parse[i]);
  while (op_tab[y].mnemonique)
    {
      if (!my_strcmp(parse[0], op_tab[y].mnemonique))
	lol = 2;
      y++;
    }
  if (lol == 1)
    raise_err("Error : ommited command", NULL, NULL);
}
