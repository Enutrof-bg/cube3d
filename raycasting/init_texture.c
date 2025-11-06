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

#include "../includes/cube.h"

void	ft_set_null(t_all *data)
{
	int	i;

	i = 0;
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
	i = 0;
	while (i < 4)
	{
		data->hand_anim[i].img = NULL;
		i++;
	}
}

void	ft_set_img_path(t_all *data)
{
	data->north.dest = data->cub.no;
	if (data->north.dest == NULL)
		data->north.dest = "";
	data->south.dest = data->cub.so;
	if (data->south.dest == NULL)
		data->south.dest = "";
	data->east.dest = data->cub.ea;
	if (data->east.dest == NULL)
		data->east.dest = "";
	data->west.dest = data->cub.we;
	if (data->west.dest == NULL)
		data->west.dest = "";
	data->door_close.dest = "./img/door_close.xpm";
	data->door_open.dest = "./img/door_open.xpm";
}

int	set_img(t_all *data)
{
	ft_set_null(data);
	ft_set_img_path(data);
	ft_set_img_north(data);
	ft_set_img_south(data);
	ft_set_img_east(data);
	ft_set_img_west(data);
	ft_set_img_door_close(data);
	ft_set_img_door_open(data);
	return (0);
}
