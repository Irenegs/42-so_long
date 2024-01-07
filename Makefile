NAME        := so_long

SRC       	:= main.c paint_functions.c solong.c validation.c

OBJ       	:= $(SRC:%.c=%.o)

CC          := gcc 
CFLAGS      := -Wall -Wextra -Werror #-fsanitize=address -g3

MLX 		:= mlx/libmlx.a

RM          := rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(MLX):
	$(MAKE) -C $(@D)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

re: fclean all

clean:
	@make -C $(dir $(MLX)) clean
	$(RM) $(OBJ)

fclean: clean
	@rm -f $(NAME)

.PHONY: re fclean clean