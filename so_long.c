/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:11:33 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/07 22:10:20 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

static void	check_fd(int fd)
{
	if (fd < 0)
	{
		printf("%s\n%s\n", "Error", "Probleme FD");
		exit (1);
	}
}

void	check_map_name(t_data *img)
{
	char	*filename;

	filename = ft_strrchr(img->argv, '.');
	while (filename)
	{
		if (ft_strncmp(filename, ".ber", ft_strlen(filename) != 0))
		{
			printf("%s\n%s\n", "Error", "Mauvais nom de fichier carte");
			exit (1);
		}
	}
}

void	map_to_array(t_data *img)
{
	int	x;
	int	fd;

	img->lines = 0;
	fd = open(img->argv, O_RDONLY);
	check_fd(fd);
	while (get_next_line(fd))
			img->lines++;
	close(fd);
	fd = open(img->argv, O_RDONLY);
	img->map = (char **)malloc(sizeof(char *) * img->lines + 1);
	x = 0;
	while (1)
	{
		img->map[x] = get_next_line(fd);
		if (img->map[x] == NULL)
		{
			free(img->map[x]);
			break ;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc != 2)
	{
		printf("%s\n%s\n", "Error", "Mauvais nombre d'arguments");
		exit (1);
	}
	img.argv = argv[1];
	check_map_name(&img);
	map_to_array(&img);
	check_map(&img);
	newgame(&img);
	free (img.map);
	return (0);
}
