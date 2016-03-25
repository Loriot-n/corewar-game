/*
** xor.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Fri Mar 25 11:01:03 2016 CUENAT
** Last update Fri Mar 25 11:01:07 2016 CUENAT
*/

# include "include.h"

t_champion	*ft_xor(t_champion *ch,
			char *info,
			int args[MAX_ARGS_NUMBER],
			t_corewar *vm)
{
  (ch->carry == 1) ? (ch->carry = 0) : (ch->carry = 1);
  ch->action->reg_addr = args[2] - 1;
  if (info[0] == 'I')
    ch->action->reg_write = vm->memory[ch->pc + (args[0] % IDX_MOD)];
  else
    ch->action->reg_write = args[0];
  if (info[1] == 'I')
    ch->action->reg_write =  ch->action->reg_write +
      vm->memory[ch->pc + (args[1] % IDX_MOD)];
  else
    ch->action->reg_write =  ch->action->reg_write + args[1];
  ch->cycle_attente = op_tab[6].nbr_cycles;
  return (ch);
}
