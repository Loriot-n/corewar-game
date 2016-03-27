/*
** formatfunctions.c for rendu in /home/qwebify/rendu/PSU_2015_my_printf
**
** Made by qwebify
** Login   <qwebify@epitech.net>
**
** Started on  Thu Nov 05 13:50:48 2015 qwebify
** Last update Sun Mar 27 20:06:15 2016 CUENAT
*/

#include "include.h"

void	print_c(va_list ap)
{
  char	c;

  if ((c = va_arg(ap, int)))
    my_putchar(c);
}

void 	print_str(va_list ap)
{
  char	*str;

  str = va_arg(ap, char *);
  if (str)
      my_putstr(str);
   else
    	my_putstr("(null)");
}

void    print_short(va_list ap)
{
        print_nbr(ap);
}

void    print_long(va_list ap)
{
        print_nbr(ap);
}

void    print_nbr(va_list ap)
{
        my_put_nbr(va_arg(ap, int));
}
