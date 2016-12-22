NAME = ft_malloc

SRC = 	main.c ft_malloc.c get_mem.c init.c

INCLUDES = -Ilibft/includes -Iinclude
LIB_FLAGS = -Llibft -lft
FLAGS = $(INCLUDES)

OBJ_DIR = obj
DIRS = 	$(OBJ_DIR)

SRC_DIR = src

VPATH = $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(DIRS) $(OBJS)
	@make -C libft
	@gcc $(OBJS) $(FLAGS) $(LIB_FLAGS) -o $(NAME) -Ofast
	@echo "\n✅  FT_MALLOC BUILT !"

$(DIRS):
	@mkdir  $@

$(OBJ_DIR)/%.o: %.c
	@gcc  $(FLAGS) -c $< -o $@ -g3
	@echo "$(NAME) => \033[33;32m$@\033[33;0m"

clean:
	rm -rf $(DIRS)

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all
