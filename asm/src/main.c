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

int	check_arg(char *str)
{
  if (str[my_strlen(str) - 1] != 's')
    return (1);
  else if (str[my_strlen(str) - 2] != '.')
    return (1);
  return (0);
}

int	prog_main(int fd, char *file, int line_cmp)
{
  int		new_fd;
  char		*new_name;
  t_label	*label;

  new_name = get_new_name(file);
  if ((new_fd = open(new_name, O_CREAT | O_WRONLY,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    raise_err("File ", new_name, " not accessible\n");
  label = fill_label_declaration(file);
  header_main(file, fd, new_fd);
  write_octets(fd, new_fd, line_cmp, label);
  return (0);
}

int	main(int argc, char **argv)
{
  int	fd;
  int	i;

  i = 1;
  if (argc == 1)
    return (write(STDOUT_FILENO, "Usage : ./asm file_name[.s]\n", 28));
  while (argc-- > 1)
    {
      if (check_arg(argv[i]))
	return (write(STDOUT_FILENO, "Usage : ./asm file_name[.s]\n", 28));
      fd = open(argv[i], O_RDONLY);
      prog_main(fd, argv[i++], 0);
      close(fd);
    }
  return (0);
}
