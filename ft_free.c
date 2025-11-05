/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:14:08 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:14:09 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_map(t_all *data)
{
	int	i;

	if (!data->map)
		return ;
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
}

int	ft_destroy_image(t_all *data)
{
	if (data->north.img)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->south.img)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->east.img)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->west.img)
		mlx_destroy_image(data->mlx, data->west.img);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->door_close.img)
		mlx_destroy_image(data->mlx, data->door_close.img);
	if (data->door_open.img)
		mlx_destroy_image(data->mlx, data->door_open.img);
	return (0);
}

int	ft_destroy_image_anim(t_all *data)
{
	int	i;

	i = 0;
	while (i < 15)
	{
		if (data->anim[i].img)
			mlx_destroy_image(data->mlx, data->anim[i].img);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (data->hand_anim[i].img)
			mlx_destroy_image(data->mlx, data->hand_anim[i].img);
		i++;
	}
	return (0);
}

void	ft_clean_mlx(t_all *data)
{
	if (data->mlx)
	{
		if (data->mlx_win_2)
			mlx_destroy_window(data->mlx, data->mlx_win_2);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

int	on_destroy(t_all *data)
{
	mlx_do_key_autorepeaton(data->mlx);
	ft_destroy_image(data);
	ft_destroy_image_anim(data);
	ft_free_all(&data->cub);
	ft_clean_mlx(data);
	exit(0);
	return (0);
}
