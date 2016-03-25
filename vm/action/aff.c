/*
** aff.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu Mar 24 14:19:20 2016 CUENAT
** Last update Fri Mar 25 17:13:18 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_aff(t_champion *ch,
			char *info,
			int args[MAX_ARGS_NUMBER],
			t_corewar *vm)
{
  char	a;

  a = ch->registre[args[0] -1] % 256;
  write(1, &a, 1);
  ch->cycle_attente = op_tab[15].nbr_cycles;
  return (ch);
}
