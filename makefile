#VARIABLES
NAME = so_long
NAME_BONUS = so_long_bonus

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -f
LIBFT = libft.a
DIR_LIBFT = includes/libft/
DIR_BONUS = bonus/

#COLORS
LRED = \033[91m
LGREEN = \033[92m
LYELLOW = \033[93
LMAGENTA = \033[95m
LCYAN = \033[96m
DEF_COLOR = \033[0;39m

#SOURCES
SRC = so_long.c\
	  newgame.c\
	  init_assets.c\
	  init_player.c\
	  player_moves.c\
	  draw_map.c \
	  check_map.c\
	  end_of_game.c\
	  free_and_destroy.c
SRC_BONUS = bonus/so_long_bonus.c\
			bonus/newgame_bonus.c\
			bonus/init_assets_bonus.c\
			bonus/init_player_bonus.c\
			bonus/player_moves_bonus.c\
			bonus/draw_map_bonus.c\
			bonus/check_map_bonus.c\
			bonus/init_enemy_bonus.c\
			bonus/enemy_moves_bonus.c\
			bonus/end_of_game_bonus.c\
			bonus/free_and_destroy_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

.c.o :
#Pour MacOs
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
#Pour Linux
#	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

#$(V).SILENT:

all:	$(NAME)

$(NAME):	$(DIR_LIBFT)/$(LIBFT) $(OBJ) $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(DIR_LIBFT)$(LIBFT)
	@echo "$(LGREEN)MLX pour MACOs ready !$(DEF_COLOR)"
#	$(CC) $(CFLAGS) $(OBJ) -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME) $(LDIR)$(LIBFT)
#	@echo "$(LGREEN)MLX  pour Linux ready !$(DEF_COLOR)"
	@echo "$(LGREEN)Compilation complete !$(DEF_COLOR)"

$(DIR_LIBFT)/$(LIBFT):
	make -C $(DIR_LIBFT)
	@echo "$(LGREEN)LIBFT done... !$(DEF_COLOR)"

$(NAME_BONUS): $(DIR_LIBFT)/$(LIBFT) $(OBJ_BONUS) $(SRC_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(DIR_LIBFT)$(LIBFT)
	@echo "$(LGREEN)MLX et bonus pour MACOs ready !$(DEF_COLOR)"
	@echo "$(LGREEN)Compilation complete !$(DEF_COLOR)"

bonus: $(DIR_LIBFT)/$(LIBFT) $(NAME_BONUS)

tests:	all
	@echo ""
	@echo "---==== VERSION MANDATOIRE ====---"
	@echo ""
	@echo "Vous ne devriez voir que des erreurs. Si une carte/jeu se load, c'est un fail"
	@echo ""
	@echo "Test FD en problème"
	./$(NAME) maps/mip.ber
	@echo ""
	@echo "Nombre d'arguments en problème"
	./$(NAME) maps/map.ber maps/map1.ber
	@echo ""
	@echo "Nom de fichier en problème"
	./$(NAME) maps/map.bert
	@echo ""
	@echo "Carte inexistante (NULL)"
	./$(NAME) maps/null.ber
	@echo ""
	@echo "Carte trop petite"
	./$(NAME) maps/too_small.ber
	@echo ""
	@echo "Carte avec mauvais caractère (test 1)"
	./$(NAME) maps/bad.ber
	@echo ""
	@echo "Carte avec mauvais caractère (test 2)"
	./$(NAME) maps/bad1.ber
	@echo ""
	@echo "Carte pas rectangle"
	./$(NAME) maps/bad2.ber
	@echo ""
	@echo "Carte problème de mur (test 1)"
	./$(NAME) maps/bad3.ber
	@echo ""
	@echo "Carte problème de mur (test 2)"
	./$(NAME) maps/bad4.ber
	@echo ""
	@echo "Carte problème de mur (test 3)"
	./$(NAME) maps/bad5.ber
	@echo ""
	@echo "Carte caractère manquant (test 1 - P)"
	./$(NAME) maps/bad6.ber
	@echo ""
	@echo "Carte caractère manquant (test 2 - E)"
	./$(NAME) maps/bad7.ber
	@echo ""
	@echo "Carte caractère manquant (test 3 - C)"
	./$(NAME) maps/bad8.ber
	@echo ""
	@echo "Carte doublon (P)"
	./$(NAME) maps/bad9.ber
	@echo ""

btests : bonus
	@echo ""
	@echo "---==== VERSION BONUS ====---"
	@echo ""
	@echo "Vous ne devriez voir que des erreurs. Si une carte/jeu se load, c'est un fail"
	@echo ""
	@echo "Test FD en problème"
	./$(NAME) maps/mip.ber
	@echo ""
	@echo "Nombre d'arguments en problème"
	./$(NAME) maps/map.ber maps/map1.ber
	@echo ""
	@echo "Nom de fichier en problème"
	./$(NAME) maps/map.bert
	@echo ""
	@echo "Carte inexistante (NULL)"
	./$(NAME) maps/null.ber
	@echo ""
	@echo "Carte trop petite"
	./$(NAME) maps/too_small.ber
	@echo ""
	@echo "Carte avec mauvais caractère (test 1)"
	./$(NAME) maps/bad.ber
	@echo ""
	@echo "Carte avec mauvais caractère (test 2)"
	./$(NAME) maps/bad1.ber
	@echo ""
	@echo "Carte pas rectangle"
	./$(NAME) maps/bad2.ber
	@echo ""
	@echo "Carte problème de mur (test 1)"
	./$(NAME) maps/bad3.ber
	@echo ""
	@echo "Carte problème de mur (test 2)"
	./$(NAME) maps/bad4.ber
	@echo ""
	@echo "Carte problème de mur (test 3)"
	./$(NAME) maps/bad5.ber
	@echo ""
	@echo "Carte caractère manquant (test 1 - P)"
	./$(NAME) maps/bad6.ber
	@echo ""
	@echo "Carte caractère manquant (test 2 - E)"
	./$(NAME) maps/bad7.ber
	@echo ""
	@echo "Carte caractère manquant (test 3 - C)"
	./$(NAME) maps/bad8.ber
	@echo ""
	@echo "Carte doublon (P)"
	./$(NAME) maps/bad9.ber
	@echo ""

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	make -C $(DIR_LIBFT) clean
	@echo "$(LCYAN)Objects files cleaned !$(DEF_COLOR)"

fclean:	clean
	$(RM) $(DIR_LIBFT)$(LIBFT)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	@echo "$(LCYAN)Executables files cleaned !$(DEF_COLOR)"

re:	fclean all