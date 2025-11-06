/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:16:29 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:16:30 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	rotate_left(t_all *data)
{
	double	temp;

	temp = data->dir_player_x;
	data->dir_player_x = data->dir_player_x * cos(-ROTATE)
		- data->dir_player_y * sin(-ROTATE);
	data->dir_player_y = temp * sin(-ROTATE)
		+ data->dir_player_y * cos(-ROTATE);
	temp = data->plane_dir_x;
	data->plane_dir_x = data->plane_dir_x * cos(-ROTATE)
		- data->plane_dir_y * sin(-ROTATE);
	data->plane_dir_y = temp * sin(-ROTATE) + data->plane_dir_y * cos(-ROTATE);
	return (0);
}

int	rotate_right(t_all *data)
{
	double	temp;

	temp = data->dir_player_x;
	data->dir_player_x = data->dir_player_x * cos(ROTATE)
		- data->dir_player_y * sin(ROTATE);
	data->dir_player_y = temp * sin(ROTATE) + data->dir_player_y * cos(ROTATE);
	temp = data->plane_dir_x;
	data->plane_dir_x = data->plane_dir_x * cos(ROTATE)
		- data->plane_dir_y * sin(ROTATE);
	data->plane_dir_y = temp * sin(ROTATE) + data->plane_dir_y * cos(ROTATE);
	return (0);
}
