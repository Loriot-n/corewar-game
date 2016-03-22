/*
** init_champ.c for  in /home/stanislas/CPE_2015_corewar/vm
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 22 11:03:51 2016 CUENAT
** Last update Tue Mar 22 12:07:04 2016 CUENAT
*/

#include "include.h"

void	ft_init_registre_(int registre[16], int ac)
{
  int	i;

  i = 0;
  registre[0] = ac;
  i++;
  while (i < 16)
    {
      registre[i] = 0;
      i++;
    }
}

t_champion	*ft_add_end(t_champion *cur_champ, int ac, char **av)
{
  t_champion	*new_champ;

  if ((new_champ = malloc(sizeof(t_champion) * 1)) == NULL)
    exit(EXIT_FAILURE);
  new_champ->header = NULL;
  new_champ->action = NULL;
  new_champ->cycle_attente = ac;
  ft_init_registre_(new_champ->registre, ac);
  new_champ->carry = 0;
  new_champ->pc = 0;
  new_champ->bool_live = NOLIVE;
  new_champ->prev = cur_champ;
  new_champ->next = cur_champ->next;
  cur_champ->next->prev = new_champ;
  cur_champ->next = new_champ;
}

t_champion	*ft_create_list_(void)
{
  t_champion	*racine;

  if ((racine = malloc(sizeof(t_champion) * 1)) == NULL)
    exit(EXIT_FAILURE);
  racine->prev = racine;
  racine->next = racine;
  return (racine);
}
