/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:33:55 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/02 11:24:55 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_moves(t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	draw_map(img);
	if (img->p_dir == 2)
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->player->p_left, img->player_x * 64, img->player_y * 64);
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->player->p_right, img->player_x * 64, img->player_y * 64);
}

void	go_up(t_data *img)
{
	if (img->map[img->player_y - 1][img->player_x] != '1')
	{
		if (img->map[img->player_y - 1][img->player_x] == 'C')
		{
			img->map[img->player_y - 1][img->player_x] = '0';
			img->collect++;
		}
		if (img->map[img->player_y - 1][img->player_x] == 'E')
		{
			if (img->collect == img->total_c)
				endgame(img);
		}
		img->player_y = img->player_y - 1;
		img->moves = img->moves + 1;
		printf("%d\n", img->moves);
		img->p_dir = 1;
		print_moves(img);
	}	
}

void	go_down(t_data *img)
{
	if (img->map[img->player_y + 1][img->player_x] != '1')
	{
		if (img->map[img->player_y + 1][img->player_x] == 'C')
		{
			img->map[img->player_y + 1][img->player_x] = '0';
			img->collect++;
		}
		if (img->map[img->player_y + 1][img->player_x] == 'E')
		{
			if (img->collect == img->total_c)
				endgame(img);
		}
		img->player_y = img->player_y + 1;
		img->moves = img->moves + 1;
		printf("%d\n", img->moves);
		img->p_dir = 1;
		print_moves(img);
	}	
}

void	go_left(t_data *img)
{
	if (img->map[img->player_y][img->player_x - 1] != '1')
	{
		if (img->map[img->player_y][img->player_x - 1] == 'C')
		{
			img->map[img->player_y][img->player_x - 1] = '0';
			img->collect++;
		}
		if (img->map[img->player_y][img->player_x - 1] == 'E')
		{
			if (img->collect == img->total_c)
				endgame(img);
		}
		img->player_x = img->player_x - 1;
		img->moves = img->moves + 1;
		printf("%d\n", img->moves);
		img->p_dir = 2;
		print_moves(img);
	}	
}

void	go_right(t_data *img)
{
	if (img->map[img->player_y][img->player_x + 1] != '1')
	{
		if (img->map[img->player_y][img->player_x + 1] == 'C')
		{
			img->map[img->player_y][img->player_x + 1] = '0';
			img->collect++;
		}
		if (img->map[img->player_y][img->player_x + 1] == 'E')
		{
			if (img->collect == img->total_c)
				endgame(img);
		}
		img->player_x = img->player_x + 1;
		img->moves = img->moves + 1;
		printf("%d\n", img->moves);
		img->p_dir = 1;
		print_moves(img);
	}	
}
