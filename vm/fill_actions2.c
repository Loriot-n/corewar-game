/*
** fill_actions2.c for corear in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "include.h"

int	args_if_info(char *readable, char *memory, int pc, int *args)
{
  int	i;

  i = 0;
  pc++;
  while (readable && readable[i])
  {
    if (readable[i] == 'r')
	{
	  args[i] = memory[pc];
	  pc++;
	}
    else if (readable[i] == 'd')
      {
        args[i] = extract_from_mem(&(memory[pc]), DIR_SIZE);
        pc += DIR_SIZE;
      }
    else if (readable[i] == 'i')
      {
        args[i] = extract_from_mem(&memory[pc], IND_SIZE);
        pc += IND_SIZE;
      }
    i++;
  }
  return (pc);
}
