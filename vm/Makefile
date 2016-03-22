##
## Makefile for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/vm/
##
## Made by maire_q
## Login   <maire_q@epitech.eu>
##
## Started on  %cdate maire_q
## Last update %udate maire_q
##

SRC=	main.c \
  	op.c \
	utils.c \
	read_header.c \
	tools.c \

NAME=	corewar

OBJ=	$(SRC:.c=.o)

CFLAGS=	-Wall -I./Include -Wextra -Wno-unused-parameter -g3

RM= rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ);

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all
