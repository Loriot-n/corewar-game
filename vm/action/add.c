/*
** add.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 23 22:45:19 2016 CUENAT
** Last update Thu Mar 24 15:07:24 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_add(t_champion *ch,
			char *info,
			int args[MAX_ARGS_NUMBER],
			t_corewar *vm)
{
  ch->action->reg_addr = args[2] - 1;
  ch->action->reg_write = ch->registre[args[0] - 1]
    + ch->registre[args[1] - 1];
  ch->cycle_attente = op_tab[3].nbr_cycles;
  return (ch);
}
