NAME = wolf3d
SRCS =	main.c error.c filecheck.c map_create.c struct.c lst_map.c path_search.c \
		texture.c move.c render.c floor.c wall.c hook.c get_sheme.c

SRCO = $(SRCS:.c=.o)
OBJ = $(addprefix $(DIR),$(SRCS:.c=.o))
FLAGS = -Wall -Wextra -Werror -O3
HEADER = -I /usr/local/include/ -I includes/
MLX = -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit -lm -lpthread
LIBS = libft/libft.a 
LIB_DIR = libft/
DIR = obj/
SRC = srcs/

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[01;38;05;46m
YELLOW      = \033[38;05;226m
BLUE        = \033[03;38;05;21m
VIOLET      = \033[01;38;05;201m
CYAN        = \033[1;36m
WHITE       = \033[01;38;05;15m
RES			= \033[m

all: $(NAME)


$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@cc $(OBJ) -o $(NAME) $(HEADER) $(MLX) -L $(LIB_DIR) -lft
	@echo 


obj/%.o: $(SRC)%.c
	@mkdir -p $(DIR)
	@gcc -c $(FLAGS) -o $@ -c $<
	@echo  "$(BLUE)█$(RES)\c)"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re
