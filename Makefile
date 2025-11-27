
NAME		= so_long

LIBFT_DIR	= lib/libft
PRINTF_DIR	= lib/ft_printf
GNL_DIR		= lib/get_next_line
MLX_DIR		= lib/mlx

LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/libftprintf.a
MLX_LIB		= $(MLX_DIR)/libmlx.a

SRCS		= main.c \
			  map.c \
			  map_parser.c \
			  map_elements.c \
			  map_validation.c \
			  setup.c \
			  utils.c

OBJS		= $(SRCS:.c=.o)

GNL_SRCS	= $(GNL_DIR)/get_next_line.c \
			  $(GNL_DIR)/get_next_line_utils.c

GNL_OBJS	= $(GNL_SRCS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -I$(MLX_DIR)
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

GREEN		= \033[0;32m
RED			= \033[0;31m
BLUE		= \033[0;34m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT) $(PRINTF) $(GNL_OBJS) $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

$(MLX_LIB):
	@echo "$(BLUE)Building MLX...$(RESET)"
	@make -C $(MLX_DIR) 2>/dev/null || true
	@echo "$(GREEN)✓ MLX built$(RESET)"

$(LIBFT):
	@echo "$(BLUE)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR) 2>/dev/null
	@echo "$(GREEN)✓ libft built$(RESET)"

$(PRINTF):
	@echo "$(BLUE)Building ft_printf...$(RESET)"
	@make -C $(PRINTF_DIR) 2>/dev/null
	@echo "$(GREEN)✓ ft_printf built$(RESET)"

%.o: %.c so_long.h
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS) $(GNL_OBJS)
	@make clean -C $(LIBFT_DIR) 2>/dev/null || true
	@make clean -C $(PRINTF_DIR) 2>/dev/null || true
	@make clean -C $(MLX_DIR) 2>/dev/null || true
	@echo "$(RED)✓ Clean complete$(RESET)"

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) 2>/dev/null || true
	@make fclean -C $(PRINTF_DIR) 2>/dev/null || true
	@echo "$(RED)✓ Full clean complete$(RESET)"

re: fclean all

.PHONY: all clean fclean re