##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC = $(shell find src/*.c)

NAME = solver

all: $(NAME)

$(NAME):
			gcc $(SRC) -o $(NAME) -g3

clean:
			rm $(NAME)

fclean:
			rm $(NAME)

re: clean
	 make all
