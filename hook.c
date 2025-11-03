/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:41:56 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:41:56 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	on_keypress(int keysym, t_all *data)
{
	if (keysym == KEY_ESC)
		on_destroy(data);
	if (keysym == KEY_W)
		data->move_x += 1;
	else if (keysym == KEY_S)
		data->move_x -= 1;
	else if (keysym == KEY_A)
		data->move_y -= 1;
	else if (keysym == KEY_D)
		data->move_y += 1;
	else if (keysym == KEY_LEFT)
		data->rotate -= 1;
	else if (keysym == KEY_RIGHT)
		data->rotate += 1;
	else if (keysym == KEY_E)
		open_close_door(data);
	else if (keysym == 32)
		data->shoot = 1;
	return (0);
}

int	on_keyrelease(int keysym, t_all *data)
{
	if (keysym == KEY_ESC)
		on_destroy(data);
	if (keysym == KEY_W)
		data->move_x -= 1;
	else if (keysym == KEY_S)
		data->move_x += 1;
	else if (keysym == KEY_A)
		data->move_y += 1;
	else if (keysym == KEY_D)
		data->move_y-= 1;
	else if (keysym == KEY_LEFT)
		data->rotate += 1;
	else if (keysym == KEY_RIGHT)
		data->rotate -= 1;
	return (0);
}

int	ft_move_player(t_all *data)
{
	if (data->move_x >= 1)
		move_forward(data);
	if (data->move_x <= -1)
		move_backward(data);
	if (data->move_y >= 1)
		move_right(data);
	if (data->move_y <= -1)
		move_left(data);
	if (data->rotate >= 1)
		rotate_right(data);
	if (data->rotate <= -1)
		rotate_left(data);
	return (0);
}

int	ft_move(t_all *data)
{
	long	now;
	long	elapsed;

	now = get_time_ms();
	elapsed = now - data->start_time;
	
	if (elapsed >= 22)
	{
		data->start_time = now;
		ft_move_player(data);
		ft_mouse(data);
		raycasting(data);
		ft_printf_map(data);
		ft_print_anim(data);
		mlx_put_image_to_window(data->mlx, data->mlx_win_2,
			data->img.img, 0, 0);

		// int i = 0;
		// while (data->map[i])
		// 	printf("%s", data->map[i++]);
		// printf("\n\n\n");
		// print_data(data);
	}
	return (0);
}

void	all_hook(t_all *data)
{
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_hook(data->mlx_win_2, 2, 1L << 0, &on_keypress, data);
	mlx_hook(data->mlx_win_2, 3, 1L << 1, &on_keyrelease, data);
	mlx_hook(data->mlx_win_2, 6 , 1L << 6, &on_mouse, data); 
	// mlx_hook(data->mlx_win_2, 6 , 1L << 6, &ft_mouse, &data); 

	mlx_mouse_hide(data->mlx, data->mlx_win_2);

	// mlx_loop_hook(data->mlx, &ft_mouse, &data);
	mlx_loop_hook(data->mlx, &ft_move, data);

	mlx_hook(data->mlx_win_2, DestroyNotify,
		StructureNotifyMask, &on_destroy, data);
}
