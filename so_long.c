/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:11:33 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/28 11:19:13 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>


int	main(int argc, char **argv)
{
	t_data	img;
	int	fd;
	int	x;
	
	//valider carte
	img.lines = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd))
		img.lines++;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	img.map = (char **)malloc(sizeof(char *) * img.lines);
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
	printf("%s", "OK #1");

	newgame(&img);
	free (img.map);
	close (fd);
	return (0);
}
