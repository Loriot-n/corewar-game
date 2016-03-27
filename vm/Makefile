##
## Makefile for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
##
## Made by maire_q
## Login   <maire_q@epitech.eu>
##
## Started on  %cdate maire_q
## Last update Sun Mar 27 20:00:07 2016 CUENAT
##

LIBSRC= ./lib/defunctions.c \
	./lib/functions.c \
	./lib/formatfunctions.c \
	./lib/formatfunctions2.c \
	./lib/formatfunctions3.c \
	./lib/my_printf.c \
	./lib/my_strlen.c

SRC=	main.c \
	check_end.c \
	op.c \
	utils.c \
	read_header.c \
	tools.c \
	init_vm.c \
	init_vm2.c \
	init_champ.c \
	init_champ2.c \
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

NAMELB= libmy.a

LIBFLAGS = -c

LIBOBJ= $(LIBSRC:.c=.o)

CFLAGS=	-L. -lmy -Wall -I./Include -Wextra -Wno-unused-parameter -g3 \
  -Wno-unused-variable

RM= rm -f

all:	$(NAME)

$(NAME):	$(LIBOBJ) $(OBJ)
		ar rc $(NAMELB) $(LIBOBJ)
		ranlib $(NAMELB)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS);

clean:
	$(RM) $(OBJ) $(LIBOBJ) $(NAMELB)

fclean : clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
