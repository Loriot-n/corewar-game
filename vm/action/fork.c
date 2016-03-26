/*
** fork.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu Mar 24 16:03:37 2016 CUENAT
** Last update Sat Mar 26 16:29:55 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_fork(t_champion *ch,
			char *info,
			int args[MAX_ARGS_NUMBER],
			t_corewar *vm)
{
  ch->bool_fork = 1;
  if (info[0] == 'i')
    ch->action->mem_addr = args[0];
  else
    ch->action->mem_addr = ch->pc + (args[0] % IDX_MOD);
  ch->cycle_attente = op_tab[11].nbr_cycles;
  return (ch);
}
