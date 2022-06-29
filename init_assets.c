/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:25:27 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/29 15:07:19 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_level_walls(t_data *img, t_level level_1)
{
	int		img_width;
	int		img_height;

	level_1.wall_right = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_window_right.xpm", &img_width, &img_height);
	level_1.wall_left = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_window_left.xpm", &img_width, &img_height);
	level_1.wall_top = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_window_top.xpm", &img_width, &img_height);
	level_1.wall_bottom = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_window_bottom.xpm", &img_width, &img_height);
	init_level_corners(img, level_1);
}

void	init_level_corners(t_data *img, t_level level_1)
{
	int		img_width;
	int		img_height;

	level_1.corner_1 = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_corner_1.xpm", &img_width, &img_height);
	level_1.corner_2 = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_corner_2.xpm", &img_width, &img_height);
	level_1.corner_3 = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_corner_3.xpm", &img_width, &img_height);
	level_1.corner_4 = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_corner_4.xpm", &img_width, &img_height);
	draw_map(img, level_1);
}

void	init_level(t_data *img)
{
	t_level	level_1;
	int		img_width;
	int		img_height;

	level_1.floor = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_floor.xpm", &img_width, &img_height);
	level_1.pilar = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_pilar.xpm", &img_width, &img_height);
	level_1.collectible = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_collectible.xpm", &img_width, &img_height);
	level_1.start = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_start.xpm", &img_width, &img_height);
	level_1.exit = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_exit.xpm", &img_width, &img_height);
	init_level_walls(img, level_1);
}
