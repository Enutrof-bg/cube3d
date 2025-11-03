/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:14:40 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 16:14:41 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void ft_count(t_all *data)
{
	int i = 0;
	int len = 0;
	int temp;
	while (data->map[i])
	{
		temp = ft_strlen(data->map[i]);
		if (temp > len)
			len = temp;

		i++;
	}
	data->map_length = len;
	data->map_heigth = i;
}

void	ft_init_value(t_all *data)
{
	data->start_time = get_time_ms();
	data->check_door = 0;
	data->temp_x = 0;
	data->temp_y = 0;
	data->move_x = 0;
	data->move_y = 0;
	data->rotate = 0;
	data->shoot = 0;
	data->mlx = NULL;
	data->mlx_win_2 = NULL;
	data->img.img = NULL;
	data->r1.texture_y = 0;
	data->map = data->cub.map;
	data->ceiling = (data->cub.C[0] << 16) + (data->cub.C[1] << 8) + (data->cub.C[2]);
	data->floor = (data->cub.F[0] << 16) + (data->cub.F[1] << 8) + (data->cub.F[2]);
	printf("%d %d\n", data->ceiling, data->floor);
	ft_count(data);
}
