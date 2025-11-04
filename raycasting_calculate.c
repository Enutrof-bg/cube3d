/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calculate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:33:46 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:33:46 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_calculate_ray(t_all *data, int pos)
{
	data->wall = 0;
	data->contact = 0;
	data->is_door = 0;
	data->camera_x = 2 * pos / (double)W - 1;
	data->ray_dir_x = data->dir_player_x + data->plane_dir_x * data->camera_x;
	data->ray_dir_y = data->dir_player_y + data->plane_dir_y * data->camera_x;
	data->player_pos_int_x = (int)data->pos_player_x;
	data->player_pos_int_y = (int)data->pos_player_y;
	if (data->ray_dir_x == 0)
		data->line_length_x = 1e30;
	else
		data->line_length_x = fabs(1 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->line_length_y = 1e30;
	else
		data->line_length_y = fabs(1 / data->ray_dir_y);
}

void	ft_calculate_distance(t_all *data)
{
	if (data->ray_dir_x < 0)
	{
		data->steps_x = -1;
		data->distance_x = (data->pos_player_x - data->player_pos_int_x)
			* data->line_length_x;
	}
	else
	{
		data->steps_x = 1;
		data->distance_x = (data->player_pos_int_x + 1.0 - data->pos_player_x)
			* data->line_length_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->steps_y = -1;
		data->distance_y = (data->pos_player_y - data->player_pos_int_y)
			* data->line_length_y;
	}
	else
	{
		data->steps_y = 1;
		data->distance_y = (data->player_pos_int_y + 1.0 - data->pos_player_y)
			* data->line_length_y;
	}
}

void	ft_algo_dda_collision(t_all *data)
{
	if (data->map[data->player_pos_int_y][data->player_pos_int_x] == '1')
		data->contact = 1;
	if (data->map[data->player_pos_int_y][data->player_pos_int_x] == 'O')
		data->is_door = 2;
	if (data->map[data->player_pos_int_y][data->player_pos_int_x] == 'D')
		data->is_door = 1;
}

void	ft_algo_dda(t_all *data)
{
	data->contact = 0;
	data->is_door = 0;
	while (data->contact == 0 && data->is_door == 0)
	{
		if (data->distance_x < data->distance_y)
		{
			data->distance_x = data->distance_x + data->line_length_x;
			data->player_pos_int_x += data->steps_x;
			data->wall = 0;
		}
		else
		{
			data->distance_y = data->distance_y + data->line_length_y;
			data->player_pos_int_y += data->steps_y;
			data->wall = 1;
		}
		if (data->player_pos_int_x < 0 || data->player_pos_int_y < 0
			|| data->player_pos_int_x >= data->map_length
			|| data->player_pos_int_y >= data->map_heigth)
			break ;
		ft_algo_dda_collision(data);
	}
}

void	ft_calculate_distance_wall(t_all *data, t_ratio *r1)
{
	if (data->wall == 0)
	{
		if (data->ray_dir_x == 0)
			data->wall_distance = 1e30;
		else
			data->wall_distance = (data->player_pos_int_x - data->pos_player_x
					+ (1 - data->steps_x) / 2) / data->ray_dir_x;
	}
	else
	{
		if (data->ray_dir_y == 0)
			data->wall_distance = 1e30;
		else
			data->wall_distance = (data->player_pos_int_y - data->pos_player_y
					+ (1 - data->steps_y) / 2) / data->ray_dir_y;
	}
	if (data->wall_distance < 0.01)
		data->wall_distance = 0.01;
	r1->dist = (int)H / data->wall_distance;
	r1->start = (H / 2) - (r1->dist / 2);
	if (r1->start < 0)
		r1->start = 0;
	r1->end = (H / 2) + (r1->dist / 2);
	if (r1->end >= H)
		r1->end = H - 1;
}
