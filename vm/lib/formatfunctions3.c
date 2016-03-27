/*
** formatfunctions3.c for my_printf in /home/qwebify/rendu/PSU_2015_my_printf/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Nov  9 15:06:55 2015 John Doe
** Last update Sun Mar 27 20:06:07 2016 CUENAT
*/

#include "include.h"

void 		print_f(va_list ap)
{
    float	nb;

    nb = va_arg(ap, double);
    my_printf("%d%c%d", (long long int) nb, '.',
      (long long int)(nb * 1000000 - ((long long int)nb)*1000000));
}

void      print_u(va_list ap)
{
  int     nb;

  nb = va_arg(ap, int);
  my_put_nbr((unsigned) nb);
}

void	print_o(va_list ap)
{
  my_put_nbr_octal(va_arg(ap, int));
}

void 	print_percent(va_list ap)
{
  ap = ap;
  my_putchar('%');
}
