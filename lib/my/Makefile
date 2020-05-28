##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for libmy
##

SRC			=	my_arraylen.c				\
				my_put_nbr.c				\
				my_put_nbr_base.c 			\
				my_getnbr.c     			\
				my_putchar.c    			\
				my_putstr.c     			\
				my_revstr.c     			\
				my_strcat.c     			\
				my_strcmp.c     			\
				my_strcpy.c     			\
				my_strdup.c					\
				my_str_isalpha.c			\
				my_str_isnum.c  			\
				my_strlen.c     			\
				my_strncat.c    			\
				my_strncmp.c    			\
				my_strncpy.c    			\
				my_str_to_word_array.c		\
				get_next_line.c 			\
				my_printf.c 				\
				my_printf_flags.c 			\
				my_printf_flags2.c 			\
				my_printf_flags3.c

OBJ			= 	$(SRC:.c=.o)

CFLAGS 		=	-I./ -g

NAME		=	libmy.a

all:			$(NAME)

$(NAME):		$(OBJ)
				@ar rc $(NAME) $(OBJ)
				@cp -p $(NAME) ../
				@rm -f $(OBJ)

clean:
				@rm -f $(OBJ)

clean_git:
				@echo -n "Deleting: my git ignore files"
				@rm -f $(NAME) ../$(NAME) ../../include/my.h ../../include/bsq.h && echo -e " [\033[32mOK\033[0m]" || echo -e " [\033[31mKO\033[0m]"

fclean: 		clean
				@rm -f $(NAME)

re:				fclean all

%.o:			%.c
				@echo -n "Compiling: $<"
				@$(CC) $(CFLAGS) -c $< -o $@ && echo -e " [\033[32mOK\033[0m]" || echo -e " [\033[31mKO\033[0m]"


.PHONY: 		all clean fclean re $(NAME)
