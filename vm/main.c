/*
** main.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Tue Mar 22 19:06:08 2016 CUENAT
*/


#include "include.h"

void	print_asm(char	*memory)
{
  char	s;
  int	i = 0;
  int	pc;
  char	*readable;
  int 	tmp;
  short	u;

  pc = 0;
  while (pc < 200)
    {
      s = memory[pc++];
      if (s > 0 && s <= 16)
	{
	  printf("\n%s(%d arguments)  ", op_tab[s - 1].mnemonique, op_tab[s - 1].nbr_args);
	  s = s - 1;
	  if (!(s == 0 || s== 8 || s == 11 || s == 14))
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
		      u = extract_short_from_mem(&memory[pc], IND_SIZE);
		      pc += IND_SIZE;
		      printf("%d, ", u);
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
	      u = extract_short_from_mem(&memory[pc], IND_SIZE);
	      pc += IND_SIZE;
	      printf("%d, ", u);
          }
      }
      else
	printf("boo :%d:", s);
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

  char s[] = {1, 2, 3, 4};
  printf("%d\n", extract_short_from_mem(s, IND_SIZE));
  vm = ft_init_vm(argv);
  racine = ft_init_champ(argv);
  ft_load_player(racine, vm);
  print_asm(vm->memory);
  return (0);
}
