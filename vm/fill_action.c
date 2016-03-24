/*
** fill_action.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "include.h"

char	*cut_args(char args)
{
  int	bit = 0;
  int	info[MAX_ARGS_NUMBER];
  int	temp;
  int	i;

  i = 0;
  calloc_int_tab(info, MAX_ARGS_NUMBER);
  while (bit < (signed int)sizeof(args) * 8)
    {
      temp = ((args & (1 << bit)) == 0) ? 0 : 1;
      info[MAX_ARGS_NUMBER - 1 - i] += temp;
      if (bit % 2 == 1)
	{
	  if (temp == 1)
	    info[MAX_ARGS_NUMBER - 1 - i] *= 10;
	  i++;
	}
      bit++;
    }
  bit = 0;
  // while (bit < MAX_ARGS_NUMBER)
  //   {
  //     if (info[bit] == 0)
  // printf("00");
  //     else if (info[bit] == 1)
  // printf("01");
  //     else
  // printf("%d", info[bit]);
  //     bit++;
  //   }
  // printf("\n");
  return (do_readable(info));
}

char	*do_readable(int *args)
{
  char	*tab;
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(char) * MAX_ARGS_NUMBER)) == NULL)
    exit(EXIT_FAILURE);
  while (i < MAX_ARGS_NUMBER)
    {
      if (args[i] == 1)
	tab[i] = 'r';
      else if (args[i] == 10)
	tab[i] = 'd';
      else if (args[i] == 11)
	tab[i] = 'i';
      else
	tab[i] = 0;
      i++;
    }
  return (tab);
}

t_champion	*ft_load_action(t_champion *champion, t_corewar *corewar)
{
  int		pc;
  int		action;
  int		args[MAX_ARGS_NUMBER];

  pc = champion->pc;
  if (corewar->memory[pc] > 0 && corewar->memory[pc] <= 16)
    action = corewar->memory[pc] - 1;
  else
    return (champion);
  if (action == 0 || action == 8 || action == 11 || action == 14)
    {
      //call_function;
      return (champion);
    }
  return (champion);

}
