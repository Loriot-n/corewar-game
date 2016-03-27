/*
** free.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "include.h"

void	free_vm(t_corewar *vm)
{
  free(vm->memory);
  free(vm);
}

void		free_champ(t_champion *champion)
{
  t_champion	*temp;

  while (champion != NULL)
    {
      temp = champion->next;
      if (champion->is_root == 0)
	free(champion->action)
      free(champion);
      champion  = temp;
    }
}
