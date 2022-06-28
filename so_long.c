/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:11:33 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/28 17:24:20 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

	//valider carte

int	main(int argc, char **argv)
{
	t_data	img;
	int	fd;
	int	x;
	
	img.lines = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("%s", "Erreur FD");
		exit (1);
	}
	while (get_next_line(fd))
		img.lines++;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	img.map = (char **)malloc(sizeof(char *) * img.lines + 1);
	x = 0;
	if (argc == 2)
	{
		while (1)
		{
			img.map[x] = get_next_line(fd);
			if (img.map[x] == NULL)
			{
				free(img.map[x]);
				break;
			}
			x++;
		}
	}
	newgame(&img);
	free (img.map);
	close (fd);
	return (0);
}
