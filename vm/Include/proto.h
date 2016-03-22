/*
** proto.h for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/Include/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Tue Mar 22 18:49:24 2016 CUENAT
*/

#ifndef PROTO_H_
#define PROTO_H_

/* utils */
int	my_strlen(char *str);
int	my_strcmp(char *str1, char *str2);
char	*my_strdup(char *src);
void	my_putchar(char c);
void	my_putstr(char *str);

/* read_header */
char		*corename(char *dir);
char		**prog_tab(char	**argv);
header_t	*get_header(char *file_name);

/* Tools */
int	my_getnbr(char *str);

/* init_champ.c */
void		ft_init_registre_(int registre[16], int ac);
void		ft_add_end(t_champion *cur_champ, int ac, char *file_name);
t_champion	*ft_create_list_(void);
t_champion	*ft_init_champ(char **argv);

/* init_vm.c */
void		ft_init_memory(char memory[MEM_SIZE]);
t_corewar	*ft_init_vm(char **argv);
int		ft_get_nb_player(char **av);

#endif /* PROTO_H_ */
