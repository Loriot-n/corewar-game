/*
** corewar.h for  in /home/stanislas/CPE_2015_corewar/vm/Include
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 22 10:48:22 2016 CUENAT
** Last update Tue Mar 22 18:32:46 2016 CUENAT
*/

#ifndef COREWAR_H_
# define COREWAR_H_

typedef struct	s_corewar
{
  char		memory[MEM_SIZE];
  int		nb_cycle;
  int		nb_live;
  int		cycle_cpt;
  int		cycle_die;
  int		nb_player;
  int		dump_cycle;
}		t_corewar;

#endif	/* COREWAR_H_ */
