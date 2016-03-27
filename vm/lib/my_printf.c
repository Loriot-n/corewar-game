/*
** main.c for rendu in /home/qwebify/rendu/PSU_2015_my_printf
**
** Made by qwebify
** Login   <qwebify@epitech.net>
**
** Started on  Tue Nov 03 13:30:14 2015 qwebify
** Last update Sun Mar 27 20:06:43 2016 CUENAT
*/

#include "include.h"

int    		check_print(char format, va_list ap, char *flags)
{
        int     i;
  	void    (*display[15])(va_list ap);

        i = 0;
        display[0] = &print_str;
        display[1] = &print_c;
        display[2] = &print_nbr;
        display[3] = &print_long;
        display[4] = &print_short;
        display[5] = &print_b;
        display[6] = &print_S;
        display[7] = &print_x;
        display[8] = &print_p;
        display[9] = &print_f;
        display[10] = &print_u;
        display[11] = &print_o;
  	display[12] = &print_nbr;
  	display[13] = &print_X;
        display[14] = &print_percent;
        while (flags[i] != format && flags[i])
          i++;
	if (flags[i])
    	  return (good_display(i, ap, flags, display));
	else
	  return (bad_display(format));
}

int            	my_printf(char *fmt, ...)
{
  va_list       ap;
  int		i;
  char    	*flags;

  i = 0;
  compteur = 0;
  flags = "scdlhbSxpfuoiX%";
  va_start(ap, fmt);
  while (fmt[i])
  {
      if (fmt[i] == '%')
      {
	 if (fmt[i + 1] == ' ')
	    my_putchar(' ');
	while (fmt[i + 1] == ' ' && !check_print(fmt[i + 1], ap, flags))
            i++;
        check_print(fmt[i + 1], ap, flags);
        i++;
      }
      else
        my_putchar(fmt[i]);
      i++;
    }
  va_end(ap);
  return (compteur);
}
