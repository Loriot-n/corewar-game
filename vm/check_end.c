/*
** main.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Sun Mar 27 16:09:43 2016 CUENAT
*/


#include "include.h"

t_corewar	*ft_end_game_2(t_champion *racine, t_corewar *vm)
{
  t_champion 	*tmp;
  int		nb_die;

  nb_die = 0;
  tmp = racine;
  printf("vm->cycle die %d\n", vm->cycle_die);
  while (racine->next != tmp)
    {
      if (racine->bool_live == NOLIVE && racine->file_name != NULL)
	nb_die++;
      racine = racine->next;
    }
  if (nb_die >= vm->nb_player && vm->nb_player == 1)
    exit(EXIT_SUCCESS);
  if (nb_die == vm->nb_player - 1 && vm->nb_player > 1)
    exit(EXIT_SUCCESS);
  if (vm->nb_live == NBR_LIVE)
    {
      vm->nb_cycle += 1;
      vm->nb_live = 0;
      vm->cycle_die = CYCLE_TO_DIE - (CYCLE_DELTA * vm->nb_cycle);
    }
  vm->cycle_cpt = 0;
  return (vm);
}

int		ft_end_game(t_champion *racine, t_corewar *vm)
{

  if (vm->cycle_die == 0)
    return (NOLIVE);
  if (vm->cycle_cpt >= vm->cycle_die)
    {
      vm = ft_end_game_2(racine, vm);
    }
  return (LIVE);
}
