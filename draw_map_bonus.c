/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:02:31 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/26 11:49:15 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	convert_data(t_data *img, int index, int data)
{
	char	*str;
	
	str = ft_itoa(data);
	if (index == 1)
		mlx_string_put(img->mlx, img->mlx_win, 80, 0, 0x00FF0000, str);
	else if (index == 2)
		mlx_string_put(img->mlx, img->mlx_win, 80, 25, 0x6922ff, str);
	else
		free (str);
}

void	top_line(t_data *img, t_level lvl1)
{
	lvl1.y = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.corner_1,
		lvl1.img_x, lvl1.img_y);
	lvl1.y++;
	while (lvl1.y < (img->lenght - 2))
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.wall_top,
			lvl1.y * 64, lvl1.img_y);
		lvl1.y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.corner_2,
		lvl1.y * 64, lvl1.img_y);
}

void	middle_line(t_data *img, t_level lvl1)
{
	lvl1.y = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.wall_left,
		lvl1.img_x, lvl1.img_y);
	lvl1.y = 1;
	while (lvl1.y < (img->lenght - 2))
	{
		if (img->map[lvl1.x][lvl1.y] == '1')
			mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.pilar,
				lvl1.y * 64, lvl1.img_y);
		if (img->map[lvl1.x][lvl1.y] == '0' || img->map[lvl1.x][lvl1.y] == 'Z')
			mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.floor,
				lvl1.y * 64, lvl1.img_y);
		if (img->map[lvl1.x][lvl1.y] == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.exit,
				lvl1.y * 64, lvl1.img_y);
		if (img->map[lvl1.x][lvl1.y] == 'C')
			mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.collectible,
				lvl1.y * 64, lvl1.img_y);
		if (img->map[lvl1.x][lvl1.y] == 'P')
			mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.start,
				lvl1.y * 64, lvl1.img_y);
		lvl1.y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.wall_right,
		lvl1.y * 64, lvl1.img_y);
}

void	bottom_line(t_data *img, t_level lvl1)
{
	lvl1.y = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.corner_3,
		lvl1.img_x, lvl1.img_y);
	lvl1.y = 1;
	while (lvl1.y < (img->lenght - 2))
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.wall_bottom,
			lvl1.y * 64, lvl1.img_y);
		lvl1.y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, lvl1.corner_4,
		lvl1.y * 64, lvl1.img_y);
}

void	draw_map(t_data *img, t_level lvl1)
{
	mlx_string_put(img->mlx, img->mlx_win, 0, 0, 0x00FF0000, "Moves :");
	mlx_string_put(img->mlx, img->mlx_win, 0, 25, 0x6922ff, "Bottles :");
	convert_data(img, 1, img->moves);
	convert_data(img, 2, img->collectibles);
	lvl1.x = 0;
	lvl1.img_x = 0;
	lvl1.img_y = 50;
	top_line(img, lvl1);
	lvl1.x = 1;
	lvl1.img_x = 0;
	lvl1.img_y = lvl1.img_y + 64;
	while (lvl1.x < img->lines - 1)
	{
		middle_line(img, lvl1);
		lvl1.x++;
		lvl1.img_x = 0;
		lvl1.img_y = lvl1.img_y + 64;
	}
	bottom_line(img, lvl1);
}
