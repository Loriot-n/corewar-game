/*
** champion.h for  in /home/stanislas/CPE_2015_corewar/vm/Include
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 22 10:30:24 2016 CUENAT
** Last update Tue Mar 22 11:10:28 2016 CUENAT
*/

#ifndef CHAMPION_H_
# define CHAMPION_H_

typedef struct 	s_champion
{
  header_t	header;
  action_t	action;
  int		cycle_attente;
  int		registr[16];
  int		carry;
  int		pc;
  int		bool_live;
  champion_t	*next;
  champion_t	*prev;
}		t_champion;

#endif /* CHAMPION_H_ */
