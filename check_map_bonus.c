/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:29:14 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/27 11:39:01 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	isinset(char *s1, char *set)
{
	int	x;
	int	len;

	x = 0;
	len = ft_strlen(s1);
	while (x < len - 1)
	{
		if (ft_strchr(set, s1[x]) == NULL)
			return (0);
		x++;
	}
	return (1);
}

void	check_map_rectangle(t_data *img)
{
	size_t		firstlen;
	int			x;
	size_t		y;

	firstlen = 0;
	while (img->map[0][firstlen] != '\n')
		firstlen++;
	x = 1;
	while (x <= img->lines - 1)
	{
		y = 0;
		while (img->map[x][y] != '\0' && img->map[x][y] != '\n')
				y++;
		if (y != firstlen)
		{
			img->error_code = 6;
			errors(img);
		}
		x++;
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
			if (img->map[x][y] == '1')
				y++;
			else
				img->error_code = 4;
		}
		else if (x > 0 && x < img->lines - 1)
		{
			if (img->map[x][0] != '1' || img->map[x][img->lenght - 2] != '1')
				img->error_code = 5;
		}
		x++;
	}
	errors(img);
}

void	check_map_char(t_data *img)
{
	int	x;

	x = 0;
	while (x < img->lines - 1)
	{
		if (isinset(img->map[x], "01CEPZ") != 1)
		{
			img->error_code = 3;
			errors(img);
		}
		x++;
	}
	search_collectibles(img, 'E');
	search_collectibles(img, 'P');
	search_collectibles(img, 'Z');
	search_collectibles(img, 'C');
	errors(img);
}

void	check_map(t_data *img)
{
	img->lenght = ft_strlen(img->map[0]);
	if (img->map[0][0] == '\0')
			img->error_code = 1;
	else if (img->lenght <= 4 || img->lines <= 3)
		img->error_code = 2;
	errors(img);
	check_map_walls(img);
	check_map_char(img);
	check_map_rectangle(img);
}
