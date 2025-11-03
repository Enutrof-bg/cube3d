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

int	on_mouse(int x, int y, t_all *data)
{
	static int prev_mouse = -200000;
	if (prev_mouse == -200000)
	{
		prev_mouse = data->mouse_x;
		return 0;
	}
	data->mouse_x = x;
    data->mouse_y = y;
	// printf("ici\n");
	// printf("DIR = %f\n", data->ray_dir_x);
	if (/*data->mouse_x < W/2  && */data->mouse_x < prev_mouse) //vers la gauche
	{
		// printf("1\n");
		double temp;
		data->angle_player = (data->angle_player - data->rotate_speed) % 180;

		temp = data->dir_player_x;
		data->dir_player_x = data->dir_player_x * cos(-ROTATE_M) - data->dir_player_y * sin(-ROTATE_M);
		data->dir_player_y = temp * sin(-ROTATE_M) + data->dir_player_y * cos(-ROTATE_M);

		temp = data->plane_dir_x;
		data->plane_dir_x = data->plane_dir_x * cos(-ROTATE_M) - data->plane_dir_y * sin(-ROTATE_M);
		data->plane_dir_y = temp * sin(-ROTATE_M) + data->plane_dir_y * cos(-ROTATE_M);
	}
	else if (/*data->mouse_x > W/2*/ data->mouse_x > prev_mouse) //vers la droite
	{
		// printf("1\n");
		double temp;
		data->angle_player = (data->angle_player + data->rotate_speed) % 180;

		temp = data->dir_player_x;
		data->dir_player_x = data->dir_player_x * cos(ROTATE_M) - data->dir_player_y * sin(ROTATE_M);
		data->dir_player_y = temp * sin(ROTATE_M) + data->dir_player_y * cos(ROTATE_M);

		temp = data->plane_dir_x;
		data->plane_dir_x = data->plane_dir_x * cos(ROTATE_M) - data->plane_dir_y * sin(ROTATE_M);
		data->plane_dir_y = temp * sin(ROTATE_M) + data->plane_dir_y * cos(ROTATE_M);
	}
	prev_mouse = x;
	// print_data(data);
	raycasting(data);
	ft_printf_map(data);
	return (0);
}

int	ft_mouse(t_all *data)
{
	mlx_mouse_get_pos(data->mlx, data->mlx_win_2, &data->mouse_x, &data->mouse_y);
	// printf("mouse: x:%d y:%d\n", data->mouse_x, data->mouse_y);

	// data->mouse_x = W /2;
	// data->mouse_y = H/2;
	if (data->mouse_x  < 0 || data->mouse_y < -37 || data->mouse_x > W || data->mouse_y > H)
	{
		if (data->mouse_x  <= 0)
			mlx_mouse_move(data->mlx, data->mlx_win_2,W/2, H/2);
		if (data->mouse_y < -37)
			mlx_mouse_move(data->mlx, data->mlx_win_2, W/2, H/2);
		if (data->mouse_x > W)
			mlx_mouse_move(data->mlx, data->mlx_win_2, W/2, H/2);
		if (data->mouse_y > H )
			mlx_mouse_move(data->mlx, data->mlx_win_2, W/2, H/2);
	}	
		// mlx_mouse_move(data->mlx, data->mlx_win_2, W/2, H/2);
	return (1);
}

int main(int argc, char **argv)
{
	t_all data;

	if (argc == 2)
	{
		data.map = ft_open_map(&data, argv[1]);
		if (set_pos_player(&data) == -1)
			return (1);
		// data.start_time = get_time_ms();

		data.mlx = mlx_init();
		data.mlx_win_2 = mlx_new_window(data.mlx,
				W, H, "3D");

		// data.mlx_win = mlx_new_window(data.mlx,
		// 		TILE_SIZE * MAP_SIZE_X,
		// 		TILE_SIZE * MAP_SIZE_Y, "minimap");
		
		data.img.img = mlx_new_image(data.mlx, W, H);
		data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
			&data.img.line_length, &data.img.endian);
		// mlx_pixel_put(, img.addr[11])


		set_img(&data);


		mlx_hook(data.mlx_win_2, 2 , 1L<<0,&on_keypress, &data);
		mlx_hook(data.mlx_win_2, 6 , 1L << 6, &on_mouse, &data); //test souris
		// mlx_key_hook(data.mlx_win, &on_keypress, &data);
		mlx_hook(data.mlx_win_2, DestroyNotify,
			StructureNotifyMask, &on_destroy, &data);
		
		// mlx_hook(data.mlx_win_2, 6, 1L<<0, &ft_mouse, &data);


		raycasting(&data);
		ft_printf_map(&data);

		mlx_mouse_hide(data.mlx, data.mlx_win_2);
		// mlx_mouse_show(data.mlx, data.mlx_win_2);
		mlx_loop_hook(data.mlx, &ft_mouse, &data);

		mlx_loop(data.mlx);
	}
}