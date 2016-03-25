/*
** action.h for  in /home/stanislas/CPE_2015_corewar/vm/Include
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 22 10:33:42 2016 CUENAT
** Last update Thu Mar 24 16:57:29 2016 CUENAT
*/

#ifndef ACTION_H_
# define ACTION_H_

typedef struct	s_action
{
  char		*action;
  int		reg_addr;
  int		reg_write;
  int		mem_addr;
  int		mem_size;
  char		*mem_write;

}		t_action;

#endif	/* ACTION_H_ */
