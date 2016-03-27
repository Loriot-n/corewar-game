/*
** formatfunctions2.c for rendu in /home/qwebify/rendu/PSU_2015_my_printf
**
** Made by qwebify
** Login   <qwebify@epitech.net>
**
** Started on  Thu Nov 05 13:52:33 2015 qwebify
** Last update Sun Mar 27 20:05:59 2016 CUENAT
*/

#include "include.h"

void 	print_b(va_list ap)
{
        my_put_nbr_binary(va_arg(ap, int));
}

void	print_x(va_list ap)
{
	my_put_hexa(va_arg(ap, int));
}

void 		print_S(va_list ap)
{
    char	*str;
    int     	i;

    str = va_arg(ap, char *);
    i = 0;
    while (str[i])
    {
        if (str[i] >= 32 && str[i] < 127)
	    my_putchar(str[i]);
        else
        {
          my_putchar('\\');
          if (str[i] < 10)
            my_putstr("00");
          else if (str[i] < 100)
            my_putchar('0');
          my_put_nbr_octal(str[i]);
        }
        i++;
    }
}

void      	my_put_hexa(long long nb)
{
  char	        hexa[100];
  int	        tmp;
  long long	i;
  long long	j;

  i = 0;
  while (nb != 0)
    {
      tmp = nb % 16;
      if (tmp < 10)
	     tmp = tmp + 48;
      else
	     tmp = tmp + 87;
      hexa[i++] = tmp;
      nb = nb / 16;
    }
  j = i - 1;
  while (j >= 0)
    {
      my_putchar(hexa[j]);
      j = j - 1;
    }
}

void      	print_p(va_list ap)
{
    long long	s;

    s = va_arg(ap, long long);
    if (!s)
      my_putstr("(nil)");
    else
    {
      my_putstr("0x");
      my_put_hexa((long long) s);
      }
}
