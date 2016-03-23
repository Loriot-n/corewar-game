/*
** st.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 23 21:07:02 2016 CUENAT
** Last update Wed Mar 23 21:21:43 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_st(t_champion *ch,
		       char *info,
		       int args[MAX_ARGS_NUMBER],
		       t_corewar *vm)
{
  if (args[1] == 'R')
    {
      ch->action->reg_addr = args[0] - 1;
      ch->action->reg_write = ch->registre[args[0] - 1];
    }
  else
    {
      ch->action->mem_addr = args[1];
      ch->action->mem_write = ft_memcpy(ch->registre[args[0] - 1], vm, ch);
    }
  return (ch);
}
