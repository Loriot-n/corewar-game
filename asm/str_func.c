/*
** str_func.c for corewar_asm in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Tue Mar 22 10:56:01 2016 Nicolas Loriot
** Last update Tue Mar 22 11:05:51 2016 Nicolas Loriot
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putstr(char *str, int out);

void	raise_err(char *err)
{
  
}

char	*my_calloc(int size)
{
  int	i;
  char	*str;

  i = 0;
  if (!(str = malloc(sizeof(char) * size)))
    raise_err("Can't perform malloc\n");
  while (str[i])
    str[i++] = 0;
  return (str);
}
