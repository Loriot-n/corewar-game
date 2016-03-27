/*
** my_swap.c for my_swap in /home/maire_q/rendu/Piscine_C_J04
** 
** Made by Quentin Maire
** Login   <maire_q@epitech.net>
** 
** Started on  Thu Oct  1 12:52:47 2015 Quentin Maire
** Last update Thu Oct  1 17:58:09 2015 Quentin Maire
*/

int	my_swap(int *a, int *b)
{
  int	ptr_a;
  int	c;
  int	d;

  ptr_a = *a;
  *a = *b;
  *b = ptr_a;
  c = *a;
  d = *b;
}
