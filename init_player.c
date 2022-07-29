/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:54:16 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/29 11:43:12 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//x et y dans l'image sont inversés dans un tableau.
//donc dans img->map[x][y] (classique), x = img->player_y et y = img->player_x
//attention au 0 dans les 2 cas.

void	search_collectibles(t_data *img, char z)
{
	int	x;
	int	y;
	int	w;

	w = 0;
	x = 0;
	img->total_c = 0;
	while (x < img->lines - 1)
	{
		y = 0;
		while (img->map[x][y])
		{
			if (z == 'C' && img->map[x][y] == z)
			{
				img->total_c++;
				w = 1;
			}
			else if (img->map[x][y] == z)
				w = 2;
			y++;
		}
		x++;
	}
	if ((z == 'C' && img->total_c == 0) || w == 0)
		img->error_code = 10;
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

static void	init_images(t_data *img)
{
	int	img_width;
	int	img_height;

	img->player->p_right = mlx_xpm_file_to_image(img->mlx,
			"assets/perso_right.xpm", &img_width, &img_height);
	img->player->p_left = mlx_xpm_file_to_image(img->mlx,
			"assets/perso_left.xpm", &img_width, &img_height);
}

void	init_player(t_data *img)
{
	img->player = malloc(sizeof(t_player));
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
	init_images(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->player->p_right,
		img->player_x * 64, img->player_y * 64);
}
