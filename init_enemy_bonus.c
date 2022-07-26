/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:22:53 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/26 12:49:58 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//x et y dans l'image sont inversés dans un tableau.
//donc dans img->map[x][y] (classique), x = img->player_y et y = img->player_x
//attention au 0 dans les 2 cas.

static int	search_start(char *string, char c)
{
	int	x;

	x = 1;
	while (string[x])
	{
		if (string[x] == c)
			return (x);
		x++;
	}
	return (0);
}

void	init_enemy(t_data *img)
{
	int	img_width;
	int	img_height;

	img->enemy_y = 1;
	while (img->enemy_y < img->lines - 1)
	{
		if (search_start(img->map[img->enemy_y], 'Z') != 0)
		{
			img->enemy_x = 1;
			while (img->map[img->enemy_y][img->enemy_x])
			{
				if (img->map[img->enemy_y][img->enemy_x] == 'Z')
					break ;
				img->enemy_x++;
			}
			break ;
		}
		img->enemy_y++;
	}
	img->enemy = mlx_xpm_file_to_image(img->mlx, "assets/patrouille.xpm",
			&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->enemy,
		img->enemy_x * 64, img->enemy_y * 64 + 50);
}
