/*
** main.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Sun Mar 27 15:31:26 2016 CUENAT
*/


#include "include.h"

int		ft_end_game(t_champion *racine, t_corewar *vm)
{
  t_champion 	*tmp;
  int		nb_die;

  nb_die = 0;
  tmp = racine;
  if (vm->cycle_die == 0)
    return (NOLIVE);
  if (vm->cycle_cpt >= vm->cycle_die)
    {
      while (racine->next != tmp)
	{
	  if (racine->bool_live == NOLIVE && racine->file_name != NULL)
	    nb_die++;
	   racine = racine->next;
	}
      if (nb_die >= vm->nb_player && vm->nb_player == 1)
	  return (1);
      if (vm->nb_live == NBR_LIVE)
	{
	  vm->nb_cycle += 1;
	  vm->nb_live = 0;
	  vm->cycle_die = CYCLE_TO_DIE - (CYCLE_DELTA * vm->nb_cycle);
	}
      vm->cycle_cpt = 0;
    }
  return (LIVE);
}

void		ft_run_game(t_champion *racine, t_corewar *vm)
{
  t_champion	*tmp;
  int		start;

  start = 0;
  tmp = racine->next;
  while (ft_end_game(tmp, vm) == LIVE)
    {
      if (start == 0)
	tmp = ft_load_action(tmp, vm);
      if (tmp->cycle_attente == 0)
	{
	  tmp = ft_launch_action(tmp, vm);
	  tmp = ft_load_action(tmp, vm);
	}
      if (tmp->cycle_attente > 0)
	tmp->cycle_attente--;
      tmp = tmp->next;
      start = 1;
      if (tmp == racine)
	{
	  tmp = tmp->next;
	  vm->cycle_cpt++;
	}
    }
}

void	print_asm(char	*memory)
{
  char	s;
  int	i = 0;
  int	pc;
  char	*readable;
  int 	tmp;
  int	u;
  int	args[MAX_ARGS_NUMBER];

  pc = 0;
  while (pc < 200)
    {
      // printf("1st pc:%d", pc);
      s = memory[pc++];
      if (IS_INSTRUC(s))
	{
	  printf("\n%s(%d arguments)  ", op_tab[s - 1].mnemonique, op_tab[s - 1].nbr_args);
	  s = s - 1;
	  if (GOT_PARAMS_CHAR(s))
	    {
	      readable = cut_args(memory[pc++]);
	      i = 0;
	      while (readable[i])
		{
		  printf("%c", readable[i]);
		  if (readable[i] == 'r')
		      printf("%d, ", memory[pc++]);
		  else if (readable[i] == 'd')
		    {
		      tmp = extract_from_mem(&(memory[pc]), DIR_SIZE);
		      pc += DIR_SIZE;
		      printf("%d, ", tmp);
		    }
		  else if (readable[i] == 'i')
		    {
		      tmp = extract_from_mem(&memory[pc], IND_SIZE);
		      pc += IND_SIZE;
		      printf("%d, ", tmp);
		    }
		  i++;
		}
	    }
	  else if (s == 0)
	    {
	      tmp = extract_from_mem(&memory[pc], 4);
	      pc += 4;
	      printf("%d, ", tmp);
	    }
	  else if (s == 8 || s == 11 || s == 14)
	    {
	      tmp = extract_from_mem(&memory[pc], IND_SIZE);
	      pc += IND_SIZE;
	      printf("%d, ", tmp);
	    }

	}
      else
	printf("boo :%d:", s);
      // printf("lst pc:%d:", pc);
      // if (pc >= 20)
	// break;
    }
}

short	extract_short_from_mem(char *str, int len)
{
  int	i;
  short	result;

  i = 0;
  result = 0;
  while (i < len)
    {
      result *= 10;
      result += str[i];
      i++;
    }
  return (result);
}

int	extract_from_mem(char *str, int len)
{
  int	i;
  int	result;

  i = 0;
  result = 0;
  while (i < len)
    {
      result *= 10;
      result += str[i];
      i++;
    }
  return (result);
}

int		main(int ac, char **argv)
{
  t_champion	*racine;
  t_corewar	*vm;

  // printf("%d\n", IS_INSTRUC(0));
  vm = ft_init_vm(argv);
  racine = ft_init_champ(argv);
  ft_load_player(racine, vm);
  //print_asm(vm->memory);
  // exit(0);
  // printf("############################\n");
  ft_run_game(racine, vm);
  return (0);
}
