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

void	print_asm(char	*file_name)
{
  char	s;
  int	i = 0;
  int fd = open(file_name, O_RDONLY);
  char args;
  char	*readable;
  int 	tmp;
  char c;

  lseek(fd, sizeof(header_t), SEEK_SET);
  while (read(fd, &s, 1) > 0)
    {
      if (s > 0 && s <= 16)
	{
	  printf("\n%s(%d arguments)  ", op_tab[s - 1].mnemonique, op_tab[s - 1].nbr_args);
	  read(fd, &args, 1);
	  readable = cut_args(args);
	  i = 0;
	  while (readable[i])
	    {
	      printf("%c", readable[i]);
	      if (readable[i] == 'r')
		{
		  read(fd, &c, 1);
		  printf("%d, ", c);
		}
	      else if (readable[i] == 'd')
		{
		  read(fd, &tmp, DIR_SIZE);
                  printf("%d, ", tmp);
		}
	      else if (readable[i] == 'i')
  		{
		  read(fd, &tmp, IND_SIZE);
		  printf("%d, ", tmp);
  		}
	      i++;
	    }
	}
      else
	printf("booo :%d:", s);
    }
}

	//   i = 0;
	//   while (i < op_tab[s - 1].nbr_args)
	//     {
	//       if (i < op_tab[s - 1].nbr_args)
	// 	read(fd, &p, sizeof(s));
	//       i++;
	//       printf(" %d", p);
	//     }

int		main(int ac, char **argv)
{
  t_champion	*racine;
  t_corewar	*vm;

  print_asm("ex.cor");
  vm = ft_init_vm(argv);
  racine = ft_init_champ(argv);
  ft_load_player(racine, vm);
  return (0);
}
