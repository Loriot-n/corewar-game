/*
** check_args.c for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/src/
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Sat Mar 26 21:55:15 2016 Nicolas Loriot
** Last update Sat Mar 26 21:55:15 2016 Nicolas Loriot
*/

#include "nico.h"
#include "gab.h"
#include "label.h"

int	check_add(char **params)
{
  int	i;

  i = 0;
  while (params[i])
    {
      if (params[i][0] == 'r' && is_good_reg(&params[i][1]))
	i++;
      else
	return (0);
    }
  return (1);
}

int	check_ldi(char **params, t_label *label, int line)
{
  if (params[0][0] == DIRECT_CHAR && params[0][1] == LABEL_CHAR)
    label_exist(&params[0][2], label, line);
  else if (params[0][0] == LABEL_CHAR)
    label_exist(&params[0][1], label, line);
  else if (params[0][0] == 'r' && is_good_reg(&params[0][1]));
  else if (is_num(&params[0][0]));
  else
    return (0);
  if (params[1][0] == DIRECT_CHAR && params[1][1] == LABEL_CHAR)
    label_exist(&params[1][2], label, line);
  else if (params[1][0] == LABEL_CHAR)
    label_exist(&params[1][1], label, line);
  else if (params[1][0] == 'r' && is_good_reg(&params[1][1]));
  else
    return (0);
  if (params[2][0] == 'r' && is_good_reg(&params[2][1]));
  else
    return (0);
  return (1);
}

int	check_sti(char **params, t_label *label, int line)
{
  if (params[2][0] == 'r' && is_good_reg(&params[2][1]));
  else
    return (0);
  if (params[0][0] == DIRECT_CHAR && params[0][1] == LABEL_CHAR)
    label_exist(&params[0][2], label, line);
  else if (params[0][0] == LABEL_CHAR)
    label_exist(&params[0][1], label, line);
  else if (params[0][0] == 'r' && is_good_reg(&params[0][1]));
  else if (is_num(&params[0][0]));
  else
    return (0);
  if (params[1][0] == DIRECT_CHAR && params[1][1] == LABEL_CHAR)
    label_exist(&params[1][2], label, line);
  else if (params[1][0] == LABEL_CHAR)
    label_exist(&params[1][1], label, line);
  else if (params[1][0] == 'r' && is_good_reg(&params[1][1]));
  else
    return (0);
  return (1);
}

int	check_ld(char **params, t_label *label, int line)
{
  if (params[0][0] == DIRECT_CHAR && params[0][1] == LABEL_CHAR)
    label_exist(&params[0][2], label, line);
  else if (params[0][0] == LABEL_CHAR)
    label_exist(&params[0][1], label, line);
  else if (is_num(&params[0][0]));
  else
    return (0);
  if (params[1][0] == 'r' && is_good_reg(&params[1][1]));
  else
    return (0);
  return (1);
}

int	check_st(char **params, t_label *label, int line)
{
  if (params[0][0] == 'r' && is_good_reg(&params[0][1]));
  else
    return (0);
  if (params[1][0] == LABEL_CHAR)
    label_exist(&params[1][1], label, line);
  else if (is_num(&params[1][0]));
  else if (params[1][0] == 'r' && is_good_reg(&params[1][1]));
  else
    return (0);
  return (1);
}
