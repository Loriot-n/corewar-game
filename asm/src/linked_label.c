/*
** linked_label.c for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Wed Mar 23 18:00:37 2016 Nicolas Loriot
** Last update Wed Mar 23 23:59:30 2016 Nicolas Loriot
*/

#include "nico.h"

t_label		*get_newlabel(char *name, unsigned int pos_lbl, int id)
{
  t_label	*elem;

  if (!(elem = malloc(sizeof(t_label))))
    raise_err("Can't", " perform", " malloc");
  elem->name = name;
  elem->pos_lbl = pos_lbl;
  elem->id = id;
  elem->next = NULL;
  elem->prev = NULL;
  return (elem);
}

void		insert_label(char *name, unsigned int pos_lbl, int id,
			    t_label **head)
{
  t_label	*newnode;
  t_label	*tmp;

  tmp = *head;
  newnode = get_newlabel(name, pos_lbl, id);
  if (!(*head))
    {
      *head = newnode;
      return ;
    }
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = newnode;
  newnode->prev = tmp;
}

void		free_label(t_label **head)
{
  t_label	*tmp;

  tmp = *head;
  if (tmp == NULL)
    return ;
  while ((tmp = *head) != NULL)
    {
      *head = (*head)->next;
      free(tmp);
    }
}

