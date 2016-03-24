/*
** proto.h for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/Include/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Wed Mar 23 21:07:35 2016 CUENAT
*/

#ifndef PROTO_H_
# define PROTO_H_
# define IS_INSTRUC(nb) (nb > 0 && nb <= 16)
# define GOT_PARAMS_CHAR(nb) (nb != 0 && nb != 11 && nb != 14 && nb != 8) /* Seuls live, fork, lfork et zjump n'ont pas d'octet de description des params */

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
char	*get_info(char *memory, int pc);
int	get_args(char	*memory, char *readable, int pc, int *args);
int	args_if_info(char *readable, char *memory, int pc, int *args);

/* memcpy.c */
int	ft_mem_reg(int start, int end, t_corewar *vm);
char	*ft_memcpy(int start, int end, t_corewar *vm, t_champion *champion);

#endif /* PROTO_H_ */
