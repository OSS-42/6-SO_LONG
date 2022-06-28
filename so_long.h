/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:25:23 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/28 15:03:53 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "includes/mlx/mlx.h"
# include "includes/libft/libft.h"
# include <stdio.h>

typedef struct s_images
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
}	t_images;

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

}	t_data;

int		endgame(t_data *img);
int		key_hook(int keycode, t_data *img);
void	init_level(t_data *img);
void	draw_map(t_data *img, t_images level_1);
void	top_line(t_data *img, t_images level_1);
void	middle_line(t_data *img, t_images level_1);
void	bottom_line(t_data *img, t_images level_1);
void	newgame(t_data *img);

#endif
