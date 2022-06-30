/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:33:55 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/29 14:57:44 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_go_up(t_data *img)
{
	int	img_width;
	int	img_height;

	if (img->map[img->enemy_y - 1][img->enemy_x] != '1')
	{
		if (img->enemy == 1 && img->map[img->enemy_y - 1][img->enemy_x]
			== img->map[img->player_y][img->player_x])
		{
			printf("%s\n", "TIG ! vous avez perdu !");
			exit (0);
		}
		mlx_clear_window(img->mlx, img->mlx_win);
		init_level(img);
		img->enemy_y = img->enemy_y - 1;
		img->player = mlx_xpm_file_to_image(img->mlx, "assets/patrouille_2.xpm",
				&img_width, &img_height);
	}	
}

void	enemy_go_down(t_data *img)
{
	int	img_width;
	int	img_height;

	if (img->map[img->enemy_y + 1][img->enemy_x] != '1')
	{
		if (img->enemy == 1 && img->map[img->enemy_y + 1][img->enemy_x]
			== img->map[img->player_y][img->player_x])
		{
			printf("%s\n", "TIG ! vous avez perdu !");
			exit (0);
		}
		mlx_clear_window(img->mlx, img->mlx_win);
		init_level(img);
		img->player_y = img->player_y + 1;
		img->player = mlx_xpm_file_to_image(img->mlx, "assets/patrouille_1.xpm",
				&img_width, &img_height);
	}	
}

void	enemy_go_left(t_data *img)
{
	int	img_width;
	int	img_height;

	if (img->map[img->enemy_y][img->enemy_x - 1] != '1')
	{
		if (img->enemy == 1 && img->map[img->enemy_y][img->enemy_x - 1]
			== img->map[img->player_y][img->player_x])
		{
			printf("%s\n", "TIG ! vous avez perdu !");
			exit (0);
		}
		mlx_clear_window(img->mlx, img->mlx_win);
		init_level(img);
		img->player_x = img->player_x - 1;
		img->player = mlx_xpm_file_to_image(img->mlx, "assets/patrouille_1.xpm",
				&img_width, &img_height);
	}	
}

void	enemy_go_right(t_data *img)
{
	int	img_width;
	int	img_height;

	if (img->map[img->enemy_y][img->enemy_x + 1] != '1')
	{
		if (img->enemy == 1 && img->map[img->enemy_y][img->enemy_x + 1]
			== img->map[img->player_y][img->player_x])
		{
			printf("%s\n", "TIG ! vous avez perdu !");
			exit (0);
		}
		mlx_clear_window(img->mlx, img->mlx_win);
		init_level(img);
		img->player_x = img->player_x + 1;
		img->player = mlx_xpm_file_to_image(img->mlx, "assets/patrouille_2.xpm",
				&img_width, &img_height);
	}	
}
