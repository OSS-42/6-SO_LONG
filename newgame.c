/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:47:12 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/27 16:35:14 by ewurstei         ###   ########.fr       */
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
	char	*wall_path = "/Users/ewurstei/Documents/42-so_long/assets/tile_wall.xpm";
	int	img_width;
	int	img_height;
	int	x;
	int	y;
	int	i;
	int	h;
	int	l;
	
	img->mlx = mlx_init();
	img->lenght = ft_strlen(img->map[0]);
	img->mlx_win = mlx_new_window(img->mlx, img->lenght * 64, (img->lines * 64), "A Day in 42 Quebec");


	img->img = mlx_xpm_file_to_image(img->mlx, wall_path, &img_width, &img_height);
	i = 0;
	x = 0;
	h = 0;
	l = 0;
	while (i < img->lines)
	{
		y = 0;
		while (img->map[x][y++] != '\n')
		{
			if (img->map[x][y] == '1')
			{
				printf("Ok\n");
				mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, h, l);
			l = l + 64;
			}
		}
		i++;
	}
	
	mlx_string_put(img->mlx, img->mlx_win, 0, 0, 0x00FF0000, "Moves :");
	mlx_string_put(img->mlx, img->mlx_win, 500, 0, 0x6922ff, "Collectibles :");
	mlx_string_put(img->mlx, img->mlx_win, 1000, 0, 0x05878a, "Life :");
		
	mlx_hook(img->mlx_win, 17, 0, endgame, img);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_loop(img->mlx);
}
