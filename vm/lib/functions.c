/*
** functions.c for rendu in /home/qwebify/rendu/PSU_2015_my_printf
**
** Made by qwebify
** Login   <qwebify@epitech.net>
**
** Started on  Tue Nov 03 15:30:06 2015 qwebify
** Last update Sun Mar 27 20:06:29 2016 CUENAT
*/

#include "include.h"

void		my_putchar(char c)
{
  if (write(1, &c, 1))
    compteur++;
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_put_nbr(int nb)
{
  int	neg;

  neg = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
        {
          neg = 1;
          nb = nb + 1;
        }
      nb = nb * -1;
    }
  if (nb >= 10)
      my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0' + neg);
}

void    my_put_nbr_binary(int nb)
{
  int   neg;

  neg = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
        {
          neg = 1;
          nb = nb + 1;
        }
      nb = nb * -1;
    }
  if (nb > 0)
      my_put_nbr_binary(nb / 2);
  my_putchar(nb % 2 + '0' + neg);
}

void    my_put_nbr_octal(int nb)
{
  int   neg;

  neg = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
        {
          neg = 1;
          nb = nb + 1;
        }
      nb = nb * -1;
    }
  if (nb > 8)
      my_put_nbr_octal(nb / 8);
  my_putchar(nb % 8 + '0' + neg);
}
