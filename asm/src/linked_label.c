/*
** linked_label.c for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Wed Mar 23 18:00:37 2016 Nicolas Loriot
** Last update Wed Mar 23 23:59:30 2016 Nicolas Loriot
*/

#include "gab.h"
#include "nico.h"
#include "label.h"

t_label		*get_newlabel(char *name, unsigned int pos_lbl)
{
  t_label	*elem;

  if (!(elem = malloc(sizeof(t_label))))
    raise_err("Can't", " perform", " malloc");
  elem->name = name;
  elem->pos_lbl = pos_lbl;
  return (elem);
}

t_label		*insert_label(char *name, unsigned int pos_lbl,
			    t_label *head)
{
  t_label	*newnode;
  t_label	*tmp;

  if ((newnode = malloc(sizeof(t_label))) == NULL)
    exit(EXIT_FAILURE);
  newnode->name = my_strdup(name);
  newnode->pos_lbl = pos_lbl;
  if (head->next == head)
    {
      head->next = newnode;
      newnode->next = head;
      newnode->prev = head;
      head->prev = newnode;
    }
  else
    {
      tmp = head;
      while (tmp->next != head)
	tmp = tmp->next;
      newnode->prev = tmp;
      head->prev = newnode;
      newnode->next = head;
      tmp->next = newnode;
    }
  return (head);
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
