/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgame_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:47:12 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/29 11:56:20 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_data *img)
{
	int	x;

	x = 0;
	while (x < img->lines)
	{
		free (img->map[x]);
		x++;
	}
}

void	free_enemy(t_data *img)
{
	int	x;

	x = 0;
	while (x < 2)
	{
		free (img->frames->enemy_pic[x]);
		x++;
	}
}

int	endgame(t_data *img)
{
	img->moves = img->moves + 1;
	printf("%d\n", img->moves);
	printf("%s\n", "Partie Terminée !");
	mlx_destroy_window(img->mlx, img->mlx_win);
	free_map(img);
	free_enemy(img);
	exit (0);
}

int	quit_game(t_data *img)
{
	printf("%s\n", "Au revoir !");
	mlx_destroy_window(img->mlx, img->mlx_win);
	free_map(img);
	free_enemy(img);
	exit (0);
}

void	endgame_bad(t_data *img)
{
	img->moves = img->moves + 1;
	printf("%d\n", img->moves);
	printf("%s\n", "TIG ! vous avez perdu !");
	mlx_destroy_window(img->mlx, img->mlx_win);
	free_map(img);
	free_enemy(img);
	exit (0);
}
