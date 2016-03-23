/*
** parse_label_declaration.c for  in /home/cabaneg/rendu/Elem_prog/CPE_2015_corewar/asm/src/
**
** Made by Gabriel Cabanes
** Login   <cabane_g@epitech.eu>
**
** Started on  Wed Mar 23 15:45:45 2016 Gabriel Cabanes
** Last update Wed Mar 23 15:45:45 2016 Gabriel Cabanes
*/

#include "gab.h"

char	*label_name(char *line, char *name)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (sub_cmp(line[i], LABEL_CHARS) && line[i])
    i++;
  while (line[i] != LABEL_CHAR && line[i])
    {
      name[j] = line[i];
      j++;
      i++;
    }
  name[j] = '\0';
  return (name);
}

int	return_octet(char *line, int i)
{
  int	octet;
  char	**parse;

  octet = 1;
  i = 1;
  parse = my_str_to_wordtab(line);
  if (cmp_instruction(parse[0]))
    return (cmp_instruction(parse[0]) + 1);
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

int	parse_label(int fd)
{
  int	i;
  int	octet;
  char	*name;
  char	*line;

  octet = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      i = 0;
      if (line[0] != '.')
	{
	  if (!label_here(line))
	    {
	      if ((name = malloc(sizeof(char) * T_LAB + 1)) == NULL)
		raise_err("Can't", " perform", " malloc\n");
	      name = label_name(line, name);
	      line = delete_label(line);
	      i = my_strlen(name) + 1;
	    }
	  if (!is_empty(line))
	    octet += return_octet(line, i);
	}
    }
  return (0);
}

int	main(int argc, char **argv)
{
  int	fd;

  fd = open(argv[1], O_RDONLY);
  parse_label(fd);
  return (0);
}
