/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:25:27 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/29 12:56:42 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_level_walls(t_data *img)
{
	int		img_width;
	int		img_height;

	img->lvl1->wall_right = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_window_right.xpm", &img_width, &img_height);
	img->lvl1->wall_left = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_window_left.xpm", &img_width, &img_height);
	img->lvl1->wall_top = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_window_top.xpm", &img_width, &img_height);
	img->lvl1->wall_bottom = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_window_bottom.xpm", &img_width, &img_height);
	init_level_corners(img);
}

void	init_level_corners(t_data *img)
{
	int		img_width;
	int		img_height;

	img->lvl1->corner_1 = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_corner_1.xpm", &img_width, &img_height);
	img->lvl1->corner_2 = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_corner_2.xpm", &img_width, &img_height);
	img->lvl1->corner_3 = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_corner_3.xpm", &img_width, &img_height);
	img->lvl1->corner_4 = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_wall_corner_4.xpm", &img_width, &img_height);
	draw_map(img);
}

void	init_level(t_data *img)
{
	int		img_width;
	int		img_height;

	img->lvl1 = malloc(sizeof(t_level));
	img->lvl1->floor = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_floor.xpm", &img_width, &img_height);
	img->lvl1->pilar = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_table_mac.xpm", &img_width, &img_height);
	img->lvl1->collect = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_collectible.xpm", &img_width, &img_height);
	img->lvl1->start = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_entry.xpm", &img_width, &img_height);
	img->lvl1->exit = mlx_xpm_file_to_image(img->mlx,
			"assets/tile_42.xpm", &img_width, &img_height);
	init_level_walls(img);
}
