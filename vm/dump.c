/*
** dump.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "include.h"

void	dump_me(char *memory)
{
  int	i;
  int	j;

  i = -32;
  while ((i += 32) < MEM_SIZE)
    {
      j = -1;
      while (++j < 32 && i + j < MEM_SIZE)
	{
	  if (j != 0)
	    my_putchar(' ');
	  my_putchar("0123456789ABCDEF"[(memory[i + j] >> 4) & 0xF]);
	  my_putchar("0123456789ABCDEF"[memory[i + j] & 0xF]);
	}
      my_putchar('\n');
    }
  exit(EXIT_SUCCESS);
}
