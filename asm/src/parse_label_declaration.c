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
#include "nico.h"

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

int	return_octet(char *line)
{
  int	i;
  int	octet;
  char	**parse;

  i = 1;
  octet = 2;
  parse = my_str_to_wordtab(line);
  if (cmp_instruction(parse[0], 0))
    return (cmp_instruction(parse[0], 0));
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

t_label	*parse_label(int fd, t_label *label)
{
  int	octet;
  char	*name;
  char	*line;

  octet = 0;
  if ((name = malloc(sizeof(char) * T_LAB + 1)) == NULL)
  raise_err("Can't", " perform", " malloc");
  while ((line = get_next_line(fd)) != NULL)
    {
      if (line[0] != '.')
	{
	  if (!label_here(line))
	    {
	      name = label_name(line, name);
	      label = insert_label(name, octet, &label);
	      line = delete_label(line);
	    }
	  if (!is_empty(line))
	    octet += return_octet(line);
	}
    }
  return (label);
}

t_label		*fill_label_declaration(char *file)
{
  int		fd;
  t_label	*label;

  label = NULL;
  fd = open(file, O_RDONLY);
  label = parse_label(fd, label);
  close(fd);
  return (label);
}
