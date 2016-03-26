/*
** fill_action.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Thu Mar 24 18:13:30 2016 CUENAT
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
  return (do_readable(info));
}

char	*do_readable(int *args)
{
  char	*tab;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char) * (MAX_ARGS_NUMBER + 1))) == NULL)
    exit(EXIT_FAILURE);
  tab[0] = '\0';
  while (i < MAX_ARGS_NUMBER)
    {
      if (args[i] == 1)
	tab[j] = 'r';
      else if (args[i] == 10)
	tab[j] = 'd';
      else if (args[i] == 11)
	tab[j] = 'i';
      j = (args[i] == 1 || args[i] == 10 || args[i] == 11) ? j + 1 : j;
      i++;
    }
  while (j < i)
    tab[j++] = '\0';
  return (tab);
}

t_champion	*ft_load_action(t_champion *champion, t_corewar *corewar)
{
  int		args[MAX_ARGS_NUMBER + 1];
  char		*info;

  printf("pc : %d\n", champion->pc);
  calloc_int_tab(args, MAX_ARGS_NUMBER + 1);
  info = get_info(corewar->memory, champion->pc);
  champion->pc = get_args(corewar->memory, info, champion->pc, args);
  // if (IS_INSTRUC(corewar->memory[champion->pc - 1]) - 1)
    int	pc = champion->pc;
  printf(":%d:%d:%d:\n", corewar->memory[pc], corewar->memory[pc + 1], corewar->memory[pc + 2]);
  printf("args:%d, %d ,%d\n", args[0], args[1], args[2]);
  champion = ft_exec_function(champion, info, args, corewar);
  return (champion);
}

char	*get_info(char *memory, int pc)
{
  char	s;

  s = memory[pc++];
  if (IS_INSTRUC(s - 1))
    {
      if (GOT_PARAMS_CHAR(s - 1))
	  return (cut_args(memory[pc]));
    }
  return (NULL);
}

int	get_args(char	*memory, char *readable, int pc, int *args)
{
  int	i = 0;
  int 	tmp;
  int	u;
  int instruction;

  i = 0;
  instruction = memory[pc++] - 1;
  args[4] = instruction;
  if (IS_INSTRUC(instruction))
    printf("\n%s(%d arguments)  ", op_tab[instruction].mnemonique, op_tab[instruction].nbr_args);
  else
    return (pc + 1);
  if (GOT_PARAMS_CHAR(instruction))
    return (args_if_info(readable, memory, pc, args));
  else if (instruction == 0)
    {
      args[i] = extract_from_mem(&memory[pc], 4);
      pc += 4;
    }
  else if (instruction == 8 || instruction == 11 || instruction == 14)
    {
      args[i] = extract_from_mem(&memory[pc], IND_SIZE);
      pc += IND_SIZE;
    }
  return (pc);
}
