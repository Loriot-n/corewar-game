/*
** linked_op.c for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Wed Mar 23 23:24:43 2016 Nicolas Loriot
** Last update Thu Mar 24 00:13:44 2016 Nicolas Loriot
*/

#include "nico.h"

t_ope		*get_newope(char ins, char nb, char *adr)
{
  t_ope		*elem;

  if (!(elem = malloc(sizeof(t_ope))))
    raise_err("Can't", " perform", " malloc");
  elem->ins = ins;
  elem->nb = nb;
  elem->adr = adr;
  elem->next = NULL;
  return (elem);
}

void		insert_ope(char ins, char nb, char *adr, t_ope **head)
{
  t_ope		*newnode;
  t_ope		*tmp;

  tmp = *head;
  newnode = get_newope(ins, nb, adr);
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

void		free_ope(t_ope **head)
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

