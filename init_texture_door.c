/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_door.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:08:16 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 16:08:17 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_set_img_door_close(t_all *data)
{
	data->door_close.img = mlx_xpm_file_to_image(data->mlx,
			data->door_close.dest, &data->door_close.img_width,
			&data->door_close.img_heigth);
	if (!data->door_close.img)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->door_close.s_screen.addr = mlx_get_data_addr(data->door_close.img,
			&data->door_close.s_screen.bits_per_pixel,
			&data->door_close.s_screen.line_length,
			&data->door_close.s_screen.endian);
	return (0);
}

int	ft_set_img_door_open(t_all *data)
{
	data->door_open.img = mlx_xpm_file_to_image(data->mlx,
			data->door_open.dest, &data->door_open.img_width,
			&data->door_open.img_heigth);
	if (!data->door_open.img)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->door_open.s_screen.addr = mlx_get_data_addr(data->door_open.img,
			&data->door_open.s_screen.bits_per_pixel,
			&data->door_open.s_screen.line_length,
			&data->door_open.s_screen.endian);
	return (0);
}
