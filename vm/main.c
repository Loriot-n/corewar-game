/*
** main.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Tue Mar 22 15:39:51 2016 CUENAT
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
}
