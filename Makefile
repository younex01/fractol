NAME = fractol
NAME_BONUS = fractol_bonus
SRC = fractol.c mandelbrot.c julia_11.c julia_22.c julia_33.c julia_44.c burning_ship.c
SRC_BONUS = fractol_bonus.c mandelbrot_bonus.c julia_bonus.c burning_ship_bonus.c tricorn_bonus.c
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}
FLAGS = -Wall -Wextra -Werror
FLAGS2 = -lmlx -framework OpenGL -framework AppKit
CC = cc
RM = rm -rf

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(FLAGS2) $(SRC) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(FLAGS) $(FLAGS2) $(SRC_BONUS) -o $(NAME_BONUS)

%.o: %.c fractol.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ) $(OBJ_BONUS) $(NAME) $(NAME_BONUS)

fclean :
	$(RM) all

re : fclean all

.PHONY : all clean fclean re