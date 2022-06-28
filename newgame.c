/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:47:12 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/28 14:32:36 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	endgame(t_data *img)
{
	printf("bye bye !");
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit (0);
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		printf("Aufwiedersehen !");
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit (0);
	}
	return (0);
}

void	newgame(t_data *img)
{
	img->mlx = mlx_init();
	img->lenght = ft_strlen(img->map[0]);
	img->mlx_win = mlx_new_window(img->mlx, ((img->lenght - 1)  * 64), (img->lines * 64) + 25, "A Day in 42 Quebec");

	init_level(img);
	
	mlx_string_put(img->mlx, img->mlx_win, 0, 0, 0x00FF0000, "Moves :");
	mlx_string_put(img->mlx, img->mlx_win, 500, 0, 0x6922ff, "Collectibles :");
	mlx_string_put(img->mlx, img->mlx_win, 1000, 0, 0x05878a, "Life :");
		
	mlx_hook(img->mlx_win, 17, 0, endgame, img);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_loop(img->mlx);
}
