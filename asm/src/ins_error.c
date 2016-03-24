/*
** ins_error.c for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Thu Mar 24 06:52:54 2016 Nicolas Loriot
** Last update Thu Mar 24 09:22:39 2016 Nicolas Loriot
*/

#include "nico.h"
#include "gab.h"

int	bad_param(char **params)
{
  
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
