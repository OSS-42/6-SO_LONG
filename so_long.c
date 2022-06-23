/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:11:33 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/23 16:19:23 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_lenght;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
	int		x;
	int		y;
	int		z;
	int		pos;

	img = (t_data *)malloc(sizeof(t_data));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "A Day in 42 Quebec");
	img->img = mlx_new_image(mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_lenght,
			&img->endian);
	x = 100;
	z = 50;
	pos = 0;
	while (z++ <= 150)
	{
		y = 100 + pos;
		while (y++ <= 140 + pos)
		{
			my_mlx_pixel_put(img, x, y, 0x00FF0000);
		}
		x++;
		pos = pos - 1;
	}
	x = 100;
	while (x <= 200)
	{
		y = 100;
		while (y++ <= 140)
		{
			my_mlx_pixel_put(img, x, y, 0x6922ff);
		}
		x++;
	}
	y = 100;
	while (y <= 180)
	{
		x = 160;
		while (x++ <= 200)
		{
			my_mlx_pixel_put(img, x, y, 0x05878a);
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
}
