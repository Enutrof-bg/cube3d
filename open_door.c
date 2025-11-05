/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:42:12 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:42:13 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static inline void	ft_check_is_door_close(t_all *data)
{
	if (data->wall == 0)
	{
		if (data->ray_dir_x == 0)
			data->wall_distance = 1e30;
		else
			data->wall_distance = (data->player_pos_int_x
					- data->pos_player_x
					+ (1 - data->steps_x) / 2) / data->ray_dir_x;
	}
	else
	{
		if (data->ray_dir_y == 0)
			data->wall_distance = 1e30;
		else
			data->wall_distance = (data->player_pos_int_y
					- data->pos_player_y
					+ (1 - data->steps_y) / 2) / data->ray_dir_y;
	}
	if (data->wall_distance < RANGE_DOOR)
		data->map[data->player_pos_int_y][data->player_pos_int_x] = 'O';
}

static inline void	ft_check_is_door_open(t_all *data)
{
	if (data->wall == 0)
	{
		if (data->ray_dir_x == 0)
			data->wall_distance = 1e30;
		else
			data->wall_distance = (data->player_pos_int_x
					- data->pos_player_x
					+ (1 - data->steps_x) / 2) / data->ray_dir_x;
	}
	else
	{
		if (data->ray_dir_y == 0)
			data->wall_distance = 1e30;
		else
			data->wall_distance = (data->player_pos_int_y
					- data->pos_player_y
					+ (1 - data->steps_y) / 2) / data->ray_dir_y;
	}
	if (data->wall_distance < RANGE_DOOR)
		data->map[data->player_pos_int_y][data->player_pos_int_x] = 'D';
}

void	ft_check_range_door(t_all *data)
{
	if (data->map[data->player_pos_int_y][data->player_pos_int_x] == 'D')
	{
		ft_check_is_door_close(data);
	}
	else if (data->map[data->player_pos_int_y][data->player_pos_int_x] == 'O')
	{
		ft_check_is_door_open(data);
	}
}

int	open_close_door(t_all *data)
{
	ft_calculate_ray(data, W / 2);
	ft_calculate_distance(data);
	ft_algo_dda(data);
	ft_check_range_door(data);
	return (0);
}
