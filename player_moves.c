/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:33:55 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/28 17:18:15 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_data *img)
{
	if (img->y - 1 == 0 || img->map[img->x][img->y - 1] == '1')
		mlx_string_put(img->mlx, img->mlx_win, 25, 25, 0x00FF0000,
			"Attention au mur !");
	else
	{
		printf("En haut !\n");
		img->moves = img->moves + 1;
		printf("%d\n", img->moves);
		img->y = img->y - 1;
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->player,
			img->x * 64, img->y * 64);
	}	
}

void	go_down(t_data *img)
{
	if (img->y + 1 == img->lines || img->map[img->x][img->y + 1] == '1')
		mlx_string_put(img->mlx, img->mlx_win, 25, 25, 0x00FF0000,
			"Attention au mur !");
	else
	{
		printf("En bas !\n");
		img->moves = img->moves + 1;
		printf("%d\n", img->moves);
		img->y = img->y + 1;
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->player,
			img->x * 64, img->y * 64);
	}	
}

void	go_left(t_data *img)
{
	if (img->x - 1 == 0 || img->map[img->x - 1][img->y] == '1')
		mlx_string_put(img->mlx, img->mlx_win, 25, 25, 0x00FF0000,
			"Attention au mur !");
	else
	{
		printf("A gauche !\n");
		img->moves = img->moves + 1;
		printf("%d\n", img->moves);
		img->x = img->x - 1;
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->player,
			img->x * 64, img->y * 64);
	}	
}

void	go_right(t_data *img)
{
	if (img->x + 1 == img->lenght - 2 || img->map[img->x + 1][img->y] == '1')
		mlx_string_put(img->mlx, img->mlx_win, 25, 25, 0x00FF0000,
			"Attention au mur !");
	else
	{
		printf("A droite !\n");
		img->moves = img->moves + 1;
		printf("%d\n", img->moves);
		img->x = img->x + 1;
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->player,
			img->x * 64, img->y * 64);
	}	
}
