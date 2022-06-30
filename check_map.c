/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:29:14 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/30 10:29:14 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	isinset(char *s1, char *set)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	len = ft_strlen(set);
	while (x < len)
	{
		if (ft_strchr(s1, set[x] == NULL))
			return (0);
		x++;
	}
	return (1);
}

void	check_map_rectangle(t_data *img)
{
	int	firstlen;
	int	x;

	x = 0;
	firstlen = ft_strlen(img->map[x]);
	while (++x < img->lines - 1)
	{
		if (ft_strlen(img->map[x] != firstlen))
		{
			printf("%s\n", "Error");
			printf("%s\n", "la carte n'est pas un rectangle parfait");
			exit (1);
		}
	}
}

void	check_map_walls(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < img->lines - 1)
	{
		if (x == 0 || x == img->lines - 1)
		{
			y = 0;
			while (img->map[x][y])
			{
				if (img->map[x][y] != '1')
				{
					printf("%s\n%s\n", "Error", "Mur non valide (haut ou bas)");
					exit (0);
				}
				y++;
			}
		}
		else if (x > 0 && x < img->lines - 2)
		{
			if (img->map[x][0] != '1' || img->map[x][img->lenght - 2] != '1')
			{
				printf("%s\n%s\n", "Error", "Mur non valide (gauche ou droite)");
				exit (1);
			}
		}
	}
	x++;
}

void	check_map_char(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < img->lines - 1)
	{
		y = 0;
		while (img->map[x][y])
		{
			if (isinset(img->map[x], "01CEP") != 1)
			{
				printf("%s\n", "Error");
				printf("Caractère manquant ou mauvais caractère");
				exit (1);
			}
		}
	}
}

void	check_map(t_data *img)
{
	if (img->map[0][0] == '\0')
	{
		printf("%s\n", "Error");
		printf("%s\n", "Il n'y a pas de carte");
		exit (1);
	}
	if (img->lenght < 5 || img->lines < 3)
	{
		printf("%s\n", "Error");
		printf("%s", "Carte trop petite : elle ne peut pas contenir 01CEP");
		exit (1);
	}
	check_map_walls(img);
	check_map_char(img);
	check_map_rectangle(img);
}
