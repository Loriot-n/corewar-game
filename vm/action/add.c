/*
** ld.c for  in /home/stanislas/CPE_2015_corewar/vm/action
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 23 19:48:01 2016 CUENAT
** Last update Wed Mar 23 22:32:09 2016 CUENAT
*/

t_champion	ft_ld(t_champion *ch,
		      char *info,
		      int args[MAX_ARGS_NUMBER],
		      t_corewar *vm)
{
  ch->action->rega_addr = ch->registre(args[2] - 1);
  ch->action->reg_write = ch->registre(args[0] - 1)
    + ch->registre(args[1] - 1);
  return (ch);
}
