/*
** tools.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "include.h"

int	my_getnbr(char *str)
{
  int	rneg[2];

  rneg[1] = ((str[0] == '-') ? -1 : 1);
  rneg[0] = 0;
  while (*str)
    rneg[0] = rneg[0] * 10 + ((*str == '-') ? *(str++) * 0 : *(str++) - 48);
  return (rneg[0] * rneg[1]);
}

int	*calloc_int_tab(int *tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      tab[i] = 0;
      i++;
    }
  return (tab);
}

void	my_putstr_stderr(char *str)
{
  write(2, &str, my_strlen(str));
}

void	*xmalloc(int size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      my_putstr("Can’t perform malloc\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
