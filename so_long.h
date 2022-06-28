/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:25:23 by ewurstei          #+#    #+#             */
/*   Updated: 2022/06/28 10:13:29 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "includes/mlx/mlx.h"
# include "includes/libft/libft.h"
# include <stdio.h>

typedef struct s_images
{
	char	*corner_1;
	char	*corner_2;
	char	*corner_3;
	char	*corner_4;
	char	*wall_left;
	char	*wall_right;
	char	*wall_top;
}	t_images;

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		width;
	int		height;
	int		lines;
	int		lenght;
}	t_data;

void	ft_pixels(t_data *img);
int		endgame(t_data *img);
void	newgame(t_data *img);

#endif
