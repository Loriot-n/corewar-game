/*
** op.h for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/include/
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Fri Mar 25 16:53:44 2016 Nicolas Loriot
** Last update Sun Mar 27 23:28:51 2016 CUENAT
*/

#ifndef _OP_H_
# define _OP_H_

# define MEM_SIZE                (6 * 1024)
# define IDX_MOD                 512
# define MAX_ARGS_NUMBER         4
# define COMMENT_CHAR            '#'
# define LABEL_CHAR              ':'
# define DIRECT_CHAR             '%'
# define SEPARATOR_CHAR          ','
# define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING         ".name"
# define COMMENT_CMD_STRING      ".comment"
typedef char    args_type_t;

/*
** regs
*/

# define REG_NUMBER      16
# define T_REG           1
# define T_DIR           2
# define T_IND           4
# define T_LAB           8

typedef struct	op_s
{
   char         *mnemonique;
   char         nbr_args;
   args_type_t  type[MAX_ARGS_NUMBER];
   char         code;
   int          nbr_cycles;
   char         *comment;
}		op_t;

/*
** size
*/

# define IND_SIZE        2
# define REG_SIZE        4
# define DIR_SIZE        REG_SIZE

/*
** op_tab
*/

extern  op_t    op_tab[];

/*
** header
*/
# define PROG_NAME_LENGTH        128
# define COMMENT_LENGTH          2048
# define COREWAR_EXEC_MAGIC      0xea83f3

typedef struct header_s
{
   int  	magic;
   char 	prog_name[PROG_NAME_LENGTH + 1];
   int  	prog_size;
   char 	comment[COMMENT_LENGTH + 1];
}		header_t;

/*
** live
*/

# define CYCLE_TO_DIE    1536
# define CYCLE_DELTA     5
# define NBR_LIVE        40

#endif
