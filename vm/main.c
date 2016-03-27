/*
** main.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Sun Mar 27 16:25:46 2016 CUENAT
*/

#include "include.h"

void		ft_run_game(t_champion *racine, t_corewar *vm)
{
  t_champion	*tmp;
  int		start;

  start = 0;
  tmp = racine->next;
  while (ft_end_game(tmp, vm) == LIVE)
    {
      if (tmp == racine)
	{
	  tmp = tmp->next;
	  vm->cycle_cpt++;
	}
      (vm->cycle_cpt == vm->dump_cycle) ? dump_me(vm->memory): 0;
      if (start == 0)
	tmp = ft_load_action(tmp, vm);
      if (tmp->cycle_attente == 0)
	{
	  tmp = ft_launch_action(tmp, vm);
	  tmp = ft_load_action(tmp, vm);
	}
      if (tmp->cycle_attente > 0)
	tmp->cycle_attente--;
      tmp = tmp->next;
      start = 1;
    }
}

short	extract_short_from_mem(char *str, int len)
{
  int	i;
  short	result;

  i = 0;
  result = 0;
  while (i < len)
    {
      result *= 10;
      result += str[i];
      i++;
    }
  return (result);
}

int	extract_from_mem(char *str, int len)
{
  int	i;
  int	result;

  i = 0;
  result = 0;
  while (i < len)
    {
      result *= 10;
      result += str[i];
      i++;
    }
  return (result);
}

void	usage(char *argv)
{
  my_putstr("Usage: corewar [-dump nbr_cycle] [[-n prog_number]");
  my_putstr(" [-a load_address ] prog_name] ...\n");
  exit(EXIT_FAILURE);
}

int		main(int ac, char **argv)
{
  t_champion	*racine;
  t_corewar	*vm;

  if (ac == 1)
    usage(argv[1]);
  vm = ft_init_vm(argv);
  racine = ft_init_champ(argv);
  ft_load_player(racine, vm);
  ft_run_game(racine, vm);
  return (0);
}
