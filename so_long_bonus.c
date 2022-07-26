/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:11:33 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/26 13:16:27 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <fcntl.h>

static void	check_fd(t_data *img, int fd)
{
	char	*line;
	
	if (fd < 0)
		errors(img , 7);
	img->lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		img->lines++;
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
}

void	check_map_name(t_data *img)
{
	char	*filename;

	filename = ft_strrchr(img->argv, '.');
	if (ft_strncmp(filename, ".ber", ft_strlen(filename)) != 0)
		errors(img, 8);
}

void	map_to_array(t_data *img)
{
	int		x;
	int		fd;

	fd = open(img->argv, O_RDONLY);
	check_fd(img,fd);
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
	close (fd);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc != 2)
		errors(&img, 9);
	img.argv = argv[1];
	check_map_name(&img);
	map_to_array(&img);
	check_map(&img);
	newgame(&img);
	free (img.map);
	return (0);
}
