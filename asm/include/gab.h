/*
** gab.h for  in /home/cabaneg/rendu/Elem_prog/CPE_2015_corewar/Sujet/asm/
**
** Made by Gabriel Cabanes
** Login   <cabane_g@epitech.eu>
**
** Started on  Tue Mar 22 09:19:48 2016 Gabriel Cabanes
** Last update Tue Mar 22 09:19:48 2016 Gabriel Cabanes
*/

#ifndef GAB_H_
# define GAB_H_

# include "op.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

/* str_func */

int	my_strlen(char *str);
int	whereis(char *to_find, int fd, char *file_name);
void	raise_err(char *err, char *name, char *err2);
int	my_strcmp(char *s1, char *s2);
int	cmp_instruction(char *str, int yolo);
char	**my_str_to_wordtab(char *str);
char	*delete_label(char *line);
int	is_empty(char *str);
char	*my_calloc(int size);
int	my_getnbr_base(char *str, char *base, int i);
int	putin_int(char *str);
int	how_many_octet(int yolo);

/* header */

char	*get_new_name(char *file);

/* Parsing */

char	*get_next_line(const int fd);
int	my_getnbr(char *str, int i);
int	label_here(char *line);
int	sub_cmp(char c, char *str);
char	*get_str(char *line, int i);

#endif /* GAB_H_ */
