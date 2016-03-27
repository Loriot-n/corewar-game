##
## Makefile for corewar in /home/qwebify/rendu/CPE/CPE_2015_corewar/
##
## Made by maire_q
## Login   <maire_q@epitech.eu>
##
## Started on  %cdate maire_q
## Last update %udate maire_q
##

all:
	(cd asm; make all)
	(cd vm; make all)

re:
	(cd asm; make re)
	(cd vm; make re)

clean:
	(cd asm; make clean)
	(cd vm; make clean)

fclean:
	(cd asm; make fclean)
	(cd vm; make fclean)

.PHONY: all clean fclean re
