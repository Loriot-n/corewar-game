/*
** params_type.c for cosxépé in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/src/
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Fri Mar 25 13:01:31 2016 Nicolas Loriot
** Last update Fri Mar 25 13:01:31 2016 Nicolas Loriot
*/

#include "nico.h"
#include "gab.h"

int	get_det(char **parse)
{
  int	det;
  int	i;

  det = 0;
  i = 1;
  while (parse[i])
    {
      if ((!my_strcmp(parse[0], "live") ||
	   !my_strcmp(parse[0], "lfork") ||
	   !my_strcmp(parse[0], "zjmp") ||
	   !my_strcmp(parse[0], "fork")))
	return (-1);
      else if (parse[i][0] == '%')
	(i == 1) ? (det += 200) : (i == 2) ? (det += 20) : (i == 3) ?
	  (det += 2) : 0;
      else if (parse[i][0] == 'r')
	(i == 1) ? (det += 100) : (i == 2) ? (det += 10) : (i == 3) ?
	  (det += 1) : 0;
      else if (!sub_cmp(parse[i][0], LABEL_CHARS))
	(i == 1) ? (det += 300) : (i == 2) ? (det += 30) : (i == 3) ?
	  (det += 3) : 0;
      i++;
    }
  return (det);
}

unsigned char	set_param_byte(int det)
{
  unsigned char	n;
  int		a;
  int		b;
  int		c;

  if (det == -1)
    return (-1);
  n = 0;
  a = det / 100;
  b = (det % 100) / 10;
  c = det % 10;
  (a == 1) ? (BIT_CLEAR(n, 7), BIT_SET(n, 6)) : (a == 2) ? (BIT_SET(n, 7)) :
      (a == 3) ? (BIT_SET(n, 7), BIT_SET(n, 6)) : (0);
  (b == 1) ? (BIT_SET(n, 4)) : (b == 2) ? (BIT_SET(n, 5)) :
      (b == 3) ? (BIT_SET(n, 5), BIT_SET(n, 4)) : (0);
  (c == 1) ? (BIT_SET(n, 2)) : (c == 2) ? (BIT_SET(n, 3)) :
      (c == 3) ? (BIT_SET(n, 3), BIT_SET(n, 2)) : (0);
  return (n);
}
