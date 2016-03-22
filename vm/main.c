/*
** main.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "include.h"

char	*corename(char *dir)
{
  int	i;

  i = 0;
  while (dir[i] && dir[i] != '.')
    i++;
  if (!(dir[i]) || my_strcmp(&(dir[i]), my_strdup(".cor")) != 0)
    {
      my_putstr("file_name is not a corewar executable\n");
      exit(EXIT_FAILURE);
    }
  return (dir);
}

char	**prog_tab(char	**argv)
{
  char		**tab;
  int		size;

  size = 0;
  tab = NULL;
  while (*argv != NULL)
       {
      if (corename(*argv) != NULL)
	{
	  if ((tab = realloc(tab, size++)) == NULL)
	    exit(EXIT_FAILURE);
	  tab[size - 1] = corename(*argv);
	}
      argv++;
    }
  if (*argv)
    {
      if ((tab = realloc(tab, size++)) == NULL)
	exit(EXIT_FAILURE);  tab[size - 1] = NULL;
    }
  return (tab);
}

int	main(int ac, char **argv)
{
  char	*s;

  printf("%d\n", sizeof(int));
  read(open("dadv.cor"), s, 4);
  printf("%s\n", "tt");
  printf("%d\n",(int)s);
  my_putstr(prog_tab(&argv[1])[0]);
}
