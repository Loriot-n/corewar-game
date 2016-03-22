/*
** main.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Tue Mar 22 19:06:08 2016 CUENAT
*/

#include "include.h"

int		main(int ac, char **argv)
{
  t_champion	*racine;
  t_corewar	*vm;

  vm = ft_init_vm(argv);
  racine = ft_init_champ(argv);
  ft_load_player(racine, vm);
  return (0);
}
