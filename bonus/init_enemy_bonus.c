/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:22:53 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/27 16:31:30 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//x et y dans l'image sont inversés dans un tableau.
//donc dans img->map[x][y] (classique), x = img->player_y et y = img->player_x
//attention au 0 dans les 2 cas.

void	animated_enemy(t_data *img)
{
	int	img_width;
	int	img_height;
	int	x;

	x = 0;	
	while (x < 5000)
	{
		img->enemy = mlx_xpm_file_to_image(img->mlx, "assets/patrouille.xpm",
			&img_width, &img_height);
		sleep(5);
		img->enemy = mlx_xpm_file_to_image(img->mlx, "assets/patrouille2.xpm",
			&img_width, &img_height);
		sleep(5);
		x++;
	}
}

static void random_start(t_data *img)
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
	img->enemy = mlx_xpm_file_to_image(img->mlx, "assets/patrouille.xpm",
			&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->enemy,
		img->enemy_x * 64, img->enemy_y * 64 + 50);
}
