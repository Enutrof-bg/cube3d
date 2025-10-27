/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:13:42 by kevwang           #+#    #+#             */
/*   Updated: 2025/10/27 11:13:43 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	get_time_micro(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec));
}

void	ft_usleep(long usec)
{
	long	start;

	start = get_time_ms() * 1000;
	while (get_time_ms() * 1000 - start < usec)
	{
		// if (get_int(&table->table_mutex, &table->end) == 1)
		// 	break ;
		usleep(100);
	}
}

void	ft_free_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}


int	on_destroy(t_all *data)
{
	if (data->img_sol)
		mlx_destroy_image(data->mlx, data->img_sol);
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_player)
		mlx_destroy_image(data->mlx, data->img_player);
	// if (data->img.img_key)
	// 	mlx_destroy_image(data->mlx, data->img.img_key);
	// if (data->img.img_exit)
	// 	mlx_destroy_image(data->mlx, data->img.img_exit);
	// if (data->img.img_exit_open)
	// 	mlx_destroy_image(data->mlx, data->img.img_exit_open);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	if (data->map)
		ft_free_double_tab(data->map);
	free(data->mlx);
	exit(0);
	return (0);
}

void	set_img(t_all *data)
{
	data->img_width = 32;
	data->img_heigth = 32;
	// data->player_end = 0;
	// data->player_collect = 0;
	data->img_sol = NULL;
	data->img_wall = NULL;
	data->img_player = NULL;
	// data->img.img_key = NULL;
	// data->img.img_exit = NULL;
	// data->img.img_exit_open = NULL;
	// ft_get_img_grass(data);
	// ft_get_img_wall(data);
	// ft_get_img_char(data);
	// ft_get_img_key(data);
	// ft_get_img_exit(data);
	// ft_get_img_exit_open(data);

	data->dest_sol = "./img/sol.xpm";
	data->img_sol = mlx_xpm_file_to_image(data->mlx,
			data->dest_sol, &data->img_width, &data->img_heigth);
	if (!data->img_sol)
	{
		// ft_printf("Error\nXPM file invalid\n");
		// on_destroy(data);
		exit(EXIT_FAILURE);
	}

	data->dest_wall = "./img/wall.xpm";
	data->img_wall = mlx_xpm_file_to_image(data->mlx,
			data->dest_wall, &data->img_width, &data->img_heigth);
	if (!data->img_wall)
	{
		// ft_printf("Error\nXPM file invalid\n");
		// on_destroy(data);
		exit(EXIT_FAILURE);
	}

	data->dest_player = "./img/player.xpm";
	data->img_player = mlx_xpm_file_to_image(data->mlx,
			data->dest_player, &data->img_width, &data->img_heigth);
	if (!data->img_player)
	{
		// ft_printf("Error\nXPM file invalid\n");
		// on_destroy(data);
		exit(EXIT_FAILURE);
	}

}

void	ft_printf_map(t_all *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_sol,
		data->img_width * j, data->img_heigth * i);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_wall,
		data->img_width * j, data->img_heigth * i);
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_player,
		data->img_width * j, data->img_heigth * i);
			j++;
		}
		i++;
	}
}

int set_pos_player(t_all *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->pos_player_x = -1;
	data->pos_player_y = -1;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->pos_player_x = j;
				data->pos_player_y = i;
				return 0;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return -1;
}

int	on_keypress(int keysym, t_all *data)
{
	// static int	count = 0;
	// char		*temp;

	if (keysym == KEY_ESC)
		on_destroy(data);
	if (keysym == KEY_W || keysym == KEY_UP)
	{
		if ((data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player))) * 1 >= 0)
				&& (data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player))) * 1 < data->map_length)
				&& (data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player))) * 1 >= 0)
				&& (data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player))) * 1 < data->map_heigth)
				&& data->map[(int)(data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player))))][(int)(data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player))))] != '1')
		{
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
			data->pos_player_x = data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player)) * 1);
			data->pos_player_y = data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player)) * 1);
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		}
	}
	else if (keysym == KEY_S || keysym == KEY_DOWN)
	{
		if ((data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player))) * 1 >= 0)
				&& (data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player))) * 1 < data->map_length)
				&& (data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player))) * 1 >= 0)
				&& (data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player))) * 1 < data->map_heigth)
				&& data->map[(int)(data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player))))][(int)(data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player))))] != '1')
		{
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
		data->pos_player_x = data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player)) * 1);
		data->pos_player_y = data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player)) * 1);
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		}
	}
	else if (keysym == KEY_A)
	{
		if ((data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player) + M_PI /2) >= 0)
				&& (data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player) + M_PI /2))) < data->map_length
				&& (data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player) + M_PI /2))) >= 0)
				&& (data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player) + M_PI /2))) < data->map_heigth
				&& data->map[(int)(data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player) + M_PI /2)))][(int)(data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player) + M_PI /2)))] != '1')
		{
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
		data->pos_player_x = data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player) + M_PI /2) * 1);
		data->pos_player_y = data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player) + M_PI /2) * 1);
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		}
	}
	else if (keysym == KEY_D)
	{
		if ((data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player) + M_PI /2) >= 0)
				&& (data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player) + M_PI /2))) < data->map_length
				&& (data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player) + M_PI /2))) >= 0)
				&& (data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player) + M_PI /2))) < data->map_heigth
				&& data->map[(int)(data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player) + M_PI /2)))][(int)(data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player) + M_PI /2)))] != '1')
		{
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
		data->pos_player_x = data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player) + M_PI /2) * 1);
		data->pos_player_y = data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player) + M_PI /2) * 1);
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		}
	}
	else if (/*keysym == KEY_A || */keysym == KEY_LEFT)
	{
		data->angle_player = (data->angle_player - data->rotate_speed) % 360;
	}
	else if (/*keysym == KEY_D || */keysym == KEY_RIGHT)
	{
		data->angle_player = (data->angle_player + data->rotate_speed) % 360;
	}

	printf("pos_player_x:%f\n", data->pos_player_x);
	printf("pos_player_y:%f\n", data->pos_player_y);

	printf("pos_player_x(int):%d\n", (int)data->pos_player_x);
	printf("pos_player_y(int):%d\n", (int)data->pos_player_y);

	printf("map_x length:%d\n", (int)data->map_length);
	printf("map_y height:%d\n", (int)data->map_heigth);

	printf("angle_player:%d\n", data->angle_player);
	// ft_printf("PM:%d\n", count);
	// temp = ft_itoa(count);
	// print_img_wall(data, &data->img, 0, 0);
	// mlx_string_put(data->mlx, data->mlx_win, 32, 32, 0x00FF0000, temp);
	// free(temp);
	// if (data->player_end == 1)
	// 	on_destroy(data);
	ft_printf_map(data);
	// int i = 0;
	// while (data->map[i])
	// {
	// 	printf("%s\n", data->map[i]);
	// 	i++;
	// }
	return (0);
}



int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("test\n");
	// char **map;
	t_all data;

	if (argc == 2)
	{
		data.map = ft_open_map(&data, argv[1]);
		int i = 0;
		while (data.map[i])
		{
			printf("%s\n", data.map[i]);
			i++;
		}
		set_pos_player(&data);
		printf("%f\n", data.pos_player_x);
		printf("%f\n", data.pos_player_y);


		data.dir_player_x = -1;
		data.dir_player_y = 0;

		data.angle_player = 0;
		data.rotate_speed = 9;

		data.start_time = get_time_ms();

		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx,
				TILE_SIZE * data.map_length,
				TILE_SIZE * data.map_heigth, "wallong");

		mlx_hook(data.mlx_win, 2 , 1L<<0,&on_keypress, &data);
		// mlx_key_hook(data.mlx_win, &on_keypress, &data);
		mlx_hook(data.mlx_win, DestroyNotify,
			StructureNotifyMask, &on_destroy, &data);
		set_img(&data);

		// int frame = 0;
		// while (1)
		// {
		// 	if ((get_time_ms() - data.start_time) % 30 > frame )
		// 	{
		// 		ft_printf_map(&data);
		// 	}
		// }
		ft_printf_map(&data);
		// mlx_loop_hook(game_engine);
		mlx_loop(data.mlx);
	}
}