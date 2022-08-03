NAME = fractol
SRC = fractol.c mandelbrot.c julia.c burning_ship.c sierpinskis_carpet.c tricorn.c
OBJ = ${SRC:.c=.o}
FLAGS = -Wall -Wextra -Werror
FLAGS2 = -lmlx -framework OpenGL -framework AppKit
CC = cc
RM = rm -rf

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(FLAGS2) $(SRC) -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) all

re : fclean all

.PHONY : all clean fclean re