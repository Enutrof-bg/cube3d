/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:15:09 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:15:09 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// int	count_column(char **tab, int x)
// {
// 	int y = 0;
// 	int result = 0;

// 	while (tab[y])
// 	{
// 		if (tab[y][x])
// 			result++;
// 		else
// 			return result;
// 		y++;
// 	}
// 	return (result);
// }

// void ft_count(t_all *data)
// {
// 	int i = 0;
// 	int len = 0;
// 	int temp;
// 	while (data->map[i])
// 	{
// 		temp = ft_strlen(data->map[i]);
// 		if (temp > len)
// 			len = temp;

// 		i++;
// 	}
// 	data->map_length = len;
// 	data->map_heigth = i;
// }

int	ft_minimap_i(t_all *data)
{
	int	i;

	i = 0;
	if ((int)data->pos_player_y + MAP_SIZE_Y / 2 > data->map_heigth)
	{
		if (data->map_heigth > MAP_SIZE_Y)
			i = data->map_heigth - MAP_SIZE_Y;
		else
			i = 0;
	}
	else if ((int)data->pos_player_y < MAP_SIZE_Y / 2)
		i = 0;
	else
		i = (int)data->pos_player_y - MAP_SIZE_Y / 2;
	return (i);
}

int	ft_minimap_j(t_all *data)
{
	int	j;

	j = 0;
	if ((int)data->pos_player_x + MAP_SIZE_X / 2 > data->map_length)
	{
		if (data->map_length > MAP_SIZE_X)
			j = data->map_length - MAP_SIZE_X;
		else
			j = 0;
	}
	else if ((int)data->pos_player_x < MAP_SIZE_X / 2)
		j = 0;
	else
		j = (int)data->pos_player_x - MAP_SIZE_X / 2;
	return (j);
}

void ft_put_four_pixel(t_all *data, int x, int y, unsigned int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	ft_minimap_get_sprite(t_all *data, int i, int j)
{
	if (data->map[i][j] == '0')
		ft_put_four_pixel(data, data->pixel_x * TILE_SIZE,
			data->pixel_y * TILE_SIZE, 0xffffff);
		// ft_put_xpm_to_img(data, data->t_sol.s_screen,
		// 	data->pixel_x * TILE_SIZE, data->pixel_y * TILE_SIZE);
	if (data->map[i][j] == '1')
		ft_put_four_pixel(data, data->pixel_x * TILE_SIZE,
			data->pixel_y * TILE_SIZE, 0x000000);
		// ft_put_xpm_to_img(data, data->t_wall.s_screen,
		// 	data->pixel_x * TILE_SIZE, data->pixel_y * TILE_SIZE);
	if (data->map[i][j] == 'P' || data->map[i][j] == 'Q')
		ft_put_four_pixel(data, data->pixel_x * TILE_SIZE,
			data->pixel_y * TILE_SIZE, 0XFF0000);
		// ft_put_xpm_to_img(data, data->t_player.s_screen,
		// 	data->pixel_x * TILE_SIZE, data->pixel_y * TILE_SIZE);
	if (data->map[i][j] == 'D')
		ft_put_four_pixel(data, data->pixel_x * TILE_SIZE,
			data->pixel_y * TILE_SIZE, 0xD6B258);
	if (data->map[i][j] == 'O')
		ft_put_four_pixel(data, data->pixel_x * TILE_SIZE,
			data->pixel_y * TILE_SIZE, 0x58D6D4);
	if (data->map[i][j] == ' ')
	{
		return ;
	}
		// ft_put_four_pixel(data, data->pixel_x * TILE_SIZE,
			// data->pixel_y * TILE_SIZE, 0x321332);
}

void	ft_printf_map(t_all *data)
{
	int	i;
	int	j;

	i = ft_minimap_i(data);
	data->pixel_y = 0;
	while (data->map[i] && data->pixel_y < MAP_SIZE_Y)
	{
		j = ft_minimap_j(data);
		data->pixel_x = 0;
		while (data->map[i][j] && data->pixel_x < MAP_SIZE_X)
		{
			ft_minimap_get_sprite(data, i, j);
			data->pixel_x++;
			j++;
		}
		data->pixel_y++;
		i++;
	}
}
