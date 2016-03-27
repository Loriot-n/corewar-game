/*
** ins_error.c for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Thu Mar 24 06:52:54 2016 Nicolas Loriot
** Last update Sat Mar 26 13:53:33 2016 Nicolas Loriot
*/

#include "nico.h"
#include "gab.h"

int		get_args_type(char **args, op_t this)
{
  int		i;

  i = 0;
  while (args[i])
    {
      if (args[i][0] == LABEL_CHAR && (BIT_CHECK(this.type, T_IND)))
	i++;
      else if (args[i][0] == DIRECT_CHAR && (BIT_CHECK(this.type, T_DIR)))
	i++;
      else if (args[i][0] == 'r' && (BIT_CHECK(this.type, T_REG)))
	i++;
      else
	return (-1);
    }
  return (0);
}

int	bad_adr(char *adr, char **params)
{
  int	i;

  i = 0;
  while (i < 16)
    {
      if (my_strcmp(op_tab[i].mnemonique, adr) == 0)
	{
	}
      i++;
    }
}

int	bad_param(char **params, char *ins)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (params[i])
    {
      while (params[i][j])
	{
	}
    }
}

int	bad_ins(char *line)
{
  int	i;

  i = 0;
  while (i < 16)
    {
      if (!my_strcmp(line, op_tab[i].mnemonique))
	i++;
      else
	return (1);
    }
  return (0);
}
