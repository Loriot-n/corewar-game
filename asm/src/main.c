/*
** main.c for  in /home/cabaneg/rendu/Elem_prog/CPE_2015_corewar/asm/src/
**
** Made by Gabriel Cabanes
** Login   <cabane_g@epitech.eu>
**
** Started on  Fri Mar 25 17:41:00 2016 Gabriel Cabanes
** Last update Fri Mar 25 17:41:00 2016 Gabriel Cabanes
*/

#include "gab.h"
#include "nico.h"

int	prog_main(int fd, char *file, int line_cmp)
{
  int	new_fd;
  char	*new_name;

  new_name = get_new_name(file);
  if ((new_fd = open(new_name, O_CREAT | O_WRONLY,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    raise_err("File ", new_name, " not accessible\n");
  header_main(file, fd, new_fd);
  write_octets(fd, new_fd, line_cmp);
  return (0);
}

int	main(int argc, char **argv)
{
  int	fd;
  int	i;

  i = 1;
  while (argc-- > 1)
    {
      fd = open(argv[i], O_RDONLY);
      prog_main(fd, argv[i++], 0);
      close(fd);
    }
  return (0);
}
