/*
** basic_str.c for  in /home/cabaneg/rendu/Elem_prog/CPE_2015_corewar/asm/src/
**
** Made by Gabriel Cabanes
** Login   <cabane_g@epitech.eu>
**
** Started on  Wed Mar 23 18:50:36 2016 Gabriel Cabanes
** Last update Wed Mar 23 18:50:36 2016 Gabriel Cabanes
*/

#include "gab.h"
#include "nico.h"

char	*get_str(char *line, int i)
{
  int	j;
  char	*str;

  j = 0;
  if ((str = malloc(sizeof(char) * my_strlen(line) + 1)) == NULL)
    raise_err("Can't ", "perform ", "malloc");
  while (line[i] && line[i] != DIRECT_CHAR && sub_cmp(line[i], LABEL_CHARS))
    i++;
  while (line[i] && line[i] != ' ' && line[i] != '\t')
    {
      str[j] = line[i];
      i++;
      j++;
    }
  str[j] = '\0';
  return (str);
}

char	*delete_label(char *line)
{
  int	i;
  int	j;
  char	*cpy;

  i = 0;
  j = 0;
  if ((cpy = malloc(sizeof(char) * my_strlen(line) + 1)) == NULL)
    raise_err("Can't ", "perform ", "malloc");
  while (line[i] && line[i] != DIRECT_CHAR && sub_cmp(line[i], LABEL_CHARS))
    i++;
  while (line[i] && line[i] != ' ' && line[i] != '\t')
    i++;
  while (line[i])
    {
      cpy[j] = line[i];
      j++;
      i++;
    }
  cpy[j] = '\0';
  return (cpy);
}

int	is_empty(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (!sub_cmp(str[i], LABEL_CHARS))
	return (0);
      i++;
    }
  return (1);
}

int	how_many_octet(int yolo)
{
  int	octet;

  octet = 1;
  while (yolo /= 255)
    octet++;
  return (octet);
}

int	putin_int(char *str, int line, t_label *label)
{
  if (str[0] == 'r')
    return (my_getnbr(str, 1));
  else if (str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR)
    return (label_exist(get_str(str, 2), label, line));
  else if (str[0] == DIRECT_CHAR && str[1] != LABEL_CHAR && str[2] == 'x')
    return (my_getnbr_base(str, "0123456789abcdef", 3));
  else if (str[0] == DIRECT_CHAR && str[1] != LABEL_CHAR && str[2] == 'X')
    return (my_getnbr_base(str, "0123456789ABCDEF", 3));
  else if (str[0] == DIRECT_CHAR && str[1] != LABEL_CHAR)
    return (my_getnbr(str, 1));
  else if (!sub_cmp(str[0], LABEL_CHARS) && str[2] == 'x')
    return (my_getnbr_base(str, "0123456789abcdef", 2));
  else if (!sub_cmp(str[0], LABEL_CHARS) && str[2] == 'X')
    return (my_getnbr_base(str, "0123456789ABCDEF", 2));
  else if (!sub_cmp(str[0], LABEL_CHARS))
    return (my_getnbr(str, 0));
  return (0);
}
