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
			errors(6);
	}
}

void	check_map_walls(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	while (x++ < img->lines - 1)
	{
		if (x == 0 || x == img->lines - 1)
		{
			y = 0;
			while (img->map[x][y])
			{
				if (img->map[x][y] == '1')
					y++;
				else
					errors(4);
			}
		}
		else if (x > 0 && x < img->lines - 2)
		{
			if (img->map[x][0] == '1' || img->map[x][img->lenght - 2] == '1')
				errors(5);
		}
	}
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
			if (isinset(img->map[x], "01CEPZ") != 1)
				errors(3);
			if (ft_strchr(img->map[x], 'Z' != NULL))
				img->enemy = 1;
		}
	}
}

void	check_map(t_data *img)
{
	if (img->map[0][0] == '\0')
		errors(1);
	if (img->lenght < 5 || img->lines < 3)
		errors(2);
	check_map_walls(img);
	check_map_char(img);
	check_map_rectangle(img);
}
