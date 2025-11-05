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

void	ft_count(t_all *data)
{
	int	i;
	int	len;
	int	temp;

	i = 0;
	len = 0;
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
	data->frame_time = get_time_ms();
	data->hand_time = get_time_ms();
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
	data->ceiling = (data->cub.c[0] << 16) + (data->cub.c[1] << 8)
		+ (data->cub.c[2]);
	data->floor = (data->cub.f[0] << 16) + (data->cub.f[1] << 8)
		+ (data->cub.f[2]);
	ft_count(data);
}
