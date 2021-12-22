NAME = so_long
SRC =	so_long.c $(SRCS)

SRCS = 	SRCS/parse_map.c\
		SRCS/store_positions.c\
		SRCS/draw.c\
		SRCS/move.c\
		SRCS/check_map.c\
		SRCS/check_components.c\
		gnl/get_next_line.o\
		gnl/get_next_line_utils.o


libft_bin = libft/libft.a
OBJ = $(SRC:.c=.o)
OBJSLIBFT = $(wildcard libft/*.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : makelibft makeMlx makeGNL $(NAME)

makelibft : 
	@make -C libft/

makeMlx : 
	@make -C mlx/

makeGNL : 
	@gcc $(CFLAGS) -c gnl/get_next_line.c -o gnl/get_next_line.o
	@gcc $(CFLAGS) -c gnl/get_next_line_utils.c -o gnl/get_next_line_utils.o

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(libft_bin) -lmlx -framework OpenGl -framework Appkit -lz mlx/libmlx.a

cleanLibft :
	make clean -C libft/

cleanMlx :
	make clean -C mlx/

clean : cleanLibft cleanMlx
	@rm -rf $(OBJ)
	@echo "Done"

re : fclean all

fclean : clean
	@rm -rf libft/libft.a
	make fclean -C mlx/
	make fclean -C libft/