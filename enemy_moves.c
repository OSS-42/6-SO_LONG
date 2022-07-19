/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:33:55 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/19 11:11:28 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_go_up(t_data *img)
{
	printf("enemy x : %d\n", img->enemy_x);
	printf("enemy y : %d\n", img->enemy_y);
	printf("player x : %d\n", img->player_x);
	printf("player y : %d\n", img->player_y);
	if (img->map[img->enemy_y - 1][img->enemy_x] != '1')
	{
		img->enemy_y = img->enemy_y - 1;
		if (img->enemy_y - 1 == img->player_y
			&& img->enemy_x == img->player_x)
		{
			printf("%s\n", "TIG ! vous avez perdu !");
			exit (0);
		}
	}	
}

void	enemy_go_down(t_data *img)
{
	printf("enemy x : %d\n", img->enemy_x);
	printf("enemy y : %d\n", img->enemy_y);
	printf("player x : %d\n", img->player_x);
	printf("player y : %d\n", img->player_y);
	if (img->map[img->enemy_y + 1][img->enemy_x] != '1')
	{
		img->enemy_y = img->enemy_y + 1;
		if (img->enemy_y + 1 == img->player_y
			&& img->enemy_x == img->player_x)
		{
			printf("%s\n", "TIG ! vous avez perdu !");
			exit (0);
		}
	}	
}

void	enemy_go_left(t_data *img)
{
	printf("enemy x : %d\n", img->enemy_x);
	printf("enemy y : %d\n", img->enemy_y);
	printf("player x : %d\n", img->player_x);
	printf("player y : %d\n", img->player_y);
	if (img->map[img->enemy_y][img->enemy_x - 1] != '1')
	{
		img->enemy_x = img->enemy_x - 1;
		if (img->enemy_x - 1 == img->player_x
			&& img->enemy_y == img->player_y)
		{
			printf("%s\n", "TIG ! vous avez perdu !");
			exit (0);
		}
	}	
}

void	enemy_go_right(t_data *img)
{
	printf("enemy x : %d\n", img->enemy_x);
	printf("enemy y : %d\n", img->enemy_y);
	printf("player x : %d\n", img->player_x);
	printf("player y : %d\n", img->player_y);
	if (img->map[img->enemy_y][img->enemy_x + 1] != '1')
	{
		img->enemy_x = img->enemy_x + 1;
		if (img->enemy_x + 1 == img->player_x
			&& img->enemy_y == img->player_x)
		{
			printf("%s\n", "TIG ! vous avez perdu !");
			exit (0);
		}
	}	
}
