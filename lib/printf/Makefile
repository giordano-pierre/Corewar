##
## EPITECH PROJECT, 2022
## B-CPE-101-LYN-1-1-myprintf-nathan.baudelin
## File description:
## Makefile
##

SRC		=	$(shell find . -name "*.c")

OBJ		=	$(SRC:.c=.o)

NAME	=	libprintf.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
