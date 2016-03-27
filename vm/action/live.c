/*
** live.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 23 18:25:41 2016 CUENAT
** Last update Sun Mar 27 16:13:53 2016 CUENAT
*/

#include "include.h"

t_champion	*ft_live(t_champion *ch,
			char *info,
			int *args,
			t_corewar *vm)
{
  t_champion 	*tmp;

  vm->nb_live += 1;
  printf("\"Le joueur %d (%s) est en vie\"\n",
	 args[0], ch->file_name);
  if (args[0] == ch->number && ch->file_name != NULL)
    {
      printf("%s\n", ch->file_name);
      ch->bool_live = LIVE;
      printf("%d\n", ch->bool_live);
    }
  else
    {
      tmp = ch;
      while (ch->next != tmp)
	{
	  if (ch->is_root == 0)
	    {
	      if (ch->number == args[0] && ch->file_name != NULL)
		{
		  ch->bool_live = LIVE;
		  break;
		}
	    }
	  ch = ch->next;
	}
    }
  ch->cycle_attente = op_tab[0].nbr_cycles;
  return (ch);
}
