/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:41:43 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:41:43 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_data(t_all *data)
{
	printf("\n\n\n");
	printf("pos_player_x:%f\n", data->pos_player_x);
	printf("pos_player_y:%f\n", data->pos_player_y);
	printf("pos_player_x(int):%d\n", (int)data->pos_player_x);
	printf("pos_player_y(int):%d\n", (int)data->pos_player_y);
	printf("dir_player_x:%f\n", data->dir_player_x);
	printf("dir_player_y:%f\n", data->dir_player_y);
	printf("plane_dir_x:%f\n", data->plane_dir_x);
	printf("plane_dir_y:%f\n", data->plane_dir_y);
	printf("map_x length:%d\n", (int)data->map_length);
	printf("map_y height:%d\n", (int)data->map_heigth);
	printf("angle_player:%d\n", data->angle_player);
}
