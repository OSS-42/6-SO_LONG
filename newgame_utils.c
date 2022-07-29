/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgame_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:47:12 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/29 11:21:50 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	quit_game(t_data *img)
{
	printf("%s\n", "Au revoir !");
	mlx_destroy_window(img->mlx, img->mlx_win);
	free_map(img);
	exit (0);
}

int	endgame(t_data *img)
{
	img->moves = img->moves + 1;
	printf("%d\n", img->moves);
	printf("%s\n", "Partie Terminée !");
	mlx_destroy_window(img->mlx, img->mlx_win);
	free_map(img);
	exit (0);
}
