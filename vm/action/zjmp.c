/*
** zjmp.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu Mar 24 00:12:07 2016 CUENAT
** Last update Fri Mar 25 17:42:01 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_zjmp_2(t_champion *ch)
{
  int	tmp;

  if (ch->pc < 0)
    {
      tmp = 0 - ch->pc;
      ch->pc = MEM_SIZE;
      while (tmp != 0)
	{
	  ch->pc--;
	  tmp++;
	}
    }
  if (ch->pc > MEM_SIZE)
    {
      tmp = MEM_SIZE - ch->pc;
      ch->pc = MEM_SIZE;
      while (tmp != 0)
	{
	  ch->pc++;
	  tmp--;
	}
    }
  return (ch);
}

t_champion	*ft_zjmp(t_champion *ch,
			 char *info,
			 int args[MAX_ARGS_NUMBER],
			 t_corewar *vm)
{
  if (ch->carry == 1)
    {
      ch->pc = ch->pc + (args[0] % IDX_MOD);
      ch = ft_zjmp_2(ch);
      ch->cycle_attente = op_tab[8].nbr_cycles;
    }
  return (ch);
}
