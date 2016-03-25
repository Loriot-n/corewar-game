/*
** op.h for corewar in /home/nico/rendu/S02/ProgElem/CPE_2015_corewar/asm/include/
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Fri Mar 25 16:53:44 2016 Nicolas Loriot
** Last update Fri Mar 25 16:53:44 2016 Nicolas Loriot
*/

#ifndef _OP_H_
# define _OP_H_

# define MEM_SIZE                (6*1024)
# define IDX_MOD                 512   /* modulo de l'index < */
# define MAX_ARGS_NUMBER         4    /* this may not be changed 2^*IND_SIZE */
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

# define REG_NUMBER      16              /* r1 <--> rx */
# define T_REG           1       /* registre */
# define T_DIR           2       /* directe  (ld  #1, r1  met 1 dans r1) */
# define T_IND           4
# define T_LAB           8       /* LABEL */

struct  op_s
{
   char         *mnemonique;
   char         nbr_args;
   args_type_t  type[MAX_ARGS_NUMBER];
   char         code;
   int          nbr_cycles;
   char         *comment;
};

typedef struct op_s     op_t;

/*
 ** size
 */

# define IND_SIZE        2               /* en octet */
# define REG_SIZE        4               /* en octet */
# define DIR_SIZE        REG_SIZE        /* en octet */

/*
 ** op_tab
 */

extern  op_t    op_tab[];

/*
 ** header
 */
# define PROG_NAME_LENGTH        128
# define COMMENT_LENGTH          2048
# define COREWAR_EXEC_MAGIC      0xea83f3        /* why not */

struct header_s
{
   int  magic;
   char prog_name[PROG_NAME_LENGTH + 1];
   int  prog_size;
   char comment[COMMENT_LENGTH + 1];
};

typedef struct header_s header_t;

/*
 ** live
 */

# define CYCLE_TO_DIE    1536  /* nombre de cycle pour etre d\'eclarer mort */
# define CYCLE_DELTA     5
# define NBR_LIVE        40

#endif
