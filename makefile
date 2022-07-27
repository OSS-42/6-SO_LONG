#VARIABLES

NAME = so_long
NAME_BONUS = so_long_bonus

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -f
LIBFT = libft.a
DIR_MLX = includes/mlx/
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
SRC = so_long.c newgame.c init_assets.c init_player.c player_moves.c draw_map.c \
		check_map.c newgame_utils.c
SRC_BONUS = bonus/so_long_bonus.c\
			bonus/newgame_bonus.c\
			bonus/init_assets_bonus.c\
			bonus/init_player_bonus.c\
			bonus/player_moves_bonus.c\
			bonus/draw_map_bonus.c\
			bonus/check_map_bonus.c\
			bonus/init_enemy_bonus.c\
			bonus/enemy_moves_bonus.c\
			bonus/newgame_utils_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

.c.o :
#Pour MacOs
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
#Pour Linux
#	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

#$(V).SILENT:

all:	$(DIR_LIBFT)/$(LIBFT) $(NAME)

$(NAME):	$(OBJ) $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(DIR_LIBFT)$(LIBFT)
	@echo "$(LGREEN)MLX pour MACOs ready !$(DEF_COLOR)"
#	$(CC) $(CFLAGS) $(OBJ) -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME) $(LDIR)$(LIBFT)
#	@echo "$(LGREEN)MLX  pour Linux ready !$(DEF_COLOR)"
#	$(AR) $(NAME) $(OBJ)
	@echo "$(LGREEN)Compilation complete !$(DEF_COLOR)"

$(DIR_LIBFT)/$(LIBFT):
	make -C $(DIR_LIBFT)
	@echo "$(LGREEN)LIBFT done... !$(DEF_COLOR)"

$(NAME_BONUS): $(OBJ_BONUS) $(SRC_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(DIR_LIBFT)$(LIBFT)
	@echo "$(LGREEN)MLX et bonus pour MACOs ready !$(DEF_COLOR)"

bonus: $(DIR_LIBFT)/$(LIBFT) $(NAME_BONUS)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	$(RM) $(DIR_LIBFT)*.o
	@echo "$(LCYAN)Objects files cleaned !$(DEF_COLOR)"

fclean:	clean
	$(RM) $(DIR_LIBFT)$(LIBFT)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) *.o
	@echo "$(LCYAN)Executables files cleaned !$(DEF_COLOR)"

re:	fclean all