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
	  read(fd, &i, sizeof(i));
	}
      printf("%d ", i);
    }
}


int		main(int ac, char **argv)
{
  t_champion	*racine;
  t_corewar	*vm;

  vm = ft_init_vm(argv);
  racine = ft_init_champ(argv);
  ft_load_player(racine, vm);
  return (0);
}
