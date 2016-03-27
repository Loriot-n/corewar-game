/*
** init_vm2.c for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "include.h"

int	is_option(char *option)
{
  if (my_strcmp(my_strdup(option), my_strdup("-dump")) == 0 ||
      my_strcmp(my_strdup(option), my_strdup("-n")) == 0 ||
      my_strcmp(my_strdup(option), my_strdup("-a")) == 0)
    return (1);
  return (0);
}
