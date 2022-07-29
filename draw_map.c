/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:02:31 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/29 11:07:36 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	top_line(t_data *img)
{
	img->lvl1->y = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->corner_1,
		img->lvl1->img_x, img->lvl1->img_y);
	img->lvl1->y++;
	while (img->lvl1->y < (img->lenght - 2))
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->wall_top,
			img->lvl1->y * 64, img->lvl1->img_y);
		img->lvl1->y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->corner_2,
		img->lvl1->y * 64, img->lvl1->img_y);
}

void	middle_line(t_data *img)
{
	img->lvl1->y = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->wall_left,
		img->lvl1->img_x, img->lvl1->img_y);
	img->lvl1->y = 1;
	while (img->lvl1->y < (img->lenght - 2))
	{
		if (img->map[img->lvl1->x][img->lvl1->y] == '1')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->pilar,
				img->lvl1->y * 64, img->lvl1->img_y);
		if (img->map[img->lvl1->x][img->lvl1->y] == '0')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->floor,
				img->lvl1->y * 64, img->lvl1->img_y);
		if (img->map[img->lvl1->x][img->lvl1->y] == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->exit,
				img->lvl1->y * 64, img->lvl1->img_y);
		if (img->map[img->lvl1->x][img->lvl1->y] == 'C')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->collectible,
				img->lvl1->y * 64, img->lvl1->img_y);
		if (img->map[img->lvl1->x][img->lvl1->y] == 'P')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->start,
				img->lvl1->y * 64, img->lvl1->img_y);
		img->lvl1->y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->wall_right,
		img->lvl1->y * 64, img->lvl1->img_y);
}

void	bottom_line(t_data *img)
{
	img->lvl1->y = 0;
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->corner_3,
		img->lvl1->img_x, img->lvl1->img_y);
	img->lvl1->y = 1;
	while (img->lvl1->y < (img->lenght - 2))
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->wall_bottom,
			img->lvl1->y * 64, img->lvl1->img_y);
		img->lvl1->y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->corner_4,
		img->lvl1->y * 64, img->lvl1->img_y);
}

void	draw_map(t_data *img)
{
	img->lvl1->x = 0;
	img->lvl1->img_x = 0;
	img->lvl1->img_y = 0;
	top_line(img);
	img->lvl1->x = 1;
	img->lvl1->img_x = 0;
	img->lvl1->img_y = img->lvl1->img_y + 64;
	while (img->lvl1->x < img->lines - 1)
	{
		middle_line(img);
		img->lvl1->x++;
		img->lvl1->img_x = 0;
		img->lvl1->img_y = img->lvl1->img_y + 64;
	}
	bottom_line(img);
}
