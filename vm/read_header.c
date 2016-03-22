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
  char		*read_buff;
  header_t	*cor_header;
  char		*temp;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    exit(EXIT_FAILURE);
  if ((read_buff = malloc(sizeof(char) * sizeof(header_t))) == NULL)
    exit(EXIT_FAILURE);
  if (read(fd, read_buff, sizeof(header_t)) < (unsigned)sizeof(header_t))
    exit(EXIT_FAILURE);
  if ((cor_header = malloc(sizeof(header_t))) == NULL)
    exit(EXIT_FAILURE);
  temp = read_buff;
  temp[1] = 0;
  cor_header->magic = my_getnbr(temp);
  printf("magic: %d\n", cor_header->magic);
  read_buff = &read_buff[1];
  temp = read_buff;
  temp[3] = 0;
  if (my_getnbr(&(read_buff[2])) == 0xea83f3)
    printf("%s\n", "good");
  printf("%x\n", my_getnbr(&(read_buff[2])));
}
