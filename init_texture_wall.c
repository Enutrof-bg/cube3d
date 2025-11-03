/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:08:09 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 16:08:11 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_set_img_north(t_all *data)
{
	data->north.img = mlx_xpm_file_to_image(data->mlx,
			data->north.dest, &data->north.img_width,
			&data->north.img_heigth);
	if (!data->north.img)
	{
		ft_printf("Error\nXPM file invalid\n");
		ft_printf("'%s'", data->north.dest);
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->north.s_screen.addr = mlx_get_data_addr(data->north.img,
			&data->north.s_screen.bits_per_pixel,
			&data->north.s_screen.line_length, &data->north.s_screen.endian);
	return (0);
}

int	ft_set_img_south(t_all *data)
{
	data->south.img = mlx_xpm_file_to_image(data->mlx,
			data->south.dest, &data->south.img_width,
			&data->south.img_heigth);
	if (!data->south.img)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->south.s_screen.addr = mlx_get_data_addr(data->south.img,
			&data->south.s_screen.bits_per_pixel,
			&data->south.s_screen.line_length, &data->south.s_screen.endian);
	return (0);
}

int	ft_set_img_east(t_all *data)
{
	data->east.img = mlx_xpm_file_to_image(data->mlx,
			data->east.dest, &data->east.img_width,
			&data->east.img_heigth);
	if (!data->east.img)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->east.s_screen.addr = mlx_get_data_addr(data->east.img,
			&data->east.s_screen.bits_per_pixel,
			&data->east.s_screen.line_length, &data->east.s_screen.endian);
	return (0);
}

int	ft_set_img_west(t_all *data)
{
	data->west.img = mlx_xpm_file_to_image(data->mlx,
			data->west.dest, &data->west.img_width,
			&data->west.img_heigth);
	if (!data->west.img)
	{
		ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->west.s_screen.addr = mlx_get_data_addr(data->west.img,
			&data->west.s_screen.bits_per_pixel,
			&data->west.s_screen.line_length, &data->west.s_screen.endian);
	return (0);
}
