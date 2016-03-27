/*
** defunctions.c for rendu in /home/qwebify/rendu/PSU_2015_my_printf
**
** Made by qwebify
** Login   <qwebify@epitech.net>
**
** Started on  Thu Nov 05 09:49:09 2015 qwebify
** Last update Sun Mar 27 20:05:16 2016 CUENAT
*/

#include "include.h"

void	print_X(va_list ap)
{
        my_put_hexa_maj(va_arg(ap, int));
}

void      	my_put_hexa_maj(long long nb)
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
	     tmp = tmp + 55;
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

int	good_display(int i, va_list ap, char *flags,
		      void (*display[15])(va_list ap))
{
  	flags = flags;
	display[i](ap);
        return (1);
}

int	bad_display(char format)
{
  	if (format != ' ')
    	{
	  my_putchar('%');
	  my_putchar(format);
	}
  	return (0);
}
