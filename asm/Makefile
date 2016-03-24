##
## Makefile for  in /home/cabane_g/rendu/Piscine_C_J10/do-op
##
## Made by cabanes gabriel
## Login   <cabane_g@epitech.net>
##
## Started on  Mon Oct 12 09:17:53 2015 cabanes gabriel
## Last update Wed Feb 17 16:01:21 2016 Gabriel Cabanes
##

CC	= gcc -Iinclude -g3 -Wall -W

RM	= rm -f

NAME	= asm

SRCS	= src/header.c \
				src/str_func.c \
				src/new_cor.c \
				src/get_next_line.c \
				src/parse_label_declaration.c \
				src/str_compare.c \
				src/basic_str.c \
				src/op.c \
				src/my_str_to_wordtab.c \
				src/linked_label.c \
				src/linked_op.c \
				src/encode.c \
				src/my_getnbr.c

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
