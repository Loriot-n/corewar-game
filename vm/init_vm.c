/*
** init_vm.c for  in /home/stanislas/CPE_2015_corewar/vm
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 22 13:32:55 2016 CUENAT
** Last update Sat Mar 26 21:07:54 2016 CUENAT
*/

#include "include.h"

void	ft_load_bitecode(int fd, t_champion *tmp, t_corewar *vm, int pos_start)
{
  char	buf[100];
  int	oct;
  int	cpt_read;

  lseek(fd, sizeof(header_t), SEEK_SET);
  while ((oct = read(fd, &buf, 100)) > 0)
    {
      cpt_read = 0;
      while (cpt_read < oct)
	{
	  vm->memory[cpt_read + pos_start] = buf[cpt_read];
	  cpt_read++;
	}
      pos_start = cpt_read + pos_start;
    }
}

void	ft_load_player(t_champion *racine, t_corewar *vm)
{
  t_champion	*tmp;
  int		pos_start;
  int		fd;

  pos_start = 0;
  tmp = racine->next;
  while (tmp != racine)
    {
      if ((fd = open(tmp->file_name, O_RDONLY)) == -1)
	exit(EXIT_FAILURE);
      ft_load_bitecode(fd, tmp, vm, pos_start);
      tmp->pc = pos_start;
      pos_start = pos_start + (MEM_SIZE /  vm->nb_player);
      close(fd);
      tmp = tmp->next;
    }
}

int	ft_get_nb_player(char **av)
{
  int	i;
  int	j;

  i = 1;
  j = 0;
  while (av[i])
    {
      if (is_option(av[i]) == 1 && is_nbr(av[i + 1]))
	i += 2;
      if (corename(av[i]) != NULL)
	j++;
      i++;
    }
  return (j);
}

void	ft_init_memory(char memory[MEM_SIZE])
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      memory[i] = 0;
      i++;
    }
}

t_corewar	*ft_init_vm(char **argv)
{
  t_corewar	*vm;
  int		i;

  i = 0;
  if ((vm = xmalloc(sizeof(t_corewar) * 1)) ==  NULL)
    exit(EXIT_FAILURE);
  ft_init_memory(vm->memory);
  vm->nb_cycle = 0;
  vm->nb_live = 0;
  vm->cycle_cpt = 0;
  vm->cycle_die = CYCLE_TO_DIE - (CYCLE_DELTA * vm->nb_cycle);
  vm->dump_cycle = -1;
  while (argv[i])
    {
      if (my_strcmp(argv[i], my_strdup("-dump")) == 0)
	{
	  if (argv[i + 1] && my_getnbr(argv[i + 1]) > 0)
	    vm->dump_cycle = my_getnbr(argv[i + 1]);
	  else
	    cus_exit("Dump must have a positive number.\n");
	  argv = &argv[2];
	}
      i++;
    }
  vm->nb_player = ft_get_nb_player(argv);
  return (vm);
}
