/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:15:21 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:15:21 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_set_dir_2(t_all *data, char dir)
{
	if (dir == 'N')
	{
		data->dir_player_x = 0;
		data->dir_player_y = -1;
		data->plane_dir_x = 0.66;
		data->plane_dir_y = 0;
		return (0);
	}
	else if (dir == 'S')
	{
		data->dir_player_x = 0;
		data->dir_player_y = 1;
		data->plane_dir_x = -0.66;
		data->plane_dir_y = 0;
		return (0);
	}
	return (1);
}

int	set_dir_player(t_all *data, char dir)
{
	if (ft_set_dir_2(data, dir) == 0)
		return (0);
	else if (dir == 'W')
	{
		data->dir_player_x = -1;
		data->dir_player_y = 0;
		data->plane_dir_x = 0;
		data->plane_dir_y = -0.66;
	}
	else if (dir == 'E')
	{
		data->dir_player_x = 1;
		data->dir_player_y = 0;
		data->plane_dir_x = 0;
		data->plane_dir_y = 0.66;
	}
	return (1);
}

int	set_pos_player(t_all *data)
{
	int	i;
	int	j;

	i = 0;
	data->pos_player_x = -1;
	data->pos_player_y = -1;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->pos_player_x = j;
				data->pos_player_y = i;
				set_dir_player(data, data->map[i][j]);
				data->map[i][j] = 'P';
				return (0);
			}
			j++;
		}
		i++;
	}
	return (-1);
}
