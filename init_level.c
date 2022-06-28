/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:25:27 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/28 15:11:45 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	top_line(t_data *img, t_images level_1)
{
	level_1.y = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.corner_1, level_1.img_x, level_1.img_y);
	level_1.y++;
	while (level_1.y < (img->lenght - 2))
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.wall_top, level_1.y * 64, level_1.img_y);
		level_1.y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.corner_2, level_1.y * 64, level_1.img_y);
	printf("%s\n", "top line drawed");
}

void	middle_line(t_data *img, t_images level_1)
{
	level_1.y = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.wall_left, level_1.img_x, level_1.img_y);
	level_1.y = 1;
	while (level_1.y < (img->lenght - 2))
	{
		if (img->map[level_1.x][level_1.y] == '1')
			mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.pilar, level_1.y * 64, level_1.img_y);
		if (img->map[level_1.x][level_1.y] == '0')
			mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.floor, level_1.y * 64, level_1.img_y);
		if (img->map[level_1.x][level_1.y] == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.exit, level_1.y * 64, level_1.img_y);
		if (img->map[level_1.x][level_1.y] == 'C')
			mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.collectible, level_1.y * 64, level_1.img_y);
		if (img->map[level_1.x][level_1.y] == 'P')
			mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.start, level_1.y * 64, level_1.img_y);
		level_1.y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.wall_right, level_1.y * 64, level_1.img_y);
	printf("%s\n", "middle line drawed");
}

void	bottom_line(t_data *img, t_images level_1)
{
	level_1.y = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.corner_3, level_1.img_x, level_1.img_y);
	level_1.y = 1;
	while (level_1.y < (img->lenght - 2))
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.wall_bottom, level_1.y * 64, level_1.img_y);
		level_1.y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.corner_4, level_1.y * 64, level_1.img_y);
	printf("%s\n", "bottom line drawed");
}

void	draw_map(t_data *img, t_images level_1)
{
	level_1.x = 0;
	level_1.img_x = 0;
	level_1.img_y = 25;
	top_line(img, level_1);
	level_1.x = 1;
	level_1.img_x = 0;
	level_1.img_y = level_1.img_y + 64;
	while (level_1.x < img->lines - 1)
	{
		middle_line(img, level_1);
		level_1.x++;
		level_1.img_x = 0;
		level_1.img_y = level_1.img_y + 64;
	}
	bottom_line(img, level_1);
}

void	init_level(t_data *img)
{
	t_images	level_1;
	int	img_width;
	int	img_height;

	level_1.wall_right = mlx_xpm_file_to_image(img->mlx, "assets/tile_wall_window_right.xpm", &img_width, &img_height);
	level_1.wall_left = mlx_xpm_file_to_image(img->mlx, "assets/tile_wall_window_left.xpm", &img_width, &img_height);
	level_1.wall_top = mlx_xpm_file_to_image(img->mlx,"assets/tile_wall_window_top.xpm", &img_width, &img_height);
	level_1.wall_bottom = mlx_xpm_file_to_image(img->mlx, "assets/tile_wall_window_bottom.xpm", &img_width, &img_height);
	level_1.corner_1 = mlx_xpm_file_to_image(img->mlx, "assets/tile_wall_corner_1.xpm", &img_width, &img_height);
	level_1.corner_2 = mlx_xpm_file_to_image(img->mlx, "assets/tile_wall_corner_2.xpm", &img_width, &img_height);
	level_1.corner_3 = mlx_xpm_file_to_image(img->mlx, "assets/tile_wall_corner_3.xpm", &img_width, &img_height);
	level_1.corner_4 = mlx_xpm_file_to_image(img->mlx, "assets/tile_wall_corner_4.xpm", &img_width, &img_height);
	level_1.floor = mlx_xpm_file_to_image(img->mlx, "assets/tile_floor.xpm", &img_width, &img_height);
	level_1.pilar = mlx_xpm_file_to_image(img->mlx, "assets/tile_pilar.xpm", &img_width, &img_height);
	level_1.collectible = mlx_xpm_file_to_image(img->mlx, "assets/tile_collectible.xpm", &img_width, &img_height);
	level_1.start = mlx_xpm_file_to_image(img->mlx, "assets/tile_start.xpm", &img_width, &img_height);
	level_1.exit = mlx_xpm_file_to_image(img->mlx, "assets/tile_exit.xpm", &img_width, &img_height); 

	draw_map(img, level_1);
}