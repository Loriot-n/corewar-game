##
## Makefile for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
##
## Made by maire_q
## Login   <maire_q@epitech.eu>
##
## Started on  %cdate maire_q
## Last update Sun Mar 27 16:06:18 2016 CUENAT
##

SRC=	main.c \
	check_end.c \
	op.c \
	utils.c \
	read_header.c \
	tools.c \
	init_vm.c \
	init_champ.c \
	fill_action.c \
	fill_actions2.c \
	dump.c \
	exec_action.c \
	action/add.c \
	action/aff.c \
	action/and.c \
	action/ld.c \
	action/live.c \
	action/memcpy.c \
	action/st.c \
	action/sub.c \
	action/zjmp.c \
	action/or.c \
	action/xor.c \
	action/fork.c \
	action/ldi.c \
	action/sti.c \
	action/lld.c \
	action/lldi.c \
	action/lfork.c \

NAME=	vm

OBJ=	$(SRC:.c=.o)

CFLAGS=	-Wall -I./Include -Wextra -Wno-unused-parameter -g3 \
  -Wno-unused-variable

RM= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ);

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
