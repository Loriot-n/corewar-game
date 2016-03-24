/*
** my_getnbr.c for tetris in /home/nico/rendu/S02/Unix/PSU_2015_tetris/src/
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Tue Mar  8 14:04:27 2016 Nicolas Loriot
** Last update Tue Mar  8 14:04:27 2016 Nicolas Loriot
*/

#include "gab.h"

int	my_verif(long int *ret, char *str, int *a, int i)
{
  if (str[i] >= '0' && str[i] <= '9')
    {
      if (*ret >= 0)
	*ret = *ret * 10 + (str[i] - '0');
      else
	*ret = *ret * 10 - (str[i] - '0');
      *a = *a + 1;
      if (*a >= 11)
	return (0);
    }
  return (0);
}

int		my_getnbr(char *str, int i)
{
  long int	ret;
  int		a;

  a = 0;
  ret = 0;
  while (str[i] != '\0')
    {
      my_verif(&ret, str, &a, i);
      if (i > 0 && str[i - 1] == '$' && str[i] >= '0' && str[i] <= '9')
	ret = -ret;
      if ((a > 0) && (str[i] < '0' || str[i] > '9'))
	return (ret);
      i = i + 1;
    }
  if (ret > 2147483647 || ret < (-2147483648))
    return (0);
  return (ret);
}

int	my_getnbrkimarche(char *str, char sepchar)
{
  int	nb;
  int	i;

  nb = 0;
  i = 0;
  while (str[i] > '9' && str[i] < '0')
    i = i + 1;
  while ((str[i] != sepchar) && (str[i] != '\0'))
    {
      nb = ((nb + str[i] - 48) * 10);
      i = i + 1;
    }
  nb = nb / 10;
  return (nb);
}
