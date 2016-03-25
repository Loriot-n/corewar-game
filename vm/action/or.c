/*
** and.c for  in /home/stanislas/CPE_2015_corewar/vm/action
1;4205;0c**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 23 22:49:57 2016 CUENAT
** Last update Fri Mar 25 19:10:09 2016 CUENAT
*/

# include "include.h"

t_champion	*ft_or(t_champion *ch,
		       char *info,
		       int args[MAX_ARGS_NUMBER],
		       t_corewar *vm)
{
  char	a;
  char	b;

  ch->action->reg_addr = args[2];
  if (info[0] == 'i')
    a = vm->memory[ch->pc + (args[0] % IDX_MOD)];
  else if (info[0] == 'd')
    a = args[0];
  else
    a = ch->registre[args[0] - 1];
  if (info[1] == 'i')
    b = vm->memory[ch->pc + (args[1] % IDX_MOD)];
  else if (info[1] == 'd')
    b = args[1];
  else
    a = ch->registre[args[1] - 1];
  ch->action->reg_write = a | b;
  return (ch);
}
