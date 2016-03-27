/*
** label.h for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/include/
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Sat Mar 26 20:54:08 2016 Nicolas Loriot
** Last update Sat Mar 26 20:54:08 2016 Nicolas Loriot
*/

#ifndef LABEL_H_
# define LABEL_H_
# include "gab.h"
# include "nico.h"

unsigned int	label_exist(char *name, t_label *label, int line);
int		is_num(char *str);
int		is_good_reg(char *str);
int		my_getnbrkimarche(char *str, char sepchar);
int		check_add(char **params);
int		check_ldi(char **params, t_label *label, int line);
int		check_sti(char **params, t_label *label, int line);
int		check_ld(char **params, t_label *label, int line);
int		check_st(char **params, t_label *label, int line);
#endif /* !LABEL_H_ */
