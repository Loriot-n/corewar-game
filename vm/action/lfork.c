/*
** lfork.c for  in /home/stanislas/CPE_2015_corewar/vm
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Sat Mar 26 21:52:39 2016 CUENAT
** Last update Sat Mar 26 21:52:40 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_lfork(t_champion *ch,
			char *info,
			int args[MAX_ARGS_NUMBER],
			t_corewar *vm)
{
  ch->bool_fork = 1;
  ch->action->mem_addr = ch->pc + args[0];
  ch->cycle_attente = op_tab[14].nbr_cycles;
  return (ch);
}
