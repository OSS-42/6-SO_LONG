/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_destroy_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:00:49 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/02 10:17:14 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_and_free_level(t_data *img)
{
	mlx_destroy_image(img->mlx, img->lvl1->collect);
	mlx_destroy_image(img->mlx, img->lvl1->corner_1);
	mlx_destroy_image(img->mlx, img->lvl1->corner_2);
	mlx_destroy_image(img->mlx, img->lvl1->corner_3);
	mlx_destroy_image(img->mlx, img->lvl1->corner_4);
	mlx_destroy_image(img->mlx, img->lvl1->exit);
	mlx_destroy_image(img->mlx, img->lvl1->floor);
	mlx_destroy_image(img->mlx, img->lvl1->pilar);
	mlx_destroy_image(img->mlx, img->lvl1->start);
	mlx_destroy_image(img->mlx, img->lvl1->wall_bottom);
	mlx_destroy_image(img->mlx, img->lvl1->wall_left);
	mlx_destroy_image(img->mlx, img->lvl1->wall_right);
	mlx_destroy_image(img->mlx, img->lvl1->wall_top);
	free (img->lvl1);
}

static void	destroy_and_free_player(t_data *img)
{
	mlx_destroy_image(img->mlx, img->player->p_right);
	mlx_destroy_image(img->mlx, img->player->p_left);
	free (img->player);
}

void	free_map(t_data *img)
{
	int	x;
	
	if (img->error_code == 7 || img->error_code == 8 || img->error_code == 9)
		exit (0);
	x = 0;
	while (x < img->lines)
	{
		free (img->map[x]);
		x++;
	}
	exit (0);
}

static void	destroy_and_free_enemy(t_data *img)
{
	int	x;

	x = 0;
	while (x < 2)
	{
		mlx_destroy_image(img->mlx, img->frames->enemy_pic[x]);
		x++;
	}
	free (img->frames);
}

void	free_all(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	free_map(img);
	destroy_and_free_level(img);
	destroy_and_free_player(img);
	destroy_and_free_enemy(img);
}