NAME = so_long
BONUS_NAME = so_long_bonus

SRCDIR = man
BONUSDIR = bon
OBJDIR = obj
BONUSOBJDIR = obj_bonus

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
MLX_DIR = /usr/include/minilibx-linux

SRC =	$(SRCDIR)/check_path.c $(SRCDIR)/handl_input.c $(SRCDIR)/render_map.c $(SRCDIR)/ft_exit.c $(SRCDIR)/load_text.c $(SRCDIR)/moves_player.c \
		$(SRCDIR)/handl_error.c  $(SRCDIR)/main.c $(SRCDIR)/read_map.c $(SRCDIR)/get_next_line.c $(SRCDIR)/get_next_line_utils.c

BONUS_SRC = $(BONUSDIR)/check_path.c $(BONUSDIR)/handl_error.c $(BONUSDIR)/main.c $(BONUSDIR)/read_map.c $(BONUSDIR)/enmy.c $(BONUSDIR)/handl_input.c $(BONUSDIR)/ft_end.c \
			$(BONUSDIR)/render_map.c $(BONUSDIR)/ft_exit.c $(BONUSDIR)/load_text.c $(BONUSDIR)/moves_player.c $(BONUSDIR)/get_next_line.c $(BONUSDIR)/get_next_line_utils.c

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:$(BONUSDIR)/%.c=$(BONUSOBJDIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -L $(MLX_DIR) -lmlx -lXext -lX11

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME) $(MLX)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(PRINTF) -o $(BONUS_NAME) $(MLX)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUSOBJDIR)/%.o: $(BONUSDIR)/%.c | $(BONUSOBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BONUSOBJDIR):
	mkdir -p $(BONUSOBJDIR)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

clean: 
	$(RM) $(OBJ) $(BONUS_OBJ)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all

.PHONY: re fclean all bonus