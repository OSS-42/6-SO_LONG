/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgame_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:47:12 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/27 11:51:15 by ewurstei         ###   ########.fr       */
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

int	errors(t_data *img)
{
	if (img->error_code == 0)
		return (0);
	else if (img->error_code == 1)
		printf("%s\n%s\n", "Error", "Il n'y a pas de carte");
	else if (img->error_code == 2)
		printf("%s\n%s\n", "Error", "Carte trop petite");
	else if (img->error_code == 3)
		printf("%s\n%s\n", "Error", "Mauvais caractère");
	else if (img->error_code == 4)
		printf("%s\n%s\n", "Error", "Murs non valides (haut/bas)");
	else if (img->error_code == 5)
		printf("%s\n%s\n", "Error", "Murs non valides (gauche/droite)");
	else if (img->error_code == 6)
		printf("%s\n%s\n", "Error", "La carte n'est pas un rectangle parfait");
	else if (img->error_code == 7)
		printf("%s\n%s\n", "Error", "Probleme FD");
	else if (img->error_code == 8)
		printf("%s\n%s\n", "Error", "Mauvais nom de fichier carte");
	else if (img->error_code == 9)
		printf("%s\n%s\n", "Error", "Mauvais nombre d'arguments");
	else if (img->error_code == 10)
		printf("%s\n%s\n", "Error", "Carte incomplète (P, E, C manquant)");
	free_map(img);
	exit (1);
}

int	endgame(t_data *img)
{
	printf("%d\n", img->moves);
	printf("%s\n", "Partie Terminée !");
	mlx_destroy_window(img->mlx, img->mlx_win);
	free_map(img);
	exit (0);
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 53)
		endgame(img);
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
	time_t	t;

	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, ((img->lenght - 1) * 64),
			(img->lines * 64 + 50), "A Day in 42 Quebec");
	img->moves = 0;
	img->collectibles = 0;
	srand((unsigned) time(&t));
	init_level(img);
	init_player(img);
	printf("%d\n", img->nbr_enemy);
	init_enemy(img);
	mlx_hook(img->mlx_win, 17, 0, endgame, img);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_loop(img->mlx);
}
