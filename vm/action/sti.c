/*
** sti.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu Mar 24 16:59:14 2016 CUENAT
** Last update Fri Mar 25 17:50:21 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_sti(t_champion *ch,
			char *info,
			int args[MAX_ARGS_NUMBER],
			t_corewar *vm)
{
  if (args[0] < 0 || args[0] > REG_NUMBER || args[1] + args[2] > MEM_SIZE ||
      args[1] + args[2] < 0)
    {
      my_putstr_stderr("Evil sti ! \\o/ \n");
      return (ch);
    }
  ch->action->mem_addr = args[1] + args[2];
  ch->action->mem_size = REG_SIZE;
  ch->action->mem_write = ft_reg_to_mem(ch->registre[args[0] - 1], vm, ch);
  ch->cycle_attente = op_tab[10].nbr_cycles;
  return (ch);
}
