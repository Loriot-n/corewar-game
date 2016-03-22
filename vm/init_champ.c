/*
** init_champ.c for  in /home/stanislas/CPE_2015_corewar/vm
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 22 11:03:51 2016 CUENAT
** Last update Tue Mar 22 19:02:15 2016 CUENAT
*/

#include "include.h"

void	ft_init_registre_(int registre[16], int nb_prog)
{
  int	i;

  i = 0;
  registre[0] = nb_prog;
  i++;
  while (i < REG_NUMBER)
    {
      registre[i] = 0;
      i++;
    }
}

void		ft_add_end(t_champion *cur_champ, int i, char *file_name)
{
  t_champion	*new_champ;

  if ((new_champ = malloc(sizeof(t_champion) * 1)) == NULL)
    exit(EXIT_FAILURE);
  new_champ->header = get_header(file_name);
  new_champ->action = NULL;
  new_champ->file_name = my_strdup(file_name);
  new_champ->cycle_attente = 0;
  ft_init_registre_(new_champ->registre, i);
  new_champ->carry = 0;
  new_champ->pc = 0;
  new_champ->bool_live = NOLIVE;
  new_champ->prev = cur_champ;
  new_champ->next = cur_champ->next;
  cur_champ->next->prev = new_champ;
  cur_champ->next = new_champ;
}

t_champion	*ft_create_list_(void)
{
  t_champion	*racine;

  if ((racine = malloc(sizeof(t_champion) * 1)) == NULL)
    exit(EXIT_FAILURE);
  racine->prev = racine;
  racine->next = racine;
  return (racine);
}
t_champion      *ft_init_champ(char **argv)
{
  char          **tab_cor;
  t_champion    *racine;
  int           i;

  i = 0;
  racine = ft_create_list_();
  tab_cor = prog_tab(&argv[1]);
  if (tab_cor == NULL)
    exit(EXIT_FAILURE);
  while (tab_cor[i] != NULL)
    {
      ft_add_end(racine, i, tab_cor[i]);
      i++;
    }
  return (racine);
}
