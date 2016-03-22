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