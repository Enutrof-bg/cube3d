/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:24:33 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:24:34 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_set_null(t_all *data)
{
	int i;

	i = 0;
	data->t_sol.img = NULL;
	data->t_wall.img = NULL;
	data->t_player.img = NULL;
	data->north.img = NULL;
	data->south.img = NULL;
	data->east.img = NULL;
	data->west.img = NULL;
	data->door_open.img = NULL;
	data->door_close.img = NULL;
	while (i < 15)
	{
		data->anim[i].img = NULL;
		i++;
	}
}

void	ft_set_img_path(t_all *data)
{
	data->t_sol.dest = "./img/sol2.xpm";
	data->t_wall.dest = "./img/wall2.xpm";
	data->t_player.dest = "./img/player2.xpm";
	// data->north.dest = "./img/n1.xpm";
	// data->south.dest = "./img/s1.xpm";
	// data->east.dest = "./img/e1.xpm";
	// data->west.dest = "./img/w1.xpm";
	data->north.dest = data->cub.NO;
	data->south.dest = data->cub.SO;
	data->east.dest = data->cub.EA;
	data->west.dest = data->cub.WE;
	data->door_close.dest = "./img/door_close.xpm";
	data->door_open.dest = "./img/door_open2.xpm";
}

int	set_img(t_all *data)
{
	ft_set_null(data);
	ft_set_img_path(data);
	// ft_set_img_sol(data);
	// ft_set_img_wall(data);
	// ft_set_img_player(data);
	ft_set_img_north(data);
	ft_set_img_south(data);
	ft_set_img_east(data);
	ft_set_img_west(data);
	ft_set_img_door_close(data);
	ft_set_img_door_open(data);
	return (0);
}
