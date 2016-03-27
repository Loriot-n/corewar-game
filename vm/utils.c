/*
** utils.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Sun Mar 27 20:10:40 2016 CUENAT
*/

#include "include.h"

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  if (my_strlen(str1) != my_strlen(str2))
    return (-1);
  while (str1[i])
    {
      if (str1[i] != str2[i])
	return (-1);
      i++;
    }
  return (0);
}

char	*my_strdup(char *src)
{
  char *str;
  int	i;

  i = 0;
  if ((str = xmalloc(my_strlen(src) + 1)) == NULL)
    exit(EXIT_FAILURE);
  while (src[i])
    {
      str[i] = src[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}
