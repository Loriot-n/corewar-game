/*
** live.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 23 18:25:41 2016 CUENAT
** Last update Fri Mar 25 13:28:25 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_live(t_champion *ch,
			char *info,
			int args[MAX_ARGS_NUMBER],
			t_corewar *vm)
{
  t_champion *tmp;

  if (vm->memory[args[0]] == ch->number)
    ch->bool_live = LIVE;
  else
    {
      tmp = ch->next;
      while (tmp != ch)
	{
	  if (tmp->number == vm->memory[args[0]])
	    tmp->bool_live = LIVE;
	  tmp = tmp->next;
	}
    }
  return (ch);
}
