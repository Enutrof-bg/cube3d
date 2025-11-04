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

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	find_biggest_line(t_all *data)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (data->map[i])
	{
		if ((int)ft_strlen(data->map[i]) > line)
			line = (int)ft_strlen(data->map[i]) - 1;
		i++;
	}
	return (line);
}

int	ft_replace(t_all *data, int i, int line)
{
	int		j;
	char	*temp;

	j = 0;
	if ((int)ft_strlen(data->map[i]) < line)
	{
		temp = data->map[i];
		data->map[i] = malloc(sizeof(char) * (line + 1));
		if (!data->map[i])
			return (data->map[i] = temp, 0);
		// data->map[i] = temp;
		// free(temp);
		// return (0);
		ft_strcpy(data->map[i], temp);
		j = (int)ft_strlen(temp) - 1;
		free(temp);
		while (j < line)
		{
			data->map[i][j] = ' ';
			j++;
		}
		data->map[i][j] = '\0';
	}
	return (1);
}

int	realloc_minimap(t_all *data)
{
	int		i;
	int		line;

	i = 0;
	line = find_biggest_line(data);
	while (data->map[i])
	{
		if (ft_replace(data, i, line) == 0)
			return (0);
		i++;
	}
	return (1);
}

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
	if (set_pos_player(&data) == -1)
		return (ft_free_all(&data.cub), 1);
	if (ft_init_mlx(&data) == 1)
		return (1);
	set_img(&data);
	set_img_anim(&data);
	all_hook(&data);
	mlx_loop(data.mlx);
}
