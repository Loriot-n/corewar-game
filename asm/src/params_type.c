/*
** params_type.c for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Thu Mar 24 03:22:20 2016 Nicolas Loriot
** Last update Thu Mar 24 06:12:16 2016 Nicolas Loriot
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
  (a == 1) ? (BIT_SET(n, 2)) : (a == 2) ? (BIT_SET(n, 1)) : (a == 3) ?
    (BIT_SET(n, 1), BIT_SET(n, 2)) : (0);
  (b == 1) ? (BIT_SET(n, 4)) : (b == 2) ? (BIT_SET(n, 3)) : (b == 3) ?
    (BIT_SET(n, 3), BIT_SET(n, 4)) : (0);
  (c == 1) ? (BIT_SET(n, 6)) : (c == 2) ? (BIT_SET(n, 5))
    : (c == 3) ? (BIT_SET(n, 5), BIT_SET(n, 6)) : (0);
  return (n);
}

t_buff		*ope_to_buff(t_ope *call)
{
  t_buff	*this;

  this.ins = call.ins;
  this.nb = call.nb;
  //my_strcpy(this.adr, call.adr);
  return (this);
}
