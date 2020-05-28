##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC			= 	gcc

SRC 		= 	src/main.c					\
				src/env.c 					\
				src/tetris.c 				\
				src/struct.c 				\
				src/args.c					\
				src/args_func.c 			\
				src/args_func2.c 			\
				src/args_func3.c 			\
				src/debug.c 				\
				src/check_errors.c 			\
				src/tetrimino.c 			\
				src/linked_tetriminos.c 	\
				src/get_infos_tetrimino.c 	\
				src/get_size_color.c 		\
				src/array_sorted.c 			\
				src/game.c					\
				src/game_instance.c 		\
				src/game_tetriminos.c 		\
				src/random_tetriminos.c 	\
				src/manage_g_tetri.c 		\
				src/create_gameboard.c 		\
				src/int_to_str.c 			\
				src/inputs.c 				\
				src/colors.c 				\
				src/window.c 				\
				src/rules.c

OBJ			=	$(SRC:.c=.o)

NAME		=	tetris

CFLAGS		= 	-I./include -g

LDFLAGS		= 	-L./lib/ -lmy -lncurses

RM_F		= 	@rm -f

all:			$(NAME)

$(NAME):		$(OBJ)
				@make -C lib/my
				@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
				$(RM_F) $(OBJ) && echo "\033[32mRemoved\033[0m" || echo -e "\033[31mError remove\033[0m"

fclean: 		clean
				$(RM_F) $(NAME)

%.o:			%.c
				@echo -n "Compiling tetris files: $<"
				@$(CC) $(CFLAGS) -c $< -o $@ && echo -e " [\033[32mOK\033[0m]" || echo -e " [\033[31mKO\033[0m]"

re:				fclean all

.PHONY:			all clean fclean re
