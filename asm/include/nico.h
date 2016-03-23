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

typedef struct		s_label
{
  int			id;
  char			name;
  unsigned int		pos_lbl;
  struct s_pieces	*next;
  struct s_pieces	*prev;
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
void		insert_label(char *name, unsigned int pos_lbl, int id,
			    t_label **head);
void		insert_ope(char ins, char nb, char *adr, t_ope **head);
void		free_ope(t_ope **head);

#endif /* !NICO_H_ */
