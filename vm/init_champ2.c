/*
** init_champ2.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "include.h"

int	is_nbr(char *c)
{
  int	i;

  i = 0;
  while (c[i])
    {
      if (c[i] < '0' || c[i] > '9')
	return (0);
      i++;
    }
  return (1);
}

int	get_prog_nbr(char *name, char **argv, int nb)
{
  int	i;

  i = 0;
  while (argv[i])
    {
      if (my_strcmp(argv[i], my_strdup("-n")) == 0)
	{
	  if (argv[i + 1] && argv[i + 2] && is_nbr(argv[i + 1]) == 1)
	    {
	      if (my_strcmp(my_strdup(argv[i + 2]), name) == 0)
		return (my_getnbr(argv[i + 1]));
	    }
	  else
	    cus_exit("Bad -n parameter\n");
	}
      i++;
    }
  return (nb + 1);
}

int	check_params(char **argv)
{
  int	i;

  i = 0;
  while (argv[i])
    {
      if (is_option(argv[i]))
	{
	  if (argv[i + 1] == NULL)
	    {
	      my_putstr("Bad ");
	      my_putstr(argv[i]);
	      cus_exit(" parameter\n");
	    }
	  if (is_nbr(argv[i + 1]) == 0)
          {
            my_putstr("Bad ");
            my_putstr(argv[i]);
            cus_exit(" parameter\n");
          }
	}
      i++;
    }
  return (1);
}
