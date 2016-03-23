/*
** str_compare.c for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Wed Mar 23 15:12:49 2016 Nicolas Loriot
** Last update Wed Mar 23 16:01:06 2016 Nicolas Loriot
*/

#include "gab.h"
#include "nico.h"

int	my_strcmp(char *s1, char *s2)
{
  while ((*s1 != '\0') && (*s2 != '\0'))
    {
      if (*s1 != *s2)
	return (-1);
      s1++;
      s2++;
    }
  if ((*s1 == '\0') && (*s2 == '\0'))
    return (0);
  if (*s2 == '\0')
    return (1);
  return (1);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
