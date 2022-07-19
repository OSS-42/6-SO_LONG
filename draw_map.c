/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:02:31 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/19 16:26:03 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void convert_data(t_data *img, int x, int y, unsigned color, int data)
{
	char	*str;
	
	str = ft_itoa(data);
	mlx_string_put(img->mlx, img->mlx_win, x, y, color, str);
	free (str);	
}

void	top_line(t_data *img, t_level level_1)
{
	level_1.y = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.corner_1,
		level_1.img_x, level_1.img_y);
	level_1.y++;
	while (level_1.y < (img->lenght - 2))
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.wall_top,
			level_1.y * 64, level_1.img_y);
		level_1.y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.corner_2,
		level_1.y * 64, level_1.img_y);
}

void	middle_line(t_data *img, t_level level_1)
{
	level_1.y = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.wall_left,
		level_1.img_x, level_1.img_y);
	level_1.y = 1;
	while (level_1.y < (img->lenght - 2))
	{
		if (img->map[level_1.x][level_1.y] == '1')
			mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.pilar,
				level_1.y * 64, level_1.img_y);
		if (img->map[level_1.x][level_1.y] == '0' || img->map[level_1.x][level_1.y] == 'Z')
			mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.floor,
				level_1.y * 64, level_1.img_y);
		if (img->map[level_1.x][level_1.y] == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.exit,
				level_1.y * 64, level_1.img_y);
		if (img->map[level_1.x][level_1.y] == 'C')
			mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.collectible,
				level_1.y * 64, level_1.img_y);
		if (img->map[level_1.x][level_1.y] == 'P')
			mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.start,
				level_1.y * 64, level_1.img_y);
		level_1.y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.wall_right,
		level_1.y * 64, level_1.img_y);
}

void	bottom_line(t_data *img, t_level level_1)
{
	level_1.y = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.corner_3,
		level_1.img_x, level_1.img_y);
	level_1.y = 1;
	while (level_1.y < (img->lenght - 2))
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.wall_bottom,
			level_1.y * 64, level_1.img_y);
		level_1.y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.corner_4,
		level_1.y * 64, level_1.img_y);
}

void	draw_map(t_data *img, t_level level_1)
{
	mlx_string_put(img->mlx, img->mlx_win, 0, 0, 0x00FF0000, "Moves :");
	mlx_string_put(img->mlx, img->mlx_win, 0, 25, 0x6922ff, "Bottles :");
	convert_data(img, 80, 0, 0x00FF0000, img->moves);
	convert_data(img, 80, 25, 0x6922ff, img->collectibles);
	level_1.x = 0;
	level_1.img_x = 0;
	level_1.img_y = 50;
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
