/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:26:49 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:26:51 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_collision(t_all *data, double x, double y)
{
	int	int_x;
	int	int_y;

	int_x = (int)x;
	int_y = (int)y;
	if (x >= 0 && x < data->map_length && y >= 0 && y < data->map_heigth
		&& data->map[int_y] && data->map[int_y][int_x] != '1'
		&& data->map[int_y][int_x] != 'D')
		return (0);
	return (1);
}

void	ft_move_player_x(t_all *data)
{
	if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == 'P')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
	else if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == 'Q')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'O';
	data->pos_player_x = data->temp_x;
	if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == '0')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
	else if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == 'O')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'Q';
}

void	ft_move_player_y(t_all *data)
{
	if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == 'P')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
	else if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == 'Q')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'O';
	data->pos_player_y = data->temp_y;
	if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == '0')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
	else if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == 'O')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'Q';
}
