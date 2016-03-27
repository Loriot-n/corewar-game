/*
** champion.h for  in /home/stanislas/CPE_2015_corewar/vm/Include
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 22 10:30:24 2016 CUENAT
** Last update Sat Mar 26 20:51:15 2016 CUENAT
*/

#ifndef CHAMPION_H_
# define CHAMPION_H_

# define	LIVE 0
# define	NOLIVE 1

typedef struct 		s_champion
{
  header_t		*header;
  t_action		*action;
  char			*file_name;
  int			cycle_attente;
  int			registre[REG_NUMBER];
  int			carry;
  int			pc;
  int			bool_live;
  int			number;
  int			bool_fork;
  struct s_champion	*next;
  struct s_champion	*prev;
}			t_champion;

#endif /* CHAMPION_H_ */
