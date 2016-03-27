/*
** my_str_to_wordtab.c for str to word tab in /home/loriot_n/rendu/Piscine_C_J08/ex_04
**
** Made by nicolas loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Fri Oct  9 11:43:20 2015 nicolas loriot
** Last update Sat Jan 23 14:38:51 2016 Nicolas Loriot
*/

#include "gab.h"

int	my_char_isalphanum(char c)
{
  if (c == ',')
    return (-1);
  else if ((c >= 'a') && (c <= 'z'))
    return (1);
  else if ((c >= 'A') && (c <= 'Z'))
    return (1);
  else if ((c >= '0') && (c <= '9'))
    return (1);
  else if ((c == ':') || (c == ';') || ((c >= '#') && (c <= '/')))
    return (1);
  else if ((c == 92) || (c == 95))
    return (1);
  return (-1);
}

int	word_counter(char *str)
{
  int	i;
  int	cnt;

  i = 0;
  cnt = 0;
  while (str[i] != '\0')
    {
      cnt = cnt + 1;
      if (my_char_isalphanum(str[i]) == 1)
	i = i + 1;
      else
	  i = i + 1;
    }
  return (cnt);
}

int	a_ctr(char *str, int i)
{
  int cnt;

  cnt = 0;
  while (my_char_isalphanum(str[i]) == 1)
    {
      cnt = cnt + 1;
      i = i + 1;
    }
  return (cnt);
}

char	**tab_creator(char **tab, char *str, int words, int k)
{
  int	i;
  int	j;

  i = 0;
  while ((str[i] != '\0') && (words > 0))
    {
      if (my_char_isalphanum(str[i]) == 1)
	{
	  if ((tab[k] = malloc(sizeof(char) * (a_ctr(str, i) + 2))) == NULL)
	    return (NULL);
	  j = 0;
	  while (my_char_isalphanum(str[i]) == 1)
	    {
	      if (str[i] == '#')
		tab[k] = NULL;
	      tab[k][j] = str[i];
	      (j = j + 1) ? (i = i + 1) : 0;
	    }
	  tab[k][j] = '\0';
	  (k = k + 1) ? (words = words - 1) : 0;
	}
      i = i + 1;
    }
  tab[k] = '\0';
  return (tab);
}

char	**my_str_to_wordtab(char *str)
{
  int	words;
  char	**tab;

  if (!str)
    return (NULL);
  words = word_counter(str);
  if ((tab = malloc(sizeof(char *) * (words + 1))) == NULL)
    return (NULL);
  tab = tab_creator(tab, str, words, 0);
  return (tab);
}
