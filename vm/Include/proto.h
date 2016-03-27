/*
** proto.h for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/Include/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Sun Mar 27 16:10:48 2016 CUENAT
*/

#ifndef PROTO_H_
# define PROTO_H_
# define IS_INSTRUC(nb) (nb >= 0 && nb < 16)
# define GOT_PARAMS_CHAR(nb) (nb != 0 && nb != 11 && nb != 14 && nb != 8)

/*
** check_end.c
*/
t_corewar	*ft_end_game_2(t_champion *racine, t_corewar *vm);
int		ft_end_game(t_champion *racine, t_corewar *vm);
/*
**utils
*/
int	my_strlen(char *str);
int	my_strcmp(char *str1, char *str2);
char	*my_strdup(char *src);
void	my_putchar(char c);
void	my_putstr(char *str);

/*
**read_header
*/
char		*corename(char *dir);
char		**prog_tab(char	**argv);
header_t	*get_header(char *file_name);

/*
**Tools
*/
int	my_getnbr(char *str);
int	*calloc_int_tab(int *tab, int size);
void	my_putstr_stderr(char *str);
void	*xmalloc(int size);
void	cus_exit(char *str);

/*
**init_champ.c
*/
void		ft_init_registre_(int registre[16], int ac);
void		ft_add_end(t_champion *cur_champ, int i, char *file_name,
			char **argv);
t_champion	*ft_create_list_(void);
t_champion	*ft_init_champ(char **argv);
t_action	*ft_init_action();

/*
**init_vm.c
*/
void		ft_init_memory(char memory[MEM_SIZE]);
t_corewar	*ft_init_vm(char **argv);
int		ft_get_nb_player(char **av);
void		ft_load_player(t_champion *racine, t_corewar *vm);
void		ft_load_bitecode(int fd, t_champion *tmp, t_corewar *vm,
				int pos_start);

/*
** init_vm2
*/
int	is_option(char *option);
int	get_prog_nbr(char *name, char **argv, int nb);
int	is_nbr(char *c);
int	get_load_addr(char *name, char **argv, int nb);
int	check_params(char **argv);

/*
**fill_action
*/
char	*cut_args(char args);
t_champion	*ft_load_action(t_champion *champion, t_corewar *corewar);
char	*do_readable(int *args);
short	extract_short_from_mem(char *str, int len);
int	extract_from_mem(char *str, int len);
char	*get_info(char *memory, int pc);
int	get_args(char	*memory, char *readable, int pc, int *args);
int	args_if_info(char *readable, char *memory, int pc, int *args);

/*
**memcpy.c
*/
int	ft_mem_reg(int start, int end, t_corewar *vm);
char	*ft_memcpy(int start, int end, t_corewar *vm, t_champion *champion);
char	*ft_reg_to_mem(int reg_val, t_corewar *vm, t_champion *champion);

/*
**dump.c
*/
void	dump_me(char *memory);
void	my_putnbr_base(int deciaml, char *base);

/*
**exec_function.c
*/
t_champion	*ft_exec_function(t_champion *ch,
				  char *info,
				  int args[MAX_ARGS_NUMBER],
				  t_corewar *vm);
t_champion	*ft_launch_action(t_champion *ch, t_corewar *vm);

/*
**instruction -> action folder
*/
t_champion	*ft_add(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_aff(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_and(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_fork(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_ld(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_lfork(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_live(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_lld(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_lldi(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_or(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_st(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_sub(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_xor(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_zjmp(t_champion *ch,
		     char *info,
		     int args[MAX_ARGS_NUMBER],
		     t_corewar *vm);
t_champion	*ft_ldi(t_champion *ch,
			char *info,
			int args[MAX_ARGS_NUMBER],
			t_corewar *vm);
t_champion	*ft_sti(t_champion *ch,
			char *info,
			int args[MAX_ARGS_NUMBER],
			t_corewar *vm);

#endif /* PROTO_H_ */
