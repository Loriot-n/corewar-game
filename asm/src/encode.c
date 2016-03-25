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
  while (parse[i] && parse[i][0] != COMMENT_CHAR && parse[i][0] != ';')
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

int	size_octet(char *yolo, char **parse)
{
  int	octet;

  octet = 0;
  if (yolo[0] == 'r')
    octet = 1;
  else if (yolo[0] == '%' && (!my_strcmp(parse[0], "sti") ||
			      !my_strcmp(parse[0], "ldi") ||
			      !my_strcmp(parse[0], "lldi") ||
			      !my_strcmp(parse[0], "lfork") ||
			      !my_strcmp(parse[0], "zjmp") ||
			      !my_strcmp(parse[0], "fork") ||
			      yolo[1] == ':'))
    octet = 2;
  else if (yolo[0] == '%')
    octet = 4;
  else if (!sub_cmp(yolo[0], LABEL_CHARS))
    octet = 2;
  return (octet);
}

char	*fil_octet(int i, int needed, int value, char *adr)
{
  if (needed > 1)
    {
      adr[i - needed + 1] = value - 255 * (needed - 1);
      while (--needed)
	adr[--i] = 255;
      return (adr);
    }
  adr[i] = value;
  return (adr);
}

char	*get_adr(char *line, char **parse, int i, int y)
{
  int	size;
  int	size_total;
  int	needed;
  int	value;
  int	i_tmp;
  char	*adr;

  size_total = size_to_malloc(line);
  if ((adr = my_calloc(size_total)) == NULL)
    raise_err("Can't ", "perform ", "malloc");
  while (parse[y])
    {
      (size = size_octet(parse[y], parse)) ? (value = putin_int(parse[y])) : 0;
      (i_tmp = 1) ? needed = how_many_octet(value) : 0;
      while (i_tmp++ < size)
	i++;
      adr = fil_octet(i, needed, value, adr);
      i++;
      y++;
    }
  return (adr);
}

char	*main_adr(char *line, char **parse)
{
  char	*adr;
  adr = get_adr(line, parse, 0, 1);
  return (adr);
}
