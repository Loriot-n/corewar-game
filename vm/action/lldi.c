/*
** ldi.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu Mar 24 16:58:03 2016 CUENAT
** Last update Fri Mar 25 19:02:21 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_lldi(t_champion *ch,
			 char *info,
			 int args[MAX_ARGS_NUMBER],
			 t_corewar *vm)
{
  int	i;
  int	start;
  int	end;

  i = 0;
  ch->action->reg_addr = args[2];
  (ch->carry == 0) ? (ch->carry = 1) : (ch->carry = 0);
  ch->cycle_attente = op_tab[9].nbr_cycles;
  while (i < 2)
    {
      if (info[i] == 'i')
	{
	  start = ch->pc + args[i];
	  end = start + IND_SIZE;
	  ch->action->reg_write = ch->action->reg_write +
	      ft_mem_reg(start, end, vm);
	}
      else
	{
	  ch->action->reg_write = ch->action->reg_write +
	    args[i];
	}
    }
  return (ch);
}
