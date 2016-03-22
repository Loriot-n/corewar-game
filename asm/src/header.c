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

struct header_s		*name(struct header_s *header, int fd)
{
  int	i;
  char	buff[1];

  i = 0;
  ((lseek(fd, whereis(NAME_CMD_STRING, fd), SEEK_SET)) < 0) ?
  exit(EXIT_FAILURE) : 0;
  while (read(fd, buff, 1) > 0)
    {
      if (buff[0] == '"')
	break ;
    }
  while (read(fd, buff, 1) > 0)
    {
      if (buff[0] == '"')
	return (header);
      header->prog_name[i++] = buff[0];
    }
  return (header);
}

struct header_s		*comment(struct header_s *header, int fd)
{
  int	i;
  char	buff[1];

  i = 0;
  ((lseek(fd, whereis(COMMENT_CMD_STRING, fd), SEEK_SET)) < 0) ?
  exit(EXIT_FAILURE) : 0;
  while (read(fd, buff, 1) > 0)
    {
      if (buff[0] == '"')
	break ;
    }
  while (read(fd, buff, 1) > 0)
    {
      if (buff[0] == '"')
	return (header);
      header->comment[i++] = buff[0];
    }
  return (header);
}

struct header_s		*fill_header(struct header_s *header, char *file)
{
  int	fd;

  fd = open(file, O_RDONLY);
  header->magic = COREWAR_EXEC_MAGIC;
  header = name(header, fd);
  header = comment(header, fd);
  return (header);
}

int			header_main(char *file)
{
  struct header_s	*header;

  ((header = malloc(sizeof(struct header_s))) == NULL) ? exit(EXIT_FAILURE) : 0;
  header = fill_header(header, file);
  return (0);
}
