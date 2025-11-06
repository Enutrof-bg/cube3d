/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:16:25 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:16:25 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	move_forward(t_all *data)
{
	data->temp_x = data->pos_player_x + data->dir_player_x * MS;
	data->temp_y = data->pos_player_y + data->dir_player_y * MS;
	if (check_collision(data, data->temp_x, data->pos_player_y) == 0)
	{
		ft_move_player_x(data);
	}
	if (check_collision(data, data->pos_player_x, data->temp_y) == 0)
	{
		ft_move_player_y(data);
	}
	return (0);
}

int	move_backward(t_all *data)
{
	data->temp_x = data->pos_player_x - data->dir_player_x * MS;
	data->temp_y = data->pos_player_y - data->dir_player_y * MS;
	if (check_collision(data, data->temp_x, data->pos_player_y) == 0)
	{
		ft_move_player_x(data);
	}
	if (check_collision(data, data->pos_player_x, data->temp_y) == 0)
	{
		ft_move_player_y(data);
	}
	return (0);
}

int	move_left(t_all *data)
{
	data->temp_x = data->pos_player_x - data->plane_dir_x * MS;
	data->temp_y = data->pos_player_y - data->plane_dir_y * MS;
	if (check_collision(data, data->temp_x, data->pos_player_y) == 0)
	{
		ft_move_player_x(data);
	}
	if (check_collision(data, data->pos_player_x, data->temp_y) == 0)
	{
		ft_move_player_y(data);
	}
	return (0);
}

int	move_right(t_all *data)
{
	data->temp_x = data->pos_player_x + data->plane_dir_x * MS;
	data->temp_y = data->pos_player_y + data->plane_dir_y * MS;
	if (check_collision(data, data->temp_x, data->pos_player_y) == 0)
	{
		ft_move_player_x(data);
	}
	if (check_collision(data, data->pos_player_x, data->temp_y) == 0)
	{
		ft_move_player_y(data);
	}
	return (0);
}
