/*
** sub.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 23 22:47:18 2016 CUENAT
** Last update Thu Mar 24 15:06:29 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_sub(t_champion *ch,
			char *info,
			int args[MAX_ARGS_NUMBER],
			t_corewar *vm)
{
  ch->action->reg_addr = args[2] - 1;
  ch->action->reg_write = ch->registre[args[0] - 1]
    - ch->registre[args[1] - 1];
  ch->cycle_attente = op_tab[4].nbr_cycles;
  return (ch);
}
