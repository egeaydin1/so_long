NAME		= mlx_test

SRCS		= test.c
OBJS		= $(SRCS:.c=.o)

MLX_PATH	= ./mlx
MLX_LIB		= $(MLX_PATH)/libmlx.a
MLX_FLAGS	= -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(MLX_PATH)

GREEN		= \033[0;32m
RED			= \033[0;31m
BLUE		= \033[0;34m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Building MiniLibX...$(RESET)"
	@make -C $(MLX_PATH) 2>/dev/null || true
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Build complete!$(RESET)"

%.o: %.c
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@make clean -C $(MLX_PATH) 2>/dev/null || true

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all

run: all
	@echo "$(BLUE)Running program...$(RESET)"
	@./$(NAME)

.PHONY: all clean fclean re run
