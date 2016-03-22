/*
** proto.h for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/Include/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#ifndef PROTO_H_
#define PROTO_H_

/* utils*/
int	my_strlen(char *str);
int	my_strcmp(char *str1, char *str2);
char	*my_strdup(char *src);
void	my_putchar(char c);
void	my_putstr(char *str);

/* read_header */
char	*corename(char *dir);
char	**prog_tab(char	**argv);
header_t	*get_header(char *file_name);

/* Tools */
int	my_getnbr(char *str);

#endif /* PROTO_H_ */
