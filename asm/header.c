/*
** header.c for  in /home/cabaneg/rendu/Elem_prog/CPE_2015_corewar/Sujet/asm/
**
** Made by Gabriel Cabanes
** Login   <cabane_g@epitech.eu>
**
** Started on  Tue Mar 22 09:15:19 2016 Gabriel Cabanes
** Last update Tue Mar 22 09:15:19 2016 Gabriel Cabanes
*/

#include "gab.h"

char	*name(char *file)
{
  int	fd;
  int	i;
  char	*name;
  char	buff[1];

  fd = open(file, O_RDONLY);
  i = 0;
  ((name = malloc(PROG_NAME_LENGTH + 1)) == NULL) ? exit(EXIT_FAILURE) : 0;
  while ((read(fd, buff, 1)) > 0)
    {
      if (buff[0] == '"')
	break ;
    }
  while ((read(fd, buff, 1)) > 0)
    {
      if ((name = realloc(name, 1)) == NULL)
	return (NULL);
      if (buff[0] == '"')
	return (name);
      name[i++] = buff[0];
    }
  printf("%s\n", name);
  return (name);
}

struct header_s		*fill_header(struct header_s *header, char *file)
{
  header->magic = COREWAR_EXEC_MAGIC;
  return (header);
}

int			header_main(char *file)
{
  struct header_s	*header;

  ((header = malloc(sizeof(struct header_s))) == NULL) ? exit(EXIT_FAILURE) : 0;
  header = fill_header(header, file);
  return (0);
}
