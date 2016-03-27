/*
** header.c for  in /home/cabaneg/rendu/Elem_prog/CPE_2015_corewar/Sujet/asm/
**
** Made by Gabriel Cabanes
** Login   <cabane_g@epitech.eu>
**
** Started on  Tue Mar 22 09:15:19 2016 Gabriel Cabanes
** Last update Tue Mar 22 22:05:00 2016 Nicolas Loriot
*/

#include "gab.h"
#include "nico.h"
#include "label.h"

struct header_s		*name(struct header_s *header, int fd, char *file)
{
  int	i;
  char	buff[1];

  i = 0;
  check_null(fd, NAME_CMD_STRING, file);
  check_quotes(fd, NAME_CMD_STRING, file);
  // check_double_def(fd, NAME_CMD_STRING, file);
  ((lseek(fd, whereis(NAME_CMD_STRING, fd, file, 1), SEEK_SET)) < 0) ?
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
  (i > PROG_NAME_LENGTH) ? raise_err("Error : ", NAME_CMD_STRING, " too long")
  : (0);
  return (header);
}

struct header_s		*comment(struct header_s *header, int fd, char *file)
{
  int	i;
  char	buff[1];

  i = 0;
  check_null(fd, COMMENT_CMD_STRING, file);
  check_quotes(fd, COMMENT_CMD_STRING, file);
  // check_double_def(fd, COMMENT_CMD_STRING, file);
  ((lseek(fd, whereis(COMMENT_CMD_STRING, fd, file, 1), SEEK_SET)) < 0) ?
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
  (i > COMMENT_LENGTH) ?
  raise_err("Error : ", COMMENT_CMD_STRING, " too long") : (0);
  return (header);
}

struct header_s		*fill_header(struct header_s *header, char *file, int fd)
{
  uint32_t		i;

  i = COREWAR_EXEC_MAGIC;
  i = ((i >> 24) & 0xff) | ((i << 8) & 0xff0000) | ((i >> 8) & 0xff00) |
    ((i << 24) & 0xff000000);
  header->magic = i;
  header = name(header, fd, file);
  header->prog_size = 0;
  header = comment(header, fd, file);
  return (header);
}

void		write_header(struct header_s *header, int fd)
{
  write(fd, header, sizeof(struct header_s));
}

int			header_main(char *file, int fd, int new_fd)
{
  struct header_s	*header;

  ((header = malloc(sizeof(struct header_s))) == NULL) ? exit(EXIT_FAILURE) : 0;
  header = fill_header(header, file, fd);
  write_header(header, new_fd);
  return (0);
}
