/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_minimap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:08:38 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 16:08:39 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// int	ft_set_img_sol(t_all *data)
// {
// 	data->t_sol.img = mlx_xpm_file_to_image(data->mlx,
// 			data->t_sol.dest, &data->t_sol.img_width, &data->t_sol.img_heigth);
// 	if (!data->t_sol.img)
// 	{
// 		ft_printf("Error\nXPM file invalid\n");
// 		on_destroy(data);
// 		exit(EXIT_FAILURE);
// 	}
// 	data->t_sol.s_screen.addr = mlx_get_data_addr(data->t_sol.img,
// 			&data->t_sol.s_screen.bits_per_pixel,
// 			&data->t_sol.s_screen.line_length, &data->t_sol.s_screen.endian);
// 	return (0);
// }

// int	ft_set_img_wall(t_all *data)
// {
// 	data->t_wall.img = mlx_xpm_file_to_image(data->mlx,
// 			data->t_wall.dest, &data->t_wall.img_width,
// 			&data->t_wall.img_heigth);
// 	if (!data->t_wall.img)
// 	{
// 		ft_printf("Error\nXPM file invalid\n");
// 		on_destroy(data);
// 		exit(EXIT_FAILURE);
// 	}
// 	data->t_wall.s_screen.addr = mlx_get_data_addr(data->t_wall.img,
// 			&data->t_wall.s_screen.bits_per_pixel,
// 			&data->t_wall.s_screen.line_length, &data->t_wall.s_screen.endian);
// 	return (0);
// }

// int	ft_set_img_player(t_all *data)
// {
// 	data->t_player.img = mlx_xpm_file_to_image(data->mlx,
// 			data->t_player.dest, &data->t_player.img_width,
// 			&data->t_player.img_heigth);
// 	if (!data->t_player.img)
// 	{
// 		ft_printf("Error\nXPM file invalid\n");
// 		on_destroy(data);
// 		exit(EXIT_FAILURE);
// 	}
// 	data->t_player.s_screen.addr = mlx_get_data_addr(data->t_player.img,
// 			&data->t_player.s_screen.bits_per_pixel,
// 			&data->t_player.s_screen.line_length,
// 			&data->t_player.s_screen.endian);
// 	return (0);
// }
