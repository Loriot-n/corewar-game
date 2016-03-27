/*
** nico.h for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/include
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Tue Mar 22 20:28:55 2016 Nicolas Loriot
**  Last update Tue Mar 22 20:28:55 2016 Nicolas Loriot
*/

#ifndef NICO_H_
# define NICO_H_

# include <stdint.h>
/*  a=target variable, b=bit number to act upon 0-n */
# define BIT_SET(a, b) ((a) |= (1 << (b)))
# define BIT_CLEAR(a, b) ((a) &= ~(1 << (b)))
# define BIT_FLIP(a, b) ((a) ^= (1 << (b)))
# define BIT_CHECK(a, b) ((a) & (1 << (b)))

/*  x=target variable, y=mask */
# define BITMASK_SET(x, y) ((x) |= (y))
# define BITMASK_CLEAR(x, y) ((x) &= (~(y)))
# define BITMASK_FLIP(x, y) ((x) ^= (y))
# define BITMASK_CHECK(x, y) ((x) & (y))

typedef struct		s_label
{
  char			*name;
  unsigned int		pos_lbl;
  struct s_label	*next;
  struct s_label	*prev;
}			t_label;

typedef struct		s_ope
{
  char			ins;
  char			nb;
  char			*adr;
  struct s_ope		*next;
}			t_ope;

typedef struct		s_buff
{
  char			ins;
  char			nb;
  char			*adr;
}			t_buff;

int		my_strcmp(char *s1, char *s2);
char		*my_strcpy(char *dest, char *src);
void		free_label(t_label **head);
t_label		*insert_label(char *name, unsigned int pos_lbl,
			    t_label **head);
t_ope		*insert_ope(char ins, char nb, char *adr, t_ope **head);
void		free_ope(t_ope **head);
int	putin_int(char *str, int line, t_label *label);
char		*main_adr(char *file, char **parse, t_label *label, int line);
unsigned int	label_exist(char *name, t_label *label, int line);
void		write_octets(int fd, int new_fd, int line_cmp, t_label *label);
t_label		*fill_label_declaration(char *file);
void	my_putstr(char *str, int out);
void	my_put_nbr(int nb);

#endif /* !NICO_H_ */
