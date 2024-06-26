NAME        := so_long

SRC			:= char_functions.c libft.c images.c main.c map_info.c \
			map_solvable.c movement.c paint_functions.c  \
			play.c solong.c valid_structure.c validation.c

OBJ			:= $(SRC:%.c=%.o)
MLX 		:= mlx/libmlx.a

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror

RM          := rm -f

all: $(NAME)

$(MLX):
	$(MAKE) -C $(@D)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) $(MLX)
	$(CC) $(OBJ) $(LDFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C mlx

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
