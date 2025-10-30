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

void raycasting(t_all *data);

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

	if (data->img_n)
		mlx_destroy_image(data->mlx, data->img_n);
	if (data->img_s)
		mlx_destroy_image(data->mlx, data->img_s);
	if (data->img_e)
		mlx_destroy_image(data->mlx, data->img_e);
	if (data->img_w)
		mlx_destroy_image(data->mlx, data->img_w);
	// if (data->img.img_key)
	// 	mlx_destroy_image(data->mlx, data->img.img_key);
	// if (data->img.img_exit)
	// 	mlx_destroy_image(data->mlx, data->img.img_exit);
	// if (data->img.img_exit_open)
	// 	mlx_destroy_image(data->mlx, data->img.img_exit_open);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win_2);
	mlx_destroy_display(data->mlx);
	if (data->map)
		ft_free_double_tab(data->map);
	// free(data->img.img);
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

	data->dest_sol = "./img/sol2.xpm";
	data->img_sol = mlx_xpm_file_to_image(data->mlx,
			data->dest_sol, &data->img_width, &data->img_heigth);
	if (!data->img_sol)
	{
		// ft_printf("Error\nXPM file invalid\n");
		// on_destroy(data);
		exit(EXIT_FAILURE);
	}

	data->dest_wall = "./img/wall2.xpm";
	data->img_wall = mlx_xpm_file_to_image(data->mlx,
			data->dest_wall, &data->img_width, &data->img_heigth);
	if (!data->img_wall)
	{
		// ft_printf("Error\nXPM file invalid\n");
		// on_destroy(data);
		exit(EXIT_FAILURE);
	}

	data->dest_player = "./img/player2.xpm";
	data->img_player = mlx_xpm_file_to_image(data->mlx,
			data->dest_player, &data->img_width, &data->img_heigth);
	if (!data->img_player)
	{
		// ft_printf("Error\nXPM file invalid\n");
		// on_destroy(data);
		exit(EXIT_FAILURE);
	}

	data->dest_n = "./img/n.xpm";
	data->img_n = mlx_xpm_file_to_image(data->mlx,
			data->dest_n, &data->texture_width, &data->texture_heigth);
	if (!data->img_n)
	{
		// ft_printf("Error\nXPM file invalid\n");
		// on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->n.addr = mlx_get_data_addr(data->img_n, &data->n.bits_per_pixel,
			&data->n.line_length, &data->n.endian);


	data->dest_s = "./img/s.xpm";
	data->img_s = mlx_xpm_file_to_image(data->mlx,
			data->dest_s, &data->texture_width, &data->texture_heigth);
	if (!data->img_s)
	{
		// ft_printf("Error\nXPM file invalid\n");
		// on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->s.addr = mlx_get_data_addr(data->img_s, &data->s.bits_per_pixel,
			&data->s.line_length, &data->s.endian);


	data->dest_e = "./img/e.xpm";
	data->img_e = mlx_xpm_file_to_image(data->mlx,
			data->dest_e, &data->texture_width, &data->texture_heigth);
	if (!data->img_e)
	{
		// ft_printf("Error\nXPM file invalid\n");
		// on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->e.addr = mlx_get_data_addr(data->img_e, &data->e.bits_per_pixel,
			&data->e.line_length, &data->e.endian);

	data->dest_w = "./img/w.xpm";
	data->img_w = mlx_xpm_file_to_image(data->mlx,
			data->dest_w, &data->texture_width, &data->texture_heigth);
	if (!data->img_w)
	{
		// ft_printf("Error\nXPM file invalid\n");
		// on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->w.addr = mlx_get_data_addr(data->img_w, &data->w.bits_per_pixel,
			&data->w.line_length, &data->w.endian);

}

void	ft_printf_map(t_all *data)
{
	int	i;
	int	j;

	int map_x = 0;
	int map_y = 0;

	int pixel = 0;

	i = 0;
	j = 0;
	if ((int)data->pos_player_y + MAP_SIZE_Y/2 > data->map_heigth)
	{
		// i = data->map_heigth - (int)data->pos_player_y;
		i = data->map_heigth - MAP_SIZE_Y;
		printf("map_heigth:%d pos_y:%f\n", data->map_heigth, data->pos_player_y);
		printf("debut i1:%d\n", i);
	}
	else if ((int)data->pos_player_y < MAP_SIZE_Y/2)
	{
		i = 0;
		printf("map_heigth:%d pos_y:%f\n", data->map_heigth, data->pos_player_y);
		printf("debut i2:%d\n", i);
	}
	else
	{
		i = (int)data->pos_player_y - MAP_SIZE_Y/2;
		printf("map_heigth:%d pos_y:%f\n", data->map_heigth, data->pos_player_y);
		printf("debut i3:%d\n", i);
	}

	while (data->map[i])
	{

		map_y = 0;
		j = 0;
		if ((int)data->pos_player_x + MAP_SIZE_X/2 > data->map_length)
		{
			// i = data->map_length - (int)data->pos_player_x;
			j = data->map_length - MAP_SIZE_X;
			printf("map_length:%d pos_y:%f\n", data->map_length, data->pos_player_x);
			printf("debut i1:%d\n", j);
		}
		else if ((int)data->pos_player_x < MAP_SIZE_X/2)
		{
			j = 0;
			printf("map_length:%d pos_y:%f\n", data->map_length, data->pos_player_x);
			printf("debut i2:%d\n", j);
		}
		else
		{
			j = (int)data->pos_player_x - MAP_SIZE_X/2;
			printf("map_length:%d pos_y:%f\n", data->map_length, data->pos_player_x);
			printf("debut i3:%d\n", j);
		}
		while (data->map[i][j])
		{

			// printf("minimap i:%d j:%d m_x:%d m_y:%d\n", i, j, map_x, map_y);
			// if (map_y < MAP_SIZE_X && map_x < MAP_SIZE_Y)
			// if (i >= (data->pos_player_x - MAP_SIZE_X) && i < (data->pos_player_x + MAP_SIZE_X) && map_x < MAP_SIZE_X
				// && j >= (data->pos_player_y - MAP_SIZE_Y) && j < (data->pos_player_y + MAP_SIZE_Y) && map_y < MAP_SIZE_Y)

			// if (pixel < MAP_SIZE_Y)
			{
				if (data->map[i][j] == '0')
					mlx_put_image_to_window(data->mlx, data->mlx_win_2, data->img_sol,
						data->img_width * map_y, data->img_heigth * map_x);
				if (data->map[i][j] == '1')
					mlx_put_image_to_window(data->mlx, data->mlx_win_2, data->img_wall,
						data->img_width * map_y, data->img_heigth * map_x);
				if (data->map[i][j] == 'P')
					mlx_put_image_to_window(data->mlx, data->mlx_win_2, data->img_player,
						data->img_width * map_y, data->img_heigth * map_x);
				pixel++;
			}
			map_y++;
			j++;
		}
		map_x++;
		i++;
	}
	printf("fin i:%d\n", i);
	// mlx_put_image_to_window(data->mlx, data->mlx_win_2, data->img_n, 0, 0);
}

int set_dir_player(t_all *data, char dir)
{
	if (dir == 'N')
	{
		data->dir_player_x = 0;
		data->dir_player_y = -1;
		data->plane_dir_x = 0.66;
		data->plane_dir_y = 0;
	}
	else if (dir == 'S')
	{
		data->dir_player_x = 0;
		data->dir_player_y = 1;
		data->plane_dir_x = -0.66;
		data->plane_dir_y = 0;
	}
	else if (dir == 'W')
	{
		data->dir_player_x = -1;
		data->dir_player_y = 0;
		data->plane_dir_x = 0;
		data->plane_dir_y = -0.66;
	}
	else if (dir == 'E')
	{
		data->dir_player_x = 1;
		data->dir_player_y = 0;
		data->plane_dir_x = 0;
		data->plane_dir_y = 0.66;
	}
	return (0);
}

int set_pos_player(t_all *data)
{
	int i;
	int j;

	i = 0;
	data->pos_player_x = -1;
	data->pos_player_y = -1;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				||data->map[i][j] == 'W' ||data->map[i][j] == 'E')
			{
				data->pos_player_x = j;
				data->pos_player_y = i;
				set_dir_player(data, data->map[i][j]);
				data->map[i][j] = 'P';
				return 0;
			}
			j++;
		}
		i++;
	}
	return (-1);
}

void print_data(t_all *data)
{
	printf("pos_player_x:%f\n", data->pos_player_x);
	printf("pos_player_y:%f\n", data->pos_player_y);

	printf("pos_player_x(int):%d\n", (int)data->pos_player_x);
	printf("pos_player_y(int):%d\n", (int)data->pos_player_y);

	printf("dir_player_x:%f\n", data->dir_player_x);
	printf("dir_player_y:%f\n", data->dir_player_y);

	printf("plane_dir_x:%f\n", data->plane_dir_x);
	printf("plane_dir_y:%f\n", data->plane_dir_y);

	printf("map_x length:%d\n", (int)data->map_length);
	printf("map_y height:%d\n", (int)data->map_heigth);

	printf("angle_player:%d\n", data->angle_player);
}

int check_collision(t_all *data, double x, double y)
{
	int int_x;
	int int_y;

	int_x = (int)x;
	int_y = (int)y;
	if (x >= 0 && x < data->map_length	&& y >= 0 && y < data->map_heigth
		&& data->map[int_y][int_x] != '1')
		return(0);
	return (1);
}

int	on_keypress(int keysym, t_all *data)
{
	// static int	count = 0;
	// char		*temp;
	// print_data(data);
	if (keysym == KEY_ESC)
		on_destroy(data);
	if (keysym == KEY_W)
	{
		// if ((data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player))) * 1 >= 0)
		// 		&& (data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player))) * 1 < data->map_length)
		// 		&& (data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player))) * 1 >= 0)
		// 		&& (data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player))) * 1 < data->map_heigth)
		// 		&& data->map[(int)(data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player))))][(int)(data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player))))] != '1')
		// if (data->pos_player_x + data->dir_player_x * MS >= 0
		// 	&& data->pos_player_x + data->dir_player_x * MS < data->map_length
		// 	&& data->pos_player_y + data->dir_player_y * MS >= 0
		// 	&& data->pos_player_y + data->dir_player_y * MS < data->map_heigth
		// 	&& data->map[(int)(data->pos_player_y + data->dir_player_y * MS)][(int)(data->pos_player_x + data->dir_player_x * MS)] != '1')
		// {

			// data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
			// data->pos_player_x = data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player)) * 1);
			// data->pos_player_y = data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player)) * 1);
			data->temp_x = data->pos_player_x + data->dir_player_x * MS;
			data->temp_y = data->pos_player_y + data->dir_player_y * MS;
			if (check_collision(data, data->temp_x, data->pos_player_y) == 0)
			{
				data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
				data->pos_player_x = data->temp_x;
				data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
			}
			if (check_collision(data, data->pos_player_x, data->temp_y) == 0)
			{
				data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
				data->pos_player_y = data->temp_y;
				data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
			}
			// data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
			// data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		// }
	}
	else if (keysym == KEY_S)
	{
		// if ((data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player))) * 1 >= 0)
		// 		&& (data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player))) * 1 < data->map_length)
		// 		&& (data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player))) * 1 >= 0)
		// 		&& (data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player))) * 1 < data->map_heigth)
		// 		&& data->map[(int)(data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player))))][(int)(data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player))))] != '1')
		// if (data->pos_player_x - data->dir_player_x * MS >= 0
		// 	&& data->pos_player_x - data->dir_player_x * MS < data->map_length
		// 	&& data->pos_player_y - data->dir_player_y * MS >= 0
		// 	&& data->pos_player_y - data->dir_player_y * MS < data->map_heigth
		// 	&& data->map[(int)(data->pos_player_y - data->dir_player_y * MS)][(int)(data->pos_player_x - data->dir_player_x * MS)] != '1')
		// {
		// data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
		// // data->pos_player_x = data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player)) * 1);
		// // data->pos_player_y = data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player)) * 1);
		// data->pos_player_x = data->pos_player_x - data->dir_player_x * MS;
		// data->pos_player_y = data->pos_player_y - data->dir_player_y * MS;
		// data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		// }
		data->temp_x = data->pos_player_x - data->dir_player_x * MS;
		data->temp_y = data->pos_player_y - data->dir_player_y * MS;
		if (check_collision(data, data->temp_x, data->pos_player_y) == 0)
		{
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
			data->pos_player_x = data->temp_x;
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		}
		if (check_collision(data, data->pos_player_x, data->temp_y) == 0)
		{
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
			data->pos_player_y = data->temp_y;
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		}
	}
	else if (keysym == KEY_A)
	{
		// if ((data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player) + M_PI /2) >= 0)
		// 		&& (data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player) + M_PI /2))) < data->map_length
		// 		&& (data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player) + M_PI /2))) >= 0)
		// 		&& (data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player) + M_PI /2))) < data->map_heigth
		// 		&& data->map[(int)(data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player) + M_PI /2)))][(int)(data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player) + M_PI /2)))] != '1')
		// {
		// if (data->pos_player_x - data->plane_dir_x * MS >= 0
		// 	&& data->pos_player_x - data->plane_dir_x * MS < data->map_length
		// 	&& data->pos_player_y - data->plane_dir_y * MS >= 0
		// 	&& data->pos_player_y - data->plane_dir_y * MS < data->map_heigth
		// 	&& data->map[(int)(data->pos_player_y - data->plane_dir_y * MS)][(int)(data->pos_player_x - data->plane_dir_x * MS)] != '1')
		// {
		// data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
		// // data->pos_player_x = data->pos_player_x - (cos(DEG_TO_RAD(data->angle_player) + M_PI /2) * 1);
		// // data->pos_player_y = data->pos_player_y - (sin(DEG_TO_RAD(data->angle_player) + M_PI /2) * 1);
		// data->pos_player_x = data->pos_player_x - data->plane_dir_x * MS;
		// data->pos_player_y = data->pos_player_y - data->plane_dir_y * MS;
		// data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		// }
		data->temp_x = data->pos_player_x - data->plane_dir_x * MS;
		data->temp_y = data->pos_player_y - data->plane_dir_y * MS;
		if (check_collision(data, data->temp_x, data->pos_player_y) == 0)
		{
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
			data->pos_player_x = data->temp_x;
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		}
		if (check_collision(data, data->pos_player_x, data->temp_y) == 0)
		{
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
			data->pos_player_y = data->temp_y;
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		}
	}
	else if (keysym == KEY_D)
	{
		// if ((data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player) + M_PI /2) >= 0)
		// 		&& (data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player) + M_PI /2))) < data->map_length
		// 		&& (data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player) + M_PI /2))) >= 0)
		// 		&& (data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player) + M_PI /2))) < data->map_heigth
		// 		&& data->map[(int)(data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player) + M_PI /2)))][(int)(data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player) + M_PI /2)))] != '1')
		// if (data->pos_player_x + data->plane_dir_x * MS >= 0
		// 	&& data->pos_player_x + data->plane_dir_x * MS < data->map_length
		// 	&& data->pos_player_y + data->plane_dir_y * MS >= 0
		// 	&& data->pos_player_y + data->plane_dir_y * MS < data->map_heigth
		// 	&& data->map[(int)(data->pos_player_y + data->plane_dir_y * MS)][(int)(data->pos_player_x + data->plane_dir_x * MS)] != '1')
		// {
		// data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
		// // data->pos_player_x = data->pos_player_x + (cos(DEG_TO_RAD(data->angle_player) + M_PI /2) * 1);
		// // data->pos_player_y = data->pos_player_y + (sin(DEG_TO_RAD(data->angle_player) + M_PI /2) * 1);
		// data->pos_player_x = data->pos_player_x + data->plane_dir_x * MS;
		// data->pos_player_y = data->pos_player_y + data->plane_dir_y * MS;
		// data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		// }
		data->temp_x = data->pos_player_x + data->plane_dir_x * MS;
		data->temp_y = data->pos_player_y + data->plane_dir_y * MS;
		if (check_collision(data, data->temp_x, data->pos_player_y) == 0)
		{
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
			data->pos_player_x = data->temp_x;
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		}
		if (check_collision(data, data->pos_player_x, data->temp_y) == 0)
		{
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
			data->pos_player_y = data->temp_y;
			data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
		}
	}
	else if (/*keysym == KEY_A || */keysym == KEY_LEFT)
	{
		double temp;
		data->angle_player = (data->angle_player - data->rotate_speed) % 360;

		temp = data->dir_player_x;
		data->dir_player_x = data->dir_player_x * cos(-ROTATE) - data->dir_player_y * sin(-ROTATE);
		data->dir_player_y = temp * sin(-ROTATE) + data->dir_player_y * cos(-ROTATE);

		temp = data->plane_dir_x;
		data->plane_dir_x = data->plane_dir_x * cos(-ROTATE) - data->plane_dir_y * sin(-ROTATE);
		data->plane_dir_y = temp * sin(-ROTATE) + data->plane_dir_y * cos(-ROTATE);
	}
	else if (/*keysym == KEY_D || */keysym == KEY_RIGHT)
	{
		double temp;
		data->angle_player = (data->angle_player + data->rotate_speed) % 360;

		temp = data->dir_player_x;
		data->dir_player_x = data->dir_player_x * cos(ROTATE) - data->dir_player_y * sin(ROTATE);
		data->dir_player_y = temp * sin(ROTATE) + data->dir_player_y * cos(ROTATE);

		temp = data->plane_dir_x;
		data->plane_dir_x = data->plane_dir_x * cos(ROTATE) - data->plane_dir_y * sin(ROTATE);
		data->plane_dir_y = temp * sin(ROTATE) + data->plane_dir_y * cos(ROTATE);
	}
	// print_data(data);
	

	raycasting(data);
	ft_printf_map(data);
	return (0);
}

void	my_mlx_pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void raycasting(t_all *data)
{
	int pos = 0;

	pos = 0;
	while (pos < W)
	{
		// my_mlx_pixel_put(data, pos, i, 0x00FF0000);

		data->camera_x = 2 * pos / (double)W - 1;
		data->ray_dir_x = data->dir_player_x + data->plane_dir_x * data->camera_x;
		data->ray_dir_y = data->dir_player_y + data->plane_dir_y * data->camera_x;

		data->player_pos_int_x = (int)data->pos_player_x;
		data->player_pos_int_y = (int)data->pos_player_y;

		data->line_length_x = fabs(1 / data->ray_dir_x);
		data->line_length_y = fabs(1 / data->ray_dir_y);

		if (data->ray_dir_x < 0)
		{
			data->steps_x = -1;
			data->distance_x = (data->pos_player_x - data->player_pos_int_x) * data->line_length_x;
		}
		else
		{
			data->steps_x = 1;
			data->distance_x = (data->player_pos_int_x +1.0 - data->pos_player_x) * data->line_length_x;
		}
		if (data->ray_dir_y < 0)
		{
			data->steps_y = -1;
			data->distance_y = (data->pos_player_y - data->player_pos_int_y) * data->line_length_y;
		}
		else
		{
			data->steps_y = 1;
			data->distance_y = (data->player_pos_int_y +1.0 - data->pos_player_y) * data->line_length_y;
		}

		data->wall = 0;
		data->contact = 0;
		while (data->contact == 0)
		{
			if (data->distance_x < data->distance_y)
			{
				data->distance_x = data->distance_x + data->line_length_x;
				data->player_pos_int_x += data->steps_x;
				data->wall = 0;
			}
			else
			{
				data->distance_y = data->distance_y + data->line_length_y;
				data->player_pos_int_y += data->steps_y;
				data->wall = 1;
			}
			if (data->player_pos_int_x < 0 || data->player_pos_int_x >= data->map_length
				|| data->player_pos_int_y < 0 || data->player_pos_int_y >= data->map_heigth)
			{
				break;
			}
			if (data->map[data->player_pos_int_y][data->player_pos_int_x] == '1')
				data->contact = 1;
		}
		// int test;
		if (data->wall == 0)
		{
			data->wall_distance = (data->player_pos_int_x - data->pos_player_x + (1 - data->steps_x)/2) / data->ray_dir_x;
			// data->wall_distance = (data->player_pos_int_x - data->pos_player_x) / data->ray_dir_x;
			// test = data->player_pos_int_x - data->pos_player_x;
		}
		else
		{
			data->wall_distance = (data->player_pos_int_y - data->pos_player_y + (1 - data->steps_y)/2) / data->ray_dir_y;
			// data->wall_distance = (data->player_pos_int_y - data->pos_player_y) / data->ray_dir_y;
			// test = data->wall_distance = data->player_pos_int_y - data->pos_player_y;
		}
		if (data->wall_distance < 0.01)
			data->wall_distance = 0.01;

		data->line_height = (int)H / data->wall_distance;
		data->texture_start = (H /2) - (data->line_height / 2);
		if (data->texture_start < 0)
			data->texture_start = 0;		
		data->texture_end =  (H /2) + (data->line_height / 2);
		if (data->texture_end >= H)
			data->texture_end = H - 1;

		int y = 0;
		unsigned int color;
		while (y < data->texture_start)
		{
			// my_mlx_pixel_put(data, pos, y, 0X87CEEB);
			my_mlx_pixel_put(data, pos, y, 8900331);
			y++;
		}



		int pixel;
		(void)pixel;
		// data->ratio_pixel = TEXTURE_SIZE /(data->texture_end - data->texture_start);
		// printf("ratio_pixel:%f\n", data->ratio_pixel);

		if (data->wall == 0)
		{
			// data->ratio = (data->distance_x / data->dir_player_y) - (int)data->player_pos_int_x;
			// data->ratio = (data->distance_y / data->dir_player_x) - (int)data->distance_x;
			data->ratio = data->pos_player_y + data->wall_distance * data->ray_dir_y;
			// data->ratio = data->wall_distance;
			// printf("ratio:%f\n", data->ratio);


			// data->ratio_pixel = TEXTURE_SIZE /(data->texture_end - data->texture_start);
			// printf("ratio_pixel:%f\n", data->ratio_pixel);

			// pixel = (y - data->texture_start) * data->ratio_pixel;
			// printf("pixel:%d\n", pixel);
			// color = 16777215;
			// color = 0x856985;
		}
		else
		{
			// data->ratio = (data->distance_y / data->dir_player_x) - (int)data->player_pos_int_y;
			// data->ratio = (data->distance_y / data->dir_player_x) - (int)data->distance_y;
			data->ratio = data->pos_player_x + data->wall_distance * data->ray_dir_x;
			// data->ratio = data->wall_distance;
			// printf("ratio:%f\n", data->ratio);

			// data->ratio_pixel = TEXTURE_SIZE /(data->texture_end - data->texture_start);
			// printf("ratio_pixel:%f\n", data->ratio_pixel);

			// pixel = (y - data->texture_start) * data->ratio_pixel;
			// printf("pixel:%d\n", pixel);
			// color = 0;
			// color = 0xA19291;
		}
		data->ratio -= floor(data->ratio);

		int texture_x = (int)((1 - data->ratio) * (double)TEXTURE_SIZE);

		if ((data->wall == 0 && data->ray_dir_x > 0) || (data->wall == 1 && data->ray_dir_y < 0))
            texture_x = TEXTURE_SIZE - texture_x - 1;

        double pixel_ratio = (double)TEXTURE_SIZE / data->line_height;
        double texture_pos = (data->texture_start - (H /2) + (data->line_height / 2)) * pixel_ratio;

		while (y < data->texture_end)
		{
			// printf("ratio_pixel:%f\n", data->ratio_pixel);
			int texture_y = (int)texture_pos % TEXTURE_SIZE;
			texture_pos += pixel_ratio;

			// pixel = (y - data->texture_start) * data->ratio_pixel;
			// // printf("pixel:%f\n", pixel);
			
			
			color = 0;
			// dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
			if (data->wall == 1 && data->ray_dir_y > 0)
			{
				// color = data->e.addr[(int)((pixel * data->e.line_length + data->ratio_pixel * TEXTURE_SIZE * ( data->e.bits_per_pixel / 8)))];
				// // printf("y:%d | ", y);
				// printf("addr:%d\n", (int)((pixel * data->e.line_length + data->ratio_pixel * TEXTURE_SIZE * ( data->e.bits_per_pixel / 8))));
				// printf("y:%d | ", y);
				// color = (data->e.addr[(int)((texture_y * data->e.line_length + texture_x * ( data->e.bits_per_pixel / 8)))]);
				// color = *(unsigned int*)&(data->e.addr[(int)((texture_y * data->e.line_length + texture_x * ( data->e.bits_per_pixel / 8)))]);
				color = *(unsigned int*)(data->s.addr + (texture_y * data->s.line_length + texture_x * ( data->s.bits_per_pixel / 8)));
				// char *pixel_addr = data->e.addr + (texture_y * data->e.line_length + texture_x * ( data->e.bits_per_pixel / 8));
				// color = *(unsigned int*)pixel_addr;
			}

			else if (data->wall == 1 && data->ray_dir_y < 0)
			{
				// color = *(unsigned int*)&data->w.addr[(int)((pixel * data->w.line_length + data->ratio_pixel * TEXTURE_SIZE * ( data->w.bits_per_pixel / 8)))];
				// printf("y:%d | ", y);
				// printf("addr:%d\n", (int)((pixel * data->w.line_length + data->ratio_pixel * TEXTURE_SIZE * ( data->w.bits_per_pixel / 8))));
				// color = (data->w.addr[(int)((texture_y * data->w.line_length + texture_x * ( data->w.bits_per_pixel / 8)))]);
				// color = *(unsigned int*)&(data->w.addr[(int)((texture_y * data->w.line_length + texture_x * ( data->w.bits_per_pixel / 8)))]);
				color = *(unsigned int*)(data->n.addr + (texture_y * data->n.line_length + texture_x * ( data->n.bits_per_pixel / 8)));
				// char *pixel_addr = data->w.addr + (texture_y * data->w.line_length + texture_x * ( data->w.bits_per_pixel / 8));
				// color = *(unsigned int*)pixel_addr;
				
			}

			else if (data->wall == 0 && data->ray_dir_x > 0)
			{
				// color = *(unsigned int*)&data->n.addr[(int)((pixel * data->n.line_length + data->ratio_pixel * TEXTURE_SIZE * ( data->n.bits_per_pixel / 8)))];
				// printf("y:%d | ", y);
				// printf("addr:%d\n", (int)((pixel * data->n.line_length + data->ratio_pixel * TEXTURE_SIZE * ( data->n.bits_per_pixel / 8))));
				// color = (data->n.addr[(int)((texture_y * data->n.line_length + texture_x * ( data->n.bits_per_pixel / 8)))]);
				// color = *(unsigned int*)&(data->n.addr[(int)((texture_y * data->n.line_length + texture_x * ( data->n.bits_per_pixel / 8)))]);
				color = *(unsigned int*)(data->e.addr + (texture_y * data->e.line_length + texture_x * ( data->e.bits_per_pixel / 8)));
				// char *pixel_addr = data->n.addr + (texture_y * data->n.line_length + texture_x * ( data->n.bits_per_pixel / 8));
				// color = *(unsigned int*)pixel_addr;
			}

			else if (data->wall == 0 && data->ray_dir_x < 0)
			{
				// color = *(unsigned int*)&data->s.addr[(int)((pixel * data->s.line_length + data->ratio_pixel * TEXTURE_SIZE * ( data->s.bits_per_pixel / 8)))];
				// printf("y:%d | ", y);
				// printf("addr:%d\n", (int)((pixel * data->s.line_length + data->ratio_pixel * TEXTURE_SIZE * ( data->s.bits_per_pixel / 8))));
				// color = (data->s.addr[(int)((texture_y * data->s.line_length + texture_x * ( data->s.bits_per_pixel / 8)))]);
				// color = *(unsigned int*)&(data->s.addr[(int)((texture_y * data->s.line_length + texture_x * ( data->s.bits_per_pixel / 8)))]);
				color = *(unsigned int*)(data->w.addr + (texture_y * data->w.line_length + texture_x * ( data->w.bits_per_pixel / 8)));
				// char *pixel_addr = data->s.addr + (texture_y * data->s.line_length + texture_x * ( data->s.bits_per_pixel / 8));
				// color = *(unsigned int*)pixel_addr;
			}
			my_mlx_pixel_put(data, pos, y, color);
			y++;
		}




		while (y < H)
		{
			// my_mlx_pixel_put(data, pos, y, 0x2F4F2F);
			my_mlx_pixel_put(data, pos, y, 3100463);
			y++;
		}
		pos++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win_2, data->img.img, 0, 0);
}

int	ft_mouse(t_all *data)
{
	mlx_mouse_get_pos(data->mlx, data->mlx_win_2, &data->mouse_x, &data->mouse_y);
	printf("mouse: x:%d y:%d\n", data->mouse_x, data->mouse_y);

	data->mouse_x = W /2;
	data->mouse_y = H/2;

	return (1);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// printf("test\n");
	// char **map;
	t_all data;

	if (argc == 2)
	{
		data.map = ft_open_map(&data, argv[1]);
		// int i = 0;
		// while (data.map[i])
		// {
		// 	printf("%s\n", data.map[i]);
		// 	i++;
		// }
		if (set_pos_player(&data) == -1)
			return (1);
		// printf("%f\n", data.pos_player_x);
		// printf("%f\n", data.pos_player_y);

		data.angle_player = 0;
		data.rotate_speed = 9;

		data.start_time = get_time_ms();

		data.mlx = mlx_init();

		data.mlx_win_2 = mlx_new_window(data.mlx,
				W, H, "3D");

		data.mlx_win = mlx_new_window(data.mlx,
				TILE_SIZE * MAP_SIZE_X,
				TILE_SIZE * MAP_SIZE_Y, "minimap");
		
		data.img.img = mlx_new_image(data.mlx, W, H);
		data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
			&data.img.line_length, &data.img.endian);
		// mlx_pixel_put(, img.addr[11])

		// data.minimap.img = mlx_new_image(data.mlx, W, H);
		// data.minimap.addr = mlx_get_data_addr(data.minimap.img, &data.minimap.bits_per_pixel,
		// 	&data.minimap.line_length, &data.minimap.endian);

		set_img(&data);

		mlx_hook(data.mlx_win_2, 2 , 1L<<0,&on_keypress, &data);
		// mlx_key_hook(data.mlx_win, &on_keypress, &data);

		mlx_hook(data.mlx_win_2, DestroyNotify,
			StructureNotifyMask, &on_destroy, &data);

		// mlx_hook(data.mlx_win_2, 6, 1L<<0, &ft_mouse, &data);

		raycasting(&data);
		ft_printf_map(&data);

		// mlx_mouse_hide(data.mlx, data.mlx_win_2);
		// mlx_mouse_show(data.mlx, data.mlx_win_2);
	
		
		// mlx_loop_hook(data.mlx, &ft_mouse, &data);

		mlx_loop(data.mlx);
	}
}