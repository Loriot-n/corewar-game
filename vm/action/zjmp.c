/*
** zjmp.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu Mar 24 00:12:07 2016 CUENAT
** Last update Thu Mar 24 00:25:58 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_zjmp(t_champion *ch,
			 char *info,
			 int args[MAX_ARGS_NUMBER],
			 t_corewar *vm))
{
  if (ch->carry == 1)
    {
      ch->pc = pc + (args[0] % IDX_MOD);
    }
  vm->cycle_attente = op_tab[8].nbr_cycles
}
