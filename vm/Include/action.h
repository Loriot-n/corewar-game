/*
** action.h for  in /home/stanislas/CPE_2015_corewar/vm/Include
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 22 10:33:42 2016 CUENAT
** Last update Tue Mar 22 11:10:49 2016 CUENAT
*/

#ifndef ACTION_H_
# define ACTION_H_

typedef struct	s_action
{
  int		action_nb;
  int		reg_load;
  int		reg_write;
  int		mem_load;
  int		mem_write;

}		t_action;

#endif	/* ACTION_H_ */
