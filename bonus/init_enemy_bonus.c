/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:22:53 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/29 11:49:54 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//x et y dans l'image sont inversés dans un tableau.
//donc dans img->map[x][y] (classique), x = img->player_y et y = img->player_x
//attention au 0 dans les 2 cas.

int	animated_enemy(t_data *img)
{
	img->frames->frame++;
	if (img->frames->frame % 2500 == 0)
	{
		img->frames->frame_enemy++;
		if (img->frames->frame_enemy == 2)
		{
			img->frames->frame_enemy = 0;
			img->frames->frame = 0;
		}
		print_moves(img);
	}
	return (0);
}

static void	random_start(t_data *img)
{
	img->enemy_x = rand() % (img->lenght - 2);
	img->enemy_y = rand() % (img->lines - 2);
	if (img->map[img->enemy_y][img->enemy_x] == '1'
		|| img->map[img->enemy_y][img->enemy_x] == 'P')
		random_start(img);
}

void	init_enemy(t_data *img)
{
	int	img_width;
	int	img_height;

	random_start(img);
	img->frames = malloc(sizeof(t_enemy));
	img->frames->frame_enemy = 0;
	img->frames->frame = 0;
	img->frames->enemy_pic[0] = mlx_xpm_file_to_image(img->mlx,
			"assets/patrouille.xpm", &img_width, &img_height);
	img->frames->enemy_pic[1] = mlx_xpm_file_to_image(img->mlx,
			"assets/patrouille2.xpm", &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->frames->enemy_pic[0],
		img->enemy_x * 64, img->enemy_y * 64 + 50);
}
