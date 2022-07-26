/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:29:14 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/26 16:10:48 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	size_t	firstlen;
	int			x;
	size_t		y;

	firstlen = 0;
	x = 0;
	while (img->map[0][x] != '\n')
	{
		firstlen++;
		x++;
	}
	x = 1;
	while (x <= img->lines - 1)
	{
		y = 0;
		printf("\nx :%d\n", x);
		printf("firstlen: %zu\n", firstlen);
		while (img->map[x][y] != '\0')
		{
				y++;
		}
		printf("line len: %zu\n", y);
		if (y != firstlen)
			img->error_code = 6;
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
}

void	check_map_char(t_data *img)
{
	int	x;

	x = 0;
	while (x < img->lines - 1)
	{
		if (isinset(img->map[x], "01CEP") != 1)
			img->error_code = 3;
		x++;
	}
}

void	check_map(t_data *img)
{
	img->lenght = ft_strlen(img->map[0]);
	if (img->map[0][0] == '\0')
		img->error_code = 1;
	else if (img->lenght <= 4 || img->lines <= 3)
		img->error_code = 2;
	check_map_walls(img);
	check_map_char(img);
	check_map_rectangle(img);
}
