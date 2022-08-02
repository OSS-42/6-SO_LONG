/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:47:12 by ewurstei          #+#    #+#             */
/*   Updated: 2022/08/02 11:21:43 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	endgame(t_data *img)
{
	img->moves = img->moves + 1;
	printf("%d\n", img->moves);
	printf("%s\n", "Partie Terminée !");
	free_all(img);
	exit (0);
}

int	quit_game(t_data *img)
{
	printf("%s\n", "Au revoir !");
	free_all(img);
	exit (0);
}


