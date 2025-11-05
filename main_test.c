/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:13:42 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/04 11:13:13 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_init_mlx(t_all *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_printf("Error\nMLX init failed\n"),
			ft_free_all(&data->cub), 1);
	data->mlx_win_2 = mlx_new_window(data->mlx, W, H, "3D");
	if (!data->mlx_win_2)
		return (ft_printf("Error\nMLX new window failed\n"),
			ft_free_all(&data->cub), ft_clean_mlx(data), 1);
	data->img.img = mlx_new_image(data->mlx, W, H);
	if (!data->img.img)
		return (ft_printf("Error\nMLX new image failed\n"),
			ft_free_all(&data->cub), ft_clean_mlx(data), 1);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	data;

	if (argc != 2)
		return (ft_printf("Error\nWrong number of arguments\n"), 1);
	if (!ft_open_map(&data, argv[1]))
		return (ft_printf("Error\nFailed to open map\n"), 1);
	ft_init_value(&data);
	if (realloc_minimap(&data) == 0)
		return (ft_printf("Error\nMemory allocation failed\n"),
			ft_free_all(&data.cub), 1);
	ft_free_all(&data.cub);
	// if (set_pos_player(&data) == -1)
	// 	return (ft_free_all(&data.cub), 1);
	// if (ft_init_mlx(&data) == 1)
	// 	return (1);
	// set_img(&data);
	// set_img_anim(&data);
	// all_hook(&data);
	// mlx_loop(data.mlx);
}
