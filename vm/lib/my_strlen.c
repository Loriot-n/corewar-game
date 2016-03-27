/*
** my_strlen.c for my_strlen in /home/maire_q/rendu/Piscine_C_J04
** 
** Made by Quentin Maire
** Login   <maire_q@epitech.net>
** 
** Started on  Thu Oct  1 20:36:26 2015 Quentin Maire
** Last update Sat Oct  3 09:11:10 2015 Quentin Maire
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*str != '\0')
    {
      i = i + 1;
      str = str + 1;
    }
  return (i);
}
