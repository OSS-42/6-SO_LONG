/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 09:00:49 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/01 09:00:49 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_level(t_data *img)
{
	free (img->lvl1->wall_right);
	free (img->lvl1->wall_left);
	free (img->lvl1->wall_top);
	free (img->lvl1->wall_bottom);
	free (img->lvl1->corner_1;
	free (img->lvl1->corner_2);
	free (img->lvl1->corner_3);
	free (img->lvl1->corner_4);
	free (img->lvl1->floor);
	free (img->lvl1->pilar);
	free (img->lvl1->collect);
	free (img->lvl1->start);
	free (img->lvl1->exit);
}

static void	free_player(t_data *img)
{
	free (img->player->p_right);
	free (img->player->p_left);
}

static void	free_map(t_data *img)
{
	int	x;

	x = 0;
	while (x < img->lines)
	{
		free (img->map[x]);
		x++;
	}
}

static void	free_enemy(t_data *img)
{
	int	x;

	x = 0;
	while (x < 2)
	{
		free (img->frames->enemy_pic[x]);
		x++;
	}
}

void	free_all(t_data *img)
{
	free_level(img);
	free_player(img);
	free_map(img);
	free_enemy(img);
}