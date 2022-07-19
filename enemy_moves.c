/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:33:55 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/19 14:48:29 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	random_moves(t_data *img)
{
	img->random_dir = rand() % 4;
	printf ("random : %d\n", img->random_dir);

	if (img->random_dir == 0)
		enemy_go_left(img);
	else if (img->random_dir == 1)
		enemy_go_up(img);
	else if (img->random_dir == 2)
		enemy_go_right(img);
	else if (img->random_dir == 3)
		enemy_go_down(img);
}

void	enemy_go_up(t_data *img)
{
	if (img->map[img->enemy_y - 1][img->enemy_x] == '1')
	{
		printf("%s\n", "bloqué");
		random_moves(img);
	}
	else if (img->map[img->enemy_y - 1][img->enemy_x] != '1')
	{
		img->enemy_y = img->enemy_y - 1;
		printf("enemy x : %d\n", img->enemy_x);
		printf("enemy y : %d\n", img->enemy_y);
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
	if (img->map[img->enemy_y + 1][img->enemy_x] == '1')
	{
		printf("%s\n", "bloqué");
		random_moves(img);
	}
	else if (img->map[img->enemy_y + 1][img->enemy_x] != '1')
	{
		img->enemy_y = img->enemy_y + 1;
		printf("enemy x : %d\n", img->enemy_x);
		printf("enemy y : %d\n", img->enemy_y);
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
	if (img->map[img->enemy_y][img->enemy_x - 1] == '1')
	{
		printf("%s\n", "bloqué");
		random_moves(img);
	}
	else if (img->map[img->enemy_y][img->enemy_x - 1] != '1')
	{
		img->enemy_x = img->enemy_x - 1;
		printf("enemy x : %d\n", img->enemy_x);
		printf("enemy y : %d\n", img->enemy_y);
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
	if (img->map[img->enemy_y][img->enemy_x + 1] == '1')
	{
		printf("%s\n", "bloqué");
		random_moves(img);
	}
	else if (img->map[img->enemy_y][img->enemy_x + 1] != '1')
	{
		img->enemy_x = img->enemy_x + 1;
		printf("enemy x : %d\n", img->enemy_x);
		printf("enemy y : %d\n", img->enemy_y);
		if (img->enemy_x + 1 == img->player_x
			&& img->enemy_y == img->player_y)
		{
			printf("%s\n", "TIG ! vous avez perdu !");
			exit (0);
		}
	}	
}
