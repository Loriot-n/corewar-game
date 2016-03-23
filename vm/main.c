/*
** main.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Wed Mar 23 18:22:19 2016 CUENAT
*/

#include "include.h"

int		ft_end_game(t_champion *racine, t_corewar *vm)
{
  t_champion 	*tmp;
  int		nb_die;

  nb = 0;
  tmp = racine->next;
  if (vm->cycle_die == 0)
    return (1);
  if (cycle->cpt == cycle_die)
    {
      while (tmp != racine)
	{
	  if (tmp->live == NOLIVE)
	    nb++;
	  tmp = tmp->next;
	}
      if (nb_die >= vm->nb_player - 1)
	return (1);
      vm->nb_cycle++;
      vm->cycle_die =  CYCLE_TO_DIE - (CYCLE_DELTA * nb_cycle);
    }
  return (0);
}

void		ft_run_game(t_champion *racine, t_corewar *vm)
{
  t_champion	*tmp;

  tmp = racine->next;
  while (ft_end_game(tmp, vm) == LIVE)
    {
      while (tmp != racine)
	{
	  tmp = ft_load_action(tmp, vm);
	}
      tmp = racine->next;
    }
}

void	print_asm(char	*file_name)
{
  char	s;
  int	i;

  int fd = open(file_name, O_RDONLY);
  lseek(fd, sizeof(header_t), SEEK_SET);
  while (read(fd, &s, sizeof(s)) > 0)
    {
      if (s > 0 && s < 16)
	{
	  printf("\n%s(%d arguments)  ", op_tab[s - 1].mnemonique, op_tab[s - 1].nbr_args);
	}
      printf(" %d", s);
    }
}


int		main(int ac, char **argv)
{
  t_champion	*racine;
  t_corewar	*vm;

  print_asm("ex.cor");
  vm = ft_init_vm(argv);
  racine = ft_init_champ(argv);
  ft_load_player(racine, vm);
  ft_run_game(racine, vm);
  return (0);
}
