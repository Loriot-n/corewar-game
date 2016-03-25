/*
** memcpy.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 23 20:39:55 2016 CUENAT
** Last update Fri Mar 25 17:34:39 2016 CUENAT
*/

#include "include.h"

char	*ft_reg_to_mem(int reg_val, t_corewar *vm, t_champion *ch)
{
  char	*tmp;

  if ((tmp = malloc(sizeof(char) * REG_SIZE)) == NULL)
    exit(EXIT_FAILURE);
  ch->action->mem_size = 1;
  tmp = (char)reg_val;
  return (tmp);
}

int	ft_mem_reg(int start, int end, t_corewar *vm)
{
  int	i;

  i = 0;
  while (start != end)
    {
      i = vm->memory[start];
      start ++;
    }
  return (i);
}

char	*ft_memcpy(int start, int end, t_corewar *vm, t_champion *ch)
{
  char	*tmp;
  int	i;

  if ((tmp = malloc(sizeof(char) * (end - start + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (start != end)
    {
      tmp[i] = vm->memory[start];
      i++;
      start++;
    }
  ch->action->mem_size = i - 1;
  return (tmp);
}
