/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:47:12 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/29 14:12:39 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(int error_code)
{
	if (error_code == 1)
		printf("%s\n%s\n", "Error", "Il n'y a pas de carte");
	if (error_code == 2)
		printf("%s\n%s\n", "Error", "Carte trop petite");
	if (error_code == 3)
		printf("%s\n%s\n", "Error", "Caractère manquant ou mauvais caractère");
	if (error_code == 4)
		printf("%s\n%s\n", "Error", "Murs non valides (haut/bas)");
	if (error_code == 5)
		printf("%s\n%s\n", "Error", "Murs non valides (gauche/droite)");
	if (error_code == 6)
		printf("%s\n%s\n", "Error", "La carte n'est pas un rectangle parfait");
	exit(1);
}

int	endgame(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit (0);
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit (0);
	}
	if (keycode == 13)
		go_up(img);
	if (keycode == 0)
		go_left(img);
	if (keycode == 1)
		go_down(img);
	if (keycode == 2)
		go_right(img);
	return (0);
}

void	newgame(t_data *img)
{
	img->mlx = mlx_init();
	img->lenght = ft_strlen(img->map[0]);
	img->mlx_win = mlx_new_window(img->mlx, ((img->lenght - 1) * 64),
			(img->lines * 64 + 50), "A Day in 42 Quebec");
	search_collectibles(img);
	init_level(img);
	init_player(img);
	if (img->enemy == 1)
		init_enemy(img);
	mlx_hook(img->mlx_win, 17, 0, endgame, img);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_loop(img->mlx);
}
