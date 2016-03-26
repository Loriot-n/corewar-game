/*
** exec_action.c for  in /home/stanislas/CPE_2015_corewar/vm
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu Mar 24 15:45:02 2016 CUENAT
** Last update Sat Mar 26 18:26:55 2016 CUENAT
*/

#include "include.h"

void	ft_new_fork_registre(int registre[REG_NUMBER], t_champion *ch)
{
  int	i;

  i = 0;
  while (i < REG_NUMBER)
    {
      registre[i] = ch->registre[i];
      i++;
    }
}

void	ft_get_forked(t_champion *ch)
{
  t_champion	*fork;

  ch->bool_fork = 0;
  if ((fork = malloc(sizeof(t_champion))) ==  NULL)
    exit(EXIT_FAILURE);
  fork->action = ft_init_action();
  fork->pc = ch->action->mem_addr;
  fork->bool_fork = 0;
  fork->file_name = my_strdup(ch->file_name);
  fork->cycle_attente = 0;
  ft_new_fork_registre(fork->registre, ch);
  fork->carry = ch->carry;
  fork->bool_live = ch->bool_live;
  fork->number = ch->number;
  fork->header = ch->header;
  fork->action = ft_init_action();
  fork->prev = ch->prev;
  fork->next = ch;
  ch->prev->next =fork;
  ch->prev = fork;
}

t_champion	*ft_launch_action(t_champion *ch, t_corewar *vm)
{
  int	i;

  i = 0;
  if (ch->bool_fork == 1)
    ft_get_forked(ch);
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
  (ch->pc < MEM_SIZE) ? (ch->pc) : (ch->pc = 0);
  return (ch);
}

t_champion	*ft_exec_function(t_champion *ch,
				  char *info,
				  int *args,
				  t_corewar *vm)
{
  t_champion	*(*instr[16])(t_champion *ch,
			     char *info,
			     int *args,
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
  if (IS_INSTRUC(args[4]))
    ch = (instr[args[4]])(ch, info, args, vm);
  return (ch);
}
