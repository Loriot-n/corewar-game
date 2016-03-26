/*
** live.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 23 18:25:41 2016 CUENAT
** Last update Sat Mar 26 19:33:06 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_live(t_champion *ch,
			char *info,
			int *args,
			t_corewar *vm)
{
  t_champion *tmp;

  if (vm->memory[args[0]] == ch->number)
    {
      printf("\"Le joueur %d (%s) est en vie\n",
	     ch->number, ch->file_name);
      ch->bool_live = LIVE;
    }
  else
    {
      tmp = ch->next;
      while (tmp != ch)
	{
	  if (tmp->number == vm->memory[args[0]])
	    {
	      printf("\"Le joueur %d (%s) est en vie\n",
		     ch->number, ch->file_name);
	      tmp->bool_live = LIVE;
	      break;
	    }
	  tmp = tmp->next;
	}
    }
  ch->cycle_attente = op_tab[0].nbr_cycles;
  return (ch);
}
