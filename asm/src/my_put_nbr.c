/*
** my_put_nbr.c for ex4 in /home/loriot_n/rendu/Piscine_C_AP
**
** Made by nicolas loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Thu Oct 15 15:35:15 2015 nicolas loriot
** Last update Wed Nov  4 21:37:41 2015 Nicolas Loriot
*/

#include "gab.h"
#include "nico.h"
#include "gab.h"
#include "label.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_put_nbr(int nb)
{
  int  	neg;

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
    {
      my_put_nbr(nb / 10);
    }
  my_putchar(nb % 10 + '0' + neg);
}

int	is_num(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] <= '0' || str[i] >= '9')
	return (0);
      else
	i++;
    }
  return (1);
}

int	is_good_reg(char *str)
{
  if (my_getnbrkimarche(str, 0) > REG_NUMBER)
    return (0);
  else
    return (1);
}
