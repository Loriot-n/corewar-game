/*
** encode.c for  in /home/cabaneg/rendu/Elem_prog/CPE_2015_corewar/asm/src/
**
** Made by Gabriel Cabanes
** Login   <cabane_g@epitech.eu>
**
** Started on  Thu Mar 24 02:05:44 2016 Gabriel Cabanes
** Last update Thu Mar 24 02:05:44 2016 Gabriel Cabanes
*/

#include "gab.h"
#include "nico.h"

int	size_to_malloc(char *line)
{
  int	i;
  int	octet;
  char	**parse;

  i = 1;
  octet = 0;
  parse = my_str_to_wordtab(line);
  if (cmp_instruction(parse[0], 1))
    return (cmp_instruction(parse[0], 1));
  while (parse[i])
    {
      if (parse[i][0] == 'r')
	octet += 1;
      else if (parse[i][0] == '%')
	octet += 4;
      else if (!sub_cmp(parse[i][0], LABEL_CHARS))
	octet += 2;
      i++;
    }
  return (octet);
}

char	*get_adr(char *line)
{
  int	i;
  int	to_putin;
  int	octet;
  char	*adr;
  char	**to_parse;

  i = 1;
  if ((adr = malloc(sizeof(char) * size_to_malloc(line) + 1)) == NULL)
    raise_err("Can't ", "perform ", "malloc");
  to_parse = my_str_to_wordtab(line);
  while (to_parse[i])
    {
      to_putin = putin_int(to_parse[i]);
      octet = how_many_octet(to_putin);
      i++;
    }
  return (adr);
}

int	main(int argc, char **argv)
{
  int	fd;
  char	*line;

  fd = open(argv[1], O_RDONLY);
  while ((line = get_next_line(fd)) != NULL)
    {
      if (!is_empty(line) && line[0] != '.')
	{
	  if (!label_here(line))
	    line = delete_label(line);
	  get_adr(line);
	}
    }
  return (0);
}
