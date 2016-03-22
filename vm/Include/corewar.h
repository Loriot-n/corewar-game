/*
** corewar.h for  in /home/stanislas/CPE_2015_corewar/vm/Include
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 22 10:48:22 2016 CUENAT
** Last update Tue Mar 22 10:49:59 2016 CUENAT
*/

#ifndef COREWAR_H_
# define COREWAR_H_

typedef struct	corewar_s
{
  char		memory[MEM_SIZE];
  int		cycle_cpt;
  int		cycle_die;
}		corewar_t;

#endif	/* COREWAR_H_ */
