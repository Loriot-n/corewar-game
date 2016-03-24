/*
** exec_action.c for  in /home/stanislas/CPE_2015_corewar/vm
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu Mar 24 15:45:02 2016 CUENAT
** Last update Thu Mar 24 18:33:00 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_launch_action(t_champion *ch, t_corewar *vm)
{
  int	i;

  i = 0;
  if (ch->action->reg_addr != -1)
    ch->registre[ch->action->reg_addr] = ch->action->reg_write;
  if (ch->action->mem_addr != -1)
    {
      while (i != ch->action->mem_size)
	{
	  if (i + ch->action->mem_addr > MEM_SIZE)
	    ch->action->mem_addr = 0;
	  vm->memory[i + ch->action->mem_addr] = ch->action->mem_write[i];
	  i++;
	}
    }
  free(ch->action);
  ch->action = ft_init_action();
  return (ch);
}

t_champion	*ft_exec_function(t_champion *ch,
				  char *info,
				  int args[MAX_ARGS_NUMBER],
				  t_corewar *vm)
{
  t_champion	*(*instr[16])(t_champion *ch,
			     char *info,
			     int args[MAX_ARGS_NUMBER],
			     t_corewar *vm);
  instr[0] = &ft_live;
  instr[1] = &ft_ld;
  instr[2] = &ft_st;
  instr[3] = &ft_add;
  instr[4] = &ft_sub;
  instr[5] = &ft_and;
  instr[6] = &ft_or;
  instr[7] = &ft_xor;
  instr[8] = &ft_zjmp;
  instr[9] = &ft_ldi;
  instr[10] = &ft_sti;
  instr[11] = &ft_fork;
  instr[12] = &ft_lld;
  instr[13] = &ft_lldi;
  instr[14] = &ft_lfork;
  instr[15] = &ft_aff;
  (instr[args[0]])(ch, info, args, vm);
  return (ch);
}
