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
}
