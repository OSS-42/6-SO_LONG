/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:54:16 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/26 10:17:46 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//x et y dans l'image sont inversés dans un tableau.
//donc dans img->map[x][y] (classique), x = img->player_y et y = img->player_x
//attention au 0 dans les 2 cas.

int	search_collectibles(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	img->total_c = 0;
	while (x < img->lines - 1)
	{
		y = 0;
		while (img->map[x][y])
		{
			if (img->map[x][y] == 'C')
				img->total_c++;
			y++;
		}
		x++;
	}
	return (0);
}

static int	search_start(char *string, char c)
{
	int	x;

	x = 0;
	while (string[x])
	{
		if (string[x] == c)
			return (x);
		x++;
	}
	return (0);
}

void	init_player(t_data *img)
{
	int	img_width;
	int	img_height;

	img->player_y = 1;
	while (img->player_y < img->lines - 1)
	{
		if (search_start(img->map[img->player_y], 'P') != 0)
		{
			img->player_x = 1;
			while (img->map[img->player_y][img->player_x])
			{
				if (img->map[img->player_y][img->player_x] == 'P')
					break ;
				img->player_x++;
			}
			break ;
		}
		img->player_y++;
	}
	img->player = mlx_xpm_file_to_image(img->mlx, "assets/perso_right.xpm",
			&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->player,
		img->player_x * 64, img->player_y * 64 + 50);
	printf("player start x : %d\n", img->player_x);
	printf("player start y : %d\n", img->player_y);
}
