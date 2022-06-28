/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:54:16 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/28 17:43:58 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_data *img)
{
	int	img_width;
	int	img_height;
	int	x;
	int	y;

	x = 0;
	img->moves = 0;
	while (x < img->lines - 1)
	{
		if (ft_strchr(img->map[x++], 'P'))
		{
			y = 0;
			while(img->map[x][y])
			{
				if (img->map[x][y++] == 'P')
					break ;
				img->x++;
			}
		}
		img->y++;		
	}
	printf("%d\n", img->x);
	printf("%d\n", img->y);
	// img->img_x = 64;
	// img->img_y = 25;
	//img->x = 1;
	//img->y = 0;
	img->player = mlx_xpm_file_to_image(img->mlx, "assets/perso.xpm",
			&img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->player,
		img->x * 64, img->y * 64);
}
