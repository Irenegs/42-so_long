###########################################

NAME        := tutorial

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# LIBS        libraries to be used
# LIBS_TARGET libraries to be built
#
# INCS        header file locations
#
# SRCS        source files
#
# OBJS        object files
# DEPS        dependency files
#
# CC          compiler
# CFLAGS      compiler flags
# CPPFLAGS    preprocessor flags
# LDFLAGS     linker flags
# LDLIBS      libraries name

INCS        := include    \
    libft/include

SRCS        := prueba_validation.c validation.c

OBJS        := $(SRCS:%.c=%.o)

CC          := gcc -fsanitize=address -g3
CFLAGS      := -Wall -Wextra -Werror

MLX := mlx/libmlx.a
#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags

RM          := rm -f
MAKEFLAGS   += --no-print-directory

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   link .o -> archive
# $(LIBS)   build libraries
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal
# run       run the program
# info      print the default goal recipe

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

$(MLX):
	$(MAKE) -C $(@D)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx -O3 -c $< -o $@
    
-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS) pipex.h.gch

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: clean fclean re
.SILENT:
