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
  char	ins;

  while (op_tab[y].mnemonique)
    {
      if (!my_strcmp(parse[0], op_tab[y].mnemonique))
	return ((ins = op_tab[y].code));
      y++;
    }
  return (0);
}

void	write_core(t_ope *ope, int size)
{
  write(1, &ope->ins, 1);
  if (ope->nb != 0)
    write(1, &ope->nb, 1);
  write(1, ope->adr, size);
}

t_ope	*fill_op(int fd)
{
  char	*line;
  char	**parse;
  char	*adr;
  char	ins;
  char	nb;
  t_ope	*ope;

  if ((ope = malloc(sizeof(t_ope))) == NULL)
    raise_err("Can't ", "perform ", "malloc");
  while ((line = get_next_line(fd)) != NULL)
    {
      if (!is_empty(line) && line[0] != '.')
	{
	  if (!label_here(line))
	    line = delete_label(line);
	  (parse = my_str_to_wordtab(line)) ? adr = main_adr(line, parse) : 0;
	  ins = encode_ins(parse);
          nb = set_param_byte(get_det(parse));
	  ope = insert_ope(ins, nb, adr, &ope);
	  write_core(ope, size_to_malloc(line));
	}
    }
  return (ope);
}

int	main(int argc, char **argv)
{
  int	fd;

  fd = open(argv[1], O_RDONLY);
  fill_op(fd);
  close(fd);
}
