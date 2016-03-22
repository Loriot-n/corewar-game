/*
** new_cor.c for  in /home/cabaneg/rendu/Elem_prog/CPE_2015_corewar/asm/src/
**
** Made by Gabriel Cabanes
** Login   <cabane_g@epitech.eu>
**
** Started on  Tue Mar 22 15:27:36 2016 Gabriel Cabanes
** Last update Tue Mar 22 15:27:36 2016 Gabriel Cabanes
*/

#include "gab.h"

char	*get_new_name(char *file)
{
  int	i;
  int	tmp;
  char	*cor;

  i = 0;
  tmp = my_strlen(file);
  ((cor = malloc(sizeof(char) * my_strlen(file) + 1)) == NULL) ?
      exit(EXIT_FAILURE) : 0;
  while (file[tmp - 1] != '.')
    tmp--;
  while (i != tmp)
    {
      cor[i] = file[i];
      i++;
    }
  cor[i] = 'c';
  cor[i + 1] = 'o';
  cor[i + 2] = 'r';
  cor[i + 3] = '\0';
  return (cor);
}
