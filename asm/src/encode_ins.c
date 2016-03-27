/*
** encode_ins.c for  in /home/cabaneg/rendu/Elem_prog/CPE_2015_corewar/asm/src/
**
** Made by Gabriel Cabanes
** Login   <cabane_g@epitech.eu>
**
** Started on  Thu Mar 24 17:44:25 2016 Gabriel Cabanes
** Last update Thu Mar 24 17:44:25 2016 Gabriel Cabanes
*/

#include "gab.h"
#include "nico.h"

char	encode_ins(char **parse)
{
  int	y;

  while (y < 16)
    {
      if (!my_strcmp(parse[0], op_tab[y].mnemonique))
	return (op_tab[y].code);
      y++;
    }
  return (0);
}

void	write_core(t_ope *ope, int size, int fd)
{
  write(fd, &ope->ins, 1);
  if (ope->nb != -1)
    write(fd, &ope->nb, 1);
  write(fd, ope->adr, size);
}

void	write_octets(int fd, int new_fd, int line_cmp, t_label *label)
{
  char		*line;
  char		**parse;
  char		*adr;
  char		ins;
  char		nb;
  t_ope		*ope;

  if ((ope = malloc(sizeof(t_ope))) == NULL)
    raise_err("Can't ", "perform ", "malloc");
  while ((line = get_next_line(fd)) != NULL && ++line_cmp)
    {
      if (!is_empty(line) && line[0] != '.')
	{
	  if (!label_here(line))
	    line = delete_label(line);
	  parse = my_str_to_wordtab(line);
	  adr = main_adr(line, parse, label, line_cmp);
	  ins = encode_ins(parse);
          nb = set_param_byte(get_det(parse));
	  ope = insert_ope(ins, nb, adr, &ope);
	  write_core(ope, size_to_malloc(line), new_fd);
	}
    }
  free(line);
}
