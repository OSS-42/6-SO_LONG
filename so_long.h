/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:25:23 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/02 11:29:08 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
//# include "includes/mlx/mlx.h"
# include <mlx.h>
# include "includes/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct s_player
{
	void	*p_right;
	void	*p_left;
}	t_player;

typedef struct s_level
{
	void	*corner_1;
	void	*corner_2;
	void	*corner_3;
	void	*corner_4;
	void	*wall_left;
	void	*wall_right;
	void	*wall_top;
	void	*wall_bottom;
	void	*floor;
	void	*pilar;
	void	*collect;
	void	*start;
	void	*exit;
	int		x;
	int		y;
	int		img_x;
	int		img_y;
}	t_level;

typedef struct s_data
{
	void		*img;
	void		*mlx;
	void		*mlx_win;
	char		**map;
	char		*argv;
	int			error_code;
	int			width;
	int			height;
	int			lines;
	int			lenght;
	int			moves;
	int			collect;
	int			total_c;
	int			player_x;
	int			player_y;
	int			p_dir;
	t_player	*player;
	t_level		*lvl1;
}	t_data;

void	newgame(t_data *img);
void	errors(t_data *img);
void	init_level(t_data *img);
void	init_level_walls(t_data *img);
void	init_level_corners(t_data *img);
void	check_map(t_data *img);
void	check_map_char(t_data *img);
void	check_map_walls(t_data *img);
void	check_map_rectangle(t_data *img);
void	check_map_name(t_data *img);
void	map_to_array(t_data *img);
void	draw_map(t_data *img);
void	search_collectibles(t_data *img, char z);
void	top_line(t_data *img);
void	middle_line(t_data *img);
void	bottom_line(t_data *img);
void	init_player(t_data *img);
int		key_hook(int keycode, t_data *img);
void	go_up(t_data *img);
void	go_down(t_data *img);
void	go_left(t_data *img);
void	go_right(t_data *img);
void	free_map(t_data *img);
void	free_all(t_data *img);
int		endgame(t_data *img);
int		quit_game(t_data *img);

#endif
