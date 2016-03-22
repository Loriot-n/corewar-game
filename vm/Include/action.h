/*
** action.h for  in /home/stanislas/CPE_2015_corewar/vm/Include
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 22 10:33:42 2016 CUENAT
** Last update Tue Mar 22 10:47:54 2016 CUENAT
*/

#ifndef ACTION_H_
# define ACTION_H_

typedef struct	action_s
{
  char		*action;
  int		reg_load;
  int		reg_write;
  int		mem_load;
  int		mem_write;

}		action_t;

#endif	/* ACTION_H_ */
