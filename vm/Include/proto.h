/*
** proto.h for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/Include/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Tue Mar 22 13:48:01 2016 CUENAT
*/

#ifndef PROTO_H_
#define PROTO_H_

/* utils */
int	my_strlen(char *str);
int	my_strcmp(char *str1, char *str2);
char	*my_strdup(char *src);
void	my_putchar(char c);
void	my_putstr(char *str);

/* init_champ.c */
void		ft_init_registre_(int registre[16], int ac);
t_champion	*ft_add_end(t_champion *cur_champ, int ac, char **av);
t_champion	*ft_create_list_(void);

/* init_vm.c */
void		ft_init_memory(char memory[MEM_SIZE]);
t_corewar	*ft_init_vm(void);

#endif /* PROTO_H_ */
