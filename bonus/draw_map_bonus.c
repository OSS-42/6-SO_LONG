/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:02:31 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/28 15:02:52 by ewurstei         ###   ########.fr       */
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
	free (str);
}

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
		if (img->map[img->lvl1->x][img->lvl1->y] == '0'
			|| img->map[img->lvl1->x][img->lvl1->y] == 'Z')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->floor,
				img->lvl1->y * 64, img->lvl1->img_y);
		if (img->map[img->lvl1->x][img->lvl1->y] == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->lvl1->exit,
				img->lvl1->y * 64, img->lvl1->img_y);
		if (img->map[img->lvl1->x][img->lvl1->y] == 'C')
			mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->lvl1->collectible,
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
	mlx_string_put(img->mlx, img->mlx_win, 0, 0, 0x00FF0000, "Moves :");
	mlx_string_put(img->mlx, img->mlx_win, 0, 25, 0x6922ff, "Bottles :");
	convert_data(img, 1, img->moves);
	convert_data(img, 2, img->collectibles);
	img->lvl1->x = 0;
	img->lvl1->img_x = 0;
	img->lvl1->img_y = 50;
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
