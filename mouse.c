/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:27:07 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/03 14:27:08 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	on_mouse(int x, int y, t_all *data)
{
	static int	prev_mouse = -200000;

	if (prev_mouse == -200000)
	{
		prev_mouse = data->mouse_x;
		return (0);
	}
	data->mouse_x = x;
	data->mouse_y = y;
	if (data->mouse_x < prev_mouse)
	{
		rotate_left(data);
	}
	else if (data->mouse_x > prev_mouse)
	{
		rotate_right(data);
	}
	prev_mouse = x;
	return (0);
}

int	ft_mouse(t_all *data)
{
	mlx_mouse_get_pos(data->mlx, data->mlx_win_2,
		&data->mouse_x, &data->mouse_y);
	if (data->mouse_x < 5 || data->mouse_y < -37
		|| data->mouse_x > W - 5 || data->mouse_y > H - 5)
	{
		if (data->mouse_x <= 5)
			mlx_mouse_move(data->mlx, data->mlx_win_2, W / 2, H / 2);
		if (data->mouse_y < -37)
			mlx_mouse_move(data->mlx, data->mlx_win_2, W / 2, H / 2);
		if (data->mouse_x > W)
			mlx_mouse_move(data->mlx, data->mlx_win_2, W / 2, H / 2);
		if (data->mouse_y > H - 5)
			mlx_mouse_move(data->mlx, data->mlx_win_2, W / 2, H / 2);
	}
	return (1);
}
