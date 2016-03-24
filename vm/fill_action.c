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
  // bit = 0;
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
  int		args[MAX_ARGS_NUMBER];
  char		*info;

   printf("a pc:%d", champion->pc);
  info = get_info(corewar->memory, champion->pc); /*Recupere l'octet de description des params */
  if (info != NULL)
    {
      champion->pc++;
      printf("%s\n", info);
    }
  // else
    // printf("beuh");
  champion->pc = get_args(corewar->memory, info, champion->pc, args) + 1; /* recupere les params*/
  printf(" %d, ", args[0]);
  printf("bpc:%d", champion->pc);
  champion = ft_exec_function(champion, info, args, corewar);
  return (champion);
}

char	*get_info(char *memory, int pc)
{
  char	s;

  s = memory[pc++];
  s--;
  if (IS_INSTRUC(s))
    {
      if (GOT_PARAMS_CHAR(s))
	  return (cut_args(memory[pc + 1]));
    }
  return (NULL);
}

int	get_args(char	*memory, char *readable, int pc, int *args)
{
  int	i = 0;
  int 	tmp;
  int	u;
  char instruction;

  i = 0;
  instruction = memory[pc] - 1;
  printf("%d\n", instruction);
  //printf("\n%s(%d arguments)  ", op_tab[instruction].mnemonique, op_tab[instruction].nbr_args);
  if (GOT_PARAMS_CHAR(instruction))
    return (args_if_info(readable, memory, pc, args));
  else if (instruction == 0)
    {
      args[i] = extract_from_mem(&memory[pc + 1], 4); /* == read(memory, args[i], 4) fait un read mais dans la mémoire quoi */
      pc += 4;
    }
  else if (instruction == 8 || instruction == 11 || instruction == 14)
    {
      args[i] = extract_from_mem(&memory[pc + 1], IND_SIZE);
      pc += IND_SIZE;
    }
  return (pc);
}
