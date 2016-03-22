/*
** read_header.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/Include/
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

header_t	*get_header(char *file_name)
{
  int		fd;
  header_t	*cor_header;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    exit(EXIT_FAILURE);
  if ((cor_header = malloc(sizeof(header_t))) == NULL)
    exit(EXIT_FAILURE);
  if (read(fd, cor_header, sizeof(header_t)) < (unsigned)sizeof(header_t))
    exit(EXIT_FAILURE);
  cor_header->magic = 0x0 + cor_header->magic;
  return (cor_header);
}
