/*
** utils.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "include.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

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

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}
