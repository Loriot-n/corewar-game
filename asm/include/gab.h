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

/* header */

char	*get_new_name(char *file);

#endif /* GAB_H_ */
