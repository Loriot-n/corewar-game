/*
** st.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 23 21:07:02 2016 CUENAT
** Last update Fri Mar 25 19:02:37 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_st(t_champion *ch,
		       char *info,
		       int args[MAX_ARGS_NUMBER],
		       t_corewar *vm)
{
  if (info[1] == 'r')
    {
      ch->action->reg_addr = args[0] - 1;
      ch->action->reg_write = ch->registre[args[0] - 1];
    }
  else
    {
      if (info[1] == 'i')
	ch->action->mem_addr = ch->pc + (args[1] % IDX_MOD);
      else
	ch->action->mem_addr = args[1];
      ch->action->mem_write = ft_reg_to_mem(ch->registre[args[0] - 1], vm, ch);
    }
  ch->cycle_attente = op_tab[2].nbr_cycles;
  return (ch);
}
