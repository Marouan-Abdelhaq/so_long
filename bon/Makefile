# Nom du programme
NAME = so_long

# Dossiers des fichiers source
SRC_DIR = .
OBJ_DIR = obj
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
GNL_DIR = get_next_line
PRINTF_DIR = ft_printf

# Liste des fichiers source
SRC_FILES = main.c read_map.c render_map.c load_text.c handl_input.c moves_player.c handl_error.c ft_exit.c check_path.c enmy.c\
            $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

# Génération des fichiers objets (.o)
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

# Flags de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L $(MLX_DIR) -lmlx -lXext -lX11
LIBFT_FLAGS = -L $(LIBFT_DIR) -lft
PRINTF_FLAGS = -L $(PRINTF_DIR) -lftprintf

# Règle pour compiler le programme
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)  # Ajout de ft_printf
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(LIBFT_FLAGS) $(PRINTF_FLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)
	@echo "✅ Compilation terminée !"

# Création du dossier obj avant compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | create_obj_dirs
	@$(CC) $(CFLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -c $< -o $@

# Créer les dossiers obj et obj/get_next_line si nécessaires
create_obj_dirs:
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/$(GNL_DIR)

clean:
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean  # Nettoyage de ft_printf
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Fichiers objets supprimés !"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean  # Suppression complète de ft_printf
	@rm -f $(NAME)
	@echo "🧹 Exécutable supprimé !"

# Recompilation complète
re: fclean all

# Règle pour exécuter le jeu avec une map par défaut
run: all
	@./so_long maps/test.ber

.PHONY: all clean fclean re run create_obj_dirs
