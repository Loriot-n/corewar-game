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
