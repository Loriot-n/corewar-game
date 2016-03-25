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

unsigned char	set_param_byte(int det)
{
  unsigned char	n;
  int		a;
  int		b;
  int		c;

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
