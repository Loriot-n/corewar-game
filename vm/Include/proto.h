/*
** proto.h for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/Include/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Tue Mar 22 19:26:05 2016 CUENAT
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
int	*calloc_int_tab(int *tab, int size);

/* init_champ.c */
void		ft_init_registre_(int registre[16], int ac);
void		ft_add_end(t_champion *cur_champ, int ac, char *file_name);
t_champion	*ft_create_list_(void);
t_champion	*ft_init_champ(char **argv);

/* init_vm.c */
void		ft_init_memory(char memory[MEM_SIZE]);
t_corewar	*ft_init_vm(char **argv);
int		ft_get_nb_player(char **av);
void		ft_load_player(t_champion *racine, t_corewar *vm);
void		ft_load_bitecode(int fd, t_champion *tmp, t_corewar *vm,
				int pos_start);

/* fill_action */
char	*cut_args(char args);
t_champion	*ft_load_action(t_champion *champion, t_corewar *corewar);
char	*do_readable(int *args);
short	extract_short_from_mem(char *str, int len);
int	extract_from_mem(char *str, int len);

#endif /* PROTO_H_ */
