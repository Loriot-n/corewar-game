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
  printf("I got a param byte \\o/ !\n");
  printf("pc->%d\n", pc);
  while (readable && readable[i])
  {
    if (readable[i] == 'r')
	{
	  args[i] = memory[pc];
	  pc++;
	}
    else if (readable[i] == 'd')
      {
        args[i] = extract_from_mem(&(memory[pc + 1]), DIR_SIZE);
        pc += DIR_SIZE;
      }
    else if (readable[i] == 'i')
      {
        args[i] = extract_from_mem(&memory[pc + 1], IND_SIZE);
        pc += IND_SIZE;
      }
    i++;
  }
  printf("%d %d %d\n", args[0], args[1], args[2]);
  exit(0);
  return (pc);
}
