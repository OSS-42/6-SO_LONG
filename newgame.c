/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:47:12 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/28 11:21:39 by ewurstei         ###   ########.fr       */
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
	t_images	level_1;
	int	img_width;
	int	img_height;
	int	x;
	int	y;
	int	img_x;
	int	img_y;
	char	*wall_left = "/Users/ewurstei/Documents/42-so_long/assets/tile_wall_window_left.xpm";
	char	*wall_right = "/Users/ewurstei/Documents/42-so_long/assets/tile_wall_window_right.xpm";
	char	*wall_top =  "/Users/ewurstei/Documents/42-so_long/assets/tile_wall_window_top.xpm";
	char	*corner_1 = "/Users/ewurstei/Documents/42-so_long/assets/tile_wall_corner_1.xpm";
	char	*corner_2 = "/Users/ewurstei/Documents/42-so_long/assets/tile_wall_corner_2.xpm";
	// char	*corner_3;
	// char	*corner_4;
	
	printf("%s", "OK #2");
	img->mlx = mlx_init();
	img->lenght = ft_strlen(img->map[0]);
	//printf("lenght : %d\n", img->lenght);
	//printf("string: %s", img->map[0]);
	img->mlx_win = mlx_new_window(img->mlx, (img->lenght * 64), (img->lines * 64) + 25, "A Day in 42 Quebec");

	level_1.wall_right = mlx_xpm_file_to_image(img->mlx, wall_right, &img_width, &img_height);
	level_1.wall_left = mlx_xpm_file_to_image(img->mlx, wall_left, &img_width, &img_height);
	level_1.wall_top = mlx_xpm_file_to_image(img->mlx, wall_top, &img_width, &img_height);
	level_1.corner_1 = mlx_xpm_file_to_image(img->mlx, corner_1, &img_width, &img_height);
	level_1.corner_2 = mlx_xpm_file_to_image(img->mlx, corner_2, &img_width, &img_height);
	x = 0;
	img_x = 0;
	img_y = 25;
	printf("%s", "OK #3");
	while (x < img->lines)
	{
		y = 0;
		if (x == 0 && y == 0 && img->map[x][y] == '1')
		{
			mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.corner_1, img_x, img_y);
			img_x = img_x + 64;
			y++;
		}
		while (y++ < (img->lenght - 2))
		{
			if (img->map[x][y] == '1')
			{
				mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.wall_top, img_x, img_y);
				img_x = img_x + 64;
			}
		}
		y++;
		// printf("y: %d\n", y);
		// printf("char: %c\n", img->map[x][y]);
		if (x == 0 && img->map[x][y] == '1')
		{
			// printf("%d\n", img->lenght);
			// printf("%d", y);
			mlx_put_image_to_window(img->mlx, img->mlx_win, level_1.corner_2, img_x, img_y);
		}
		img_x = 0;
		img_y = img_y + 64;
		x++;
	}
	
	mlx_string_put(img->mlx, img->mlx_win, 0, 0, 0x00FF0000, "Moves :");
	mlx_string_put(img->mlx, img->mlx_win, 500, 0, 0x6922ff, "Collectibles :");
	mlx_string_put(img->mlx, img->mlx_win, 1000, 0, 0x05878a, "Life :");
		
	mlx_hook(img->mlx_win, 17, 0, endgame, img);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_loop(img->mlx);
}
