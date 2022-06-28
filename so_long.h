/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:25:23 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/28 17:23:03 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "includes/mlx/mlx.h"
# include "includes/libft/libft.h"
# include <stdio.h>

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
	void	*collectible;
	void	*start;
	void	*exit;
	int		x;
	int		y;
	int		img_x;
	int		img_y;
}	t_level;

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		width;
	int		height;
	int		lines;
	int		lenght;
	int		moves;
	int		x;
	int		y;
	int		img_x;
	int		img_y;
	void	*player;

}	t_data;

void	newgame(t_data *img);
void	init_level(t_data *img);
void	draw_map(t_data *img, t_level level_1);
void	top_line(t_data *img, t_level level_1);
void	middle_line(t_data *img, t_level level_1);
void	bottom_line(t_data *img, t_level level_1);
void	init_player(t_data *img);
int		key_hook(int keycode, t_data *img);
void	go_up(t_data *img);
void	go_down(t_data *img);
void	go_left(t_data *img);
void	go_right(t_data *img);
int		endgame(t_data *img);

#endif
