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
void	my_mlx_pixel_put(t_all *data, int x, int y, int color);

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

int ft_destroy_image(t_all *data)
{
	if (data->t_sol.img)
		mlx_destroy_image(data->mlx, data->t_sol.img);
	if (data->t_wall.img)
		mlx_destroy_image(data->mlx, data->t_wall.img);
	if (data->t_player.img)
		mlx_destroy_image(data->mlx, data->t_player.img);
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

int ft_destroy_image_anim(t_all *data)
{
	int i;

	i = 0;
	while (i < 15)
	{
		if (data->anim[i].img)
			mlx_destroy_image(data->mlx, data->anim[i].img);
		i++;
	}
	return (0);
}

int	on_destroy(t_all *data)
{
	ft_destroy_image(data);
	ft_destroy_image_anim(data);
	mlx_destroy_window(data->mlx, data->mlx_win_2);
	mlx_destroy_display(data->mlx);
	if (data->map)
		ft_free_double_tab(data->map);
	free(data->mlx);
	exit(0);
	return (0);
}

void	set_img(t_all *data)
{
	data->t_sol.img = NULL;
	data->t_wall.img = NULL;
	data->t_player.img = NULL;
	data->north.img = NULL;
	data->south.img = NULL;
	data->east.img = NULL;
	data->west.img = NULL;
	data->door_open.img = NULL;
	data->door_close.img = NULL;


	data->t_sol.dest = "./img/sol2.xpm";
	data->t_sol.img = mlx_xpm_file_to_image(data->mlx,
			data->t_sol.dest, &data->t_sol.img_width, &data->t_sol.img_heigth);
	if (!data->t_sol.img)
	{
		// ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->t_sol.s_screen.addr = mlx_get_data_addr(data->t_sol.img, &data->t_sol.s_screen.bits_per_pixel,
			&data->t_sol.s_screen.line_length, &data->t_sol.s_screen.endian);


	data->t_wall.dest = "./img/wall2.xpm";
	data->t_wall.img = mlx_xpm_file_to_image(data->mlx,
			data->t_wall.dest, &data->t_wall.img_width, &data->t_wall.img_heigth);
	if (!data->t_wall.img)
	{
		// ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->t_wall.s_screen.addr = mlx_get_data_addr(data->t_wall.img, &data->t_wall.s_screen.bits_per_pixel,
		&data->t_wall.s_screen.line_length, &data->t_wall.s_screen.endian);


	data->t_player.dest = "./img/player2.xpm";
	data->t_player.img = mlx_xpm_file_to_image(data->mlx,
			data->t_player.dest, &data->t_player.img_width, &data->t_player.img_heigth);
	if (!data->t_player.img)
	{
		// ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->t_player.s_screen.addr = mlx_get_data_addr(data->t_player.img, &data->t_player.s_screen.bits_per_pixel,
			&data->t_player.s_screen.line_length, &data->t_player.s_screen.endian);


	data->north.dest = "./img/n.xpm";
	data->north.img = mlx_xpm_file_to_image(data->mlx,
			data->north.dest, &data->north.img_width, &data->north.img_heigth);
	if (!data->north.img)
	{
		// ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->north.s_screen.addr = mlx_get_data_addr(data->north.img, &data->north.s_screen.bits_per_pixel,
			&data->north.s_screen.line_length, &data->north.s_screen.endian);


	data->south.dest = "./img/s.xpm";
	data->south.img = mlx_xpm_file_to_image(data->mlx,
			data->south.dest, &data->south.img_width, &data->south.img_heigth);
	if (!data->south.img)
	{
		// ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->south.s_screen.addr = mlx_get_data_addr(data->south.img, &data->south.s_screen.bits_per_pixel,
			&data->south.s_screen.line_length, &data->south.s_screen.endian);


	data->east.dest = "./img/e.xpm";
	data->east.img = mlx_xpm_file_to_image(data->mlx,
			data->east.dest, &data->south.img_width, &data->south.img_heigth);
	if (!data->east.img)
	{
		// ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->east.s_screen.addr = mlx_get_data_addr(data->east.img, &data->east.s_screen.bits_per_pixel,
			&data->east.s_screen.line_length, &data->east.s_screen.endian);



	data->west.dest = "./img/w.xpm";
	data->west.img = mlx_xpm_file_to_image(data->mlx,
			data->west.dest, &data->texture_width, &data->texture_heigth);
	if (!data->west.img)
	{
		// ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->west.s_screen.addr = mlx_get_data_addr(data->west.img, &data->west.s_screen.bits_per_pixel,
			&data->west.s_screen.line_length, &data->west.s_screen.endian);



	data->door_close.dest = "./img/door_close.xpm";
	data->door_close.img = mlx_xpm_file_to_image(data->mlx,
			data->door_close.dest, &data->texture_width, &data->texture_heigth);
	if (!data->door_close.img)
	{
		// ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->door_close.s_screen.addr = mlx_get_data_addr(data->door_close.img, &data->door_close.s_screen.bits_per_pixel,
			&data->door_close.s_screen.line_length, &data->door_close.s_screen.endian);


	data->door_open.dest = "./img/door_open2.xpm";
	data->door_open.img = mlx_xpm_file_to_image(data->mlx,
			data->door_open.dest, &data->texture_width, &data->texture_heigth);
	if (!data->door_open.img)
	{
		// ft_printf("Error\nXPM file invalid\n");
		on_destroy(data);
		exit(EXIT_FAILURE);
	}
	data->door_open.s_screen.addr = mlx_get_data_addr(data->door_open.img, &data->door_open.s_screen.bits_per_pixel,
			&data->door_open.s_screen.line_length, &data->door_open.s_screen.endian);
}

void set_img_anim(t_all *data)
{
	 static const char *paths[15] = {
      "./img/anim/anim1.xpm", "./img/anim/anim2.xpm",
        "./img/anim/anim3.xpm", "./img/anim/anim4.xpm", "./img/anim/anim5.xpm",
        "./img/anim/anim6.xpm", "./img/anim/anim7.xpm", "./img/anim/anim8.xpm",
        "./img/anim/anim9.xpm", "./img/anim/anim10.xpm", "./img/anim/anim11.xpm",
        "./img/anim/anim12.xpm", "./img/anim/anim13.xpm", "./img/anim/anim14.xpm", 
        "./img/anim/anim15.xpm"
       }; // tkt

	int i;

	i = 0;
	while (i < 15)
	{
		data->anim[i].dest = (char *)paths[i];
		data->anim[i].img = mlx_xpm_file_to_image(data->mlx,
			data->anim[i].dest,
			&data->anim[i].img_width,
			&data->anim[i].img_heigth);
		if (!data->anim[i].img)
		{
			printf("Prout %d\n", i);
			exit(12);
		}
        // if (!data->anim[i].img)
        // {
		// 	data->anim[i].s_screen.addr = NULL;
		// 	data->anim[i].img_width = 0;
		// 	data->anim[i].img_heigth = 0;
		// }
		// else
		// {
			data->anim[i].s_screen.addr = mlx_get_data_addr(data->anim[i].img,
				&data->anim[i].s_screen.bits_per_pixel,
				&data->anim[i].s_screen.line_length,
				&data->anim[i].s_screen.endian);
		// }
		i++;
	}
}


void	my_mlx_pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int ft_put_xpm_to_img(t_all *data, t_screen img, int x, int y)
{
	int i;
	int j;
	unsigned int	color;

	i = 0;
	j = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			// int check = (j * img.line_length + i * ( img.bits_per_pixel / 8));
			// if (check < 0 || (int)sizeof(unsigned int) > data->anim[i].img_width * data->anim[i].img_heigth)
			// 	color = 0;
			// else
			color = *(unsigned int*)(img.addr + (j * img.line_length + i * ( img.bits_per_pixel / 8)));
			my_mlx_pixel_put(data, x+i , y+j , color);
			j++;
		}
		i++;
	}
	return (0);
}


int ft_put_anim(t_all *data, t_sprite img, int x, int y)
{
	int i;
	int j;
	unsigned int	color;

	i = 0;
	j = 0;
	while (i < img.img_width)
	{
		j = 0;
		while (j < img.img_heigth)
		{
			// int check = (j * img.line_length + i * ( img.bits_per_pixel / 8));
			// if (check < 0 || (int)sizeof(unsigned int) > data->anim[i].img_width * data->anim[i].img_heigth)
			// 	color = 0;
			// else
			color = *(unsigned int*)(img.s_screen.addr + (j * img.s_screen.line_length + i * ( img.s_screen.bits_per_pixel / 8)));
			if (color != MASK_MAGENTA)
				my_mlx_pixel_put(data, x+i , y+j , color);
			j++;
		}
		i++;
	}
	return (0);
}

void ft_print_anim(t_all *data)
{

	static int frame = 0;

	// printf("test0:%d\n", frame);
	if (frame > 14)
	{
		frame = 0;
		data->shoot = 0;
		// printf("tes1:%d\n", frame);
	}
	if (data->shoot == 1)
	{
		// printf("test2:%d\n", frame);
		ft_put_anim(data, data->anim[frame], W - data->anim[frame].img_width -100,H - data->anim[frame].img_heigth);
		frame++;
	}
}

int ft_minimap_i(t_all *data)
{
	int i;

	if ((int)data->pos_player_y + MAP_SIZE_Y/2 > data->map_heigth)
	{
		if (data->map_heigth > MAP_SIZE_Y)
			i = data->map_heigth - MAP_SIZE_Y;
		else
			i = 0;
	}
	else if ((int)data->pos_player_y < MAP_SIZE_Y/2)
		i = 0;
	else
		i = (int)data->pos_player_y - MAP_SIZE_Y/2;
	return (i);
}

int ft_minimap_j(t_all *data)
{
	int j;

	if ((int)data->pos_player_x + MAP_SIZE_X/2 > data->map_length)
	{
		if (data->map_length > MAP_SIZE_X)
			j = data->map_length - MAP_SIZE_X;
		else
			j = 0;
	}
	else if ((int)data->pos_player_x < MAP_SIZE_X/2)
		j = 0;
	else
		j = (int)data->pos_player_x - MAP_SIZE_X/2;
	return (j);
}

void	ft_printf_map(t_all *data)
{
	int	i;
	int	j;
	int pixel_y;
	int pixel_x;

	i = ft_minimap_i(data);
	pixel_y = 0;
	while (data->map[i] && pixel_y < MAP_SIZE_Y)
	{
		j = ft_minimap_j(data);
		pixel_x = 0;
		while (data->map[i][j] && pixel_x < MAP_SIZE_X)
		{
			{
				if (data->map[i][j] == '0')
					ft_put_xpm_to_img(data, data->t_sol.s_screen, pixel_x * TILE_SIZE, pixel_y * TILE_SIZE);
				if (data->map[i][j] == '1')
					ft_put_xpm_to_img(data, data->t_wall.s_screen, pixel_x * TILE_SIZE, pixel_y * TILE_SIZE);
				if (data->map[i][j] == 'P')
					ft_put_xpm_to_img(data, data->t_player.s_screen, pixel_x * TILE_SIZE, pixel_y * TILE_SIZE);
			}
			pixel_x++;
			j++;
		}
		pixel_y++;
		i++;
	}
}

int ft_set_dir_2(t_all *data, char dir)
{
	if (dir == 'N')
	{
		data->dir_player_x = 0;
		data->dir_player_y = -1;
		data->plane_dir_x = 0.66;
		data->plane_dir_y = 0;
		return (0);
	}
	else if (dir == 'S')
	{
		data->dir_player_x = 0;
		data->dir_player_y = 1;
		data->plane_dir_x = -0.66;
		data->plane_dir_y = 0;
		return (0);
	}
	return (1);
}

int set_dir_player(t_all *data, char dir)
{
	if (ft_set_dir_2(data, dir) == 0)
		return (0);
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
	return (1);
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
				return (0);
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
		&& data->map[int_y][int_x] != '1' && data->map[int_y][int_x] != 'D')
		return(0);
	return (1);
}

int open_close_door(t_all *data)
{
		data->camera_x = 2 * 640 / (double)W - 1;
		data->ray_dir_x = data->dir_player_x + data->plane_dir_x * data->camera_x;
		data->ray_dir_y = data->dir_player_y + data->plane_dir_y * data->camera_x;

		data->player_pos_int_x = (int)data->pos_player_x;
		data->player_pos_int_y = (int)data->pos_player_y;

		if (data->ray_dir_x == 0)
			data->line_length_x = 1e30;
		else
			data->line_length_x = fabs(1 / data->ray_dir_x);
		if (data->ray_dir_y == 0)
			data->line_length_y = 1e30;
		else
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
		data->is_door = 0;
		while (data->contact == 0 && data->is_door == 0)
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
			if (data->map[data->player_pos_int_y][data->player_pos_int_x] == 'D')
			{
				if (data->wall == 0)
					data->wall_distance = (data->player_pos_int_x - data->pos_player_x + (1 - data->steps_x)/2) / data->ray_dir_x;
				else
					data->wall_distance = (data->player_pos_int_y - data->pos_player_y + (1 - data->steps_y)/2) / data->ray_dir_y;
				if (data->wall_distance < 3)
					data->map[data->player_pos_int_y][data->player_pos_int_x] = 'O';
			}
			else if (data->map[data->player_pos_int_y][data->player_pos_int_x] == 'O')
			{
				if (data->wall == 0)
					data->wall_distance = (data->player_pos_int_x - data->pos_player_x + (1 - data->steps_x)/2) / data->ray_dir_x;
				else
					data->wall_distance = (data->player_pos_int_y - data->pos_player_y + (1 - data->steps_y)/2) / data->ray_dir_y;
				if (data->wall_distance < 3)
					data->map[data->player_pos_int_y][data->player_pos_int_x] = 'D';
			}
		}
		return 0;
}

void ft_move_player_x(t_all *data)
{
	if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == 'P')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
	else if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == 'Q')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'O';
	data->pos_player_x = data->temp_x;
	if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == '0')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
	else if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == 'O')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'Q';
}

void ft_move_player_y(t_all *data)
{
	if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == 'P')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = '0';
	else if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == 'Q')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'O';
	data->pos_player_y = data->temp_y;
	if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == '0')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'P';
	else if (data->map[(int)data->pos_player_y][(int)data->pos_player_x] == 'O')
		data->map[(int)data->pos_player_y][(int)data->pos_player_x] = 'Q';
}

int move_forward(t_all *data)
{
	data->temp_x = data->pos_player_x + data->dir_player_x * MS;
	data->temp_y = data->pos_player_y + data->dir_player_y * MS;
	if (check_collision(data, data->temp_x, data->pos_player_y) == 0)
	{
		ft_move_player_x(data);
	}
	if (check_collision(data, data->pos_player_x, data->temp_y) == 0)
	{
		ft_move_player_y(data);
	}
	return (0);
}

int move_backward(t_all *data)
{
	data->temp_x = data->pos_player_x - data->dir_player_x * MS;
	data->temp_y = data->pos_player_y - data->dir_player_y * MS;
	if (check_collision(data, data->temp_x, data->pos_player_y) == 0)
	{
		ft_move_player_x(data);
	}
	if (check_collision(data, data->pos_player_x, data->temp_y) == 0)
	{
		ft_move_player_y(data);
	}
	return (0);
}

int move_left(t_all *data)
{
	data->temp_x = data->pos_player_x - data->plane_dir_x * MS;
	data->temp_y = data->pos_player_y - data->plane_dir_y * MS;
	if (check_collision(data, data->temp_x, data->pos_player_y) == 0)
	{
		ft_move_player_x(data);
	}
	if (check_collision(data, data->pos_player_x, data->temp_y) == 0)
	{
		ft_move_player_y(data);
	}
	return (0);
}

int move_right(t_all *data)
{
	data->temp_x = data->pos_player_x + data->plane_dir_x * MS;
	data->temp_y = data->pos_player_y + data->plane_dir_y * MS;
	if (check_collision(data, data->temp_x, data->pos_player_y) == 0)
	{
		ft_move_player_x(data);
	}
	if (check_collision(data, data->pos_player_x, data->temp_y) == 0)
	{
		ft_move_player_y(data);
	}
	return (0);
}

int rotate_left(t_all *data)
{
	double temp;

	temp = data->dir_player_x;
	data->dir_player_x = data->dir_player_x * cos(-ROTATE) - data->dir_player_y * sin(-ROTATE);
	data->dir_player_y = temp * sin(-ROTATE) + data->dir_player_y * cos(-ROTATE);

	temp = data->plane_dir_x;
	data->plane_dir_x = data->plane_dir_x * cos(-ROTATE) - data->plane_dir_y * sin(-ROTATE);
	data->plane_dir_y = temp * sin(-ROTATE) + data->plane_dir_y * cos(-ROTATE);
	return (0);
}

int rotate_right(t_all *data)
{
	double temp;

	temp = data->dir_player_x;
	data->dir_player_x = data->dir_player_x * cos(ROTATE) - data->dir_player_y * sin(ROTATE);
	data->dir_player_y = temp * sin(ROTATE) + data->dir_player_y * cos(ROTATE);

	temp = data->plane_dir_x;
	data->plane_dir_x = data->plane_dir_x * cos(ROTATE) - data->plane_dir_y * sin(ROTATE);
	data->plane_dir_y = temp * sin(ROTATE) + data->plane_dir_y * cos(ROTATE);
	return (0);
}

int	on_keypress(int keysym, t_all *data)
{
	// printf("key:%d\n", keysym);
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
		data->move_x = 0;
	else if (keysym == KEY_S)
		data->move_x =0;
	else if (keysym == KEY_A)
		data->move_y = 0;
	else if (keysym == KEY_D)
		data->move_y = 0;
	else if (keysym == KEY_LEFT)
		data->rotate = 0;
	else if (keysym == KEY_RIGHT)
		data->rotate = 0;
	return (0);
}

int ft_move(t_all *data)
{
	static int fps = 0;
	// static long last;
	long now = get_time_ms();
	// last = now;

	long elapsed = now - data->start_time;
	if (elapsed >= 22)
	{
		data->start_time = now;
		fps++;

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

	// printf("time:%ld\n", (get_time_ms() - data->start_time));

	// ft_printf_map(data);
	raycasting(data);
	ft_printf_map(data);
	ft_print_anim(data);

	mlx_put_image_to_window(data->mlx, data->mlx_win_2, data->img.img, 0, 0);
	}
	// else
	// {
	// 	long wait_ms = 30 - elapsed;
	// 	if (wait_ms > 0)
	// 		ft_usleep(wait_ms * 1000);
	// }
	return (0);
}

void raycasting(t_all *data)
{
	int pos = 0;

	pos = 0;
	while (pos < W)
	{
		data->camera_x = 2 * pos / (double)W - 1;
		data->ray_dir_x = data->dir_player_x + data->plane_dir_x * data->camera_x;
		data->ray_dir_y = data->dir_player_y + data->plane_dir_y * data->camera_x;

		data->player_pos_int_x = (int)data->pos_player_x;
		data->player_pos_int_y = (int)data->pos_player_y;

		if (data->ray_dir_x == 0)
			data->line_length_x = 1e30;
		else
			data->line_length_x = fabs(1 / data->ray_dir_x);
		if (data->ray_dir_y == 0)
			data->line_length_y = 1e30;
		else
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
		data->is_door = 0;
		while (data->contact == 0 && data->is_door == 0)
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
				break;

			if (data->map[data->player_pos_int_y][data->player_pos_int_x] == '1')
				data->contact = 1;

			if (data->map[data->player_pos_int_y][data->player_pos_int_x] == 'O')
				data->is_door = 2;

			if (data->map[data->player_pos_int_y][data->player_pos_int_x] == 'D')
				data->is_door = 1;

		}
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
		if (data->wall == 0)
		{
			// data->ratio = (data->distance_x / data->dir_player_y) - (int)data->player_pos_int_x;
			// data->ratio = (data->distance_y / data->dir_player_x) - (int)data->distance_x;
			data->ratio = data->pos_player_y + data->wall_distance * data->ray_dir_y;
		}
		else
		{
			// data->ratio = (data->distance_y / data->dir_player_x) - (int)data->player_pos_int_y;
			// data->ratio = (data->distance_y / data->dir_player_x) - (int)data->distance_y;
			data->ratio = data->pos_player_x + data->wall_distance * data->ray_dir_x;
		}
		data->ratio -= floor(data->ratio);

		int texture_x = (int)((1 - data->ratio) * (double)TEXTURE_SIZE);

		if ((data->wall == 0 && data->ray_dir_x > 0) || (data->wall == 1 && data->ray_dir_y < 0))
            texture_x = TEXTURE_SIZE - texture_x - 1;

        if (data->ray_dir_x == 0)
        	texture_x = (int)((0.1) * (double)TEXTURE_SIZE);

        double pixel_ratio = (double)TEXTURE_SIZE / data->line_height;
        double texture_pos = (data->texture_start - (H /2) + (data->line_height / 2)) * pixel_ratio;

		while (y < data->texture_end)
		{
			int texture_y = (int)texture_pos % TEXTURE_SIZE;
			texture_pos += pixel_ratio;
			color = 0;

			//crosshair
			if (pos > W/2 -3 && pos < W/2+3 && y > H/2-3 && y < H/2+3)
			{
				color = 0x0AFF0E;
			}
			else if (data->is_door == 1)
			{
				color = *(unsigned int*)(data->door_close.s_screen.addr + (texture_y * data->door_close.s_screen.line_length + texture_x * ( data->door_close.s_screen.bits_per_pixel / 8)));
			}
			else if (data->is_door == 2)
			{

				color = *(unsigned int*)(data->door_open.s_screen.addr + (texture_y * data->door_open.s_screen.line_length + texture_x * ( data->door_open.s_screen.bits_per_pixel / 8)));
				if (color == MASK_MAGENTA)
				{
					color = 0xFFFFFF;

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
						if (data->map[data->player_pos_int_y][data->player_pos_int_x] == 'D')
							data->contact = 2;
						if (data->map[data->player_pos_int_y][data->player_pos_int_x] == 'O')
							data->contact = 3;
					}
					if (data->wall == 0)
					{
						data->wall_distance = (data->player_pos_int_x - data->pos_player_x + (1 - data->steps_x)/2) / data->ray_dir_x;
					}
					else
					{
						data->wall_distance = (data->player_pos_int_y - data->pos_player_y + (1 - data->steps_y)/2) / data->ray_dir_y;
					}

					// int temp_line_height = (int)H / data->wall_distance;
					int temp_dist = (int)H / data->wall_distance;
					int temp_start = (H /2) - (temp_dist / 2);
					if (temp_start < 0)
						temp_start = 0;

					int temp_end =  (H /2) + (temp_dist / 2);
					if (temp_end >= H)
						temp_end = H - 1;

					if (data->wall == 0)
						data->ratio = data->pos_player_y + data->wall_distance * data->ray_dir_y;
					else if (data->wall == 1)
						data->ratio = data->pos_player_x + data->wall_distance * data->ray_dir_x;

					data->ratio -= floor(data->ratio);

					int temp_texture_x = (int)((1 - data->ratio) * (double)TEXTURE_SIZE);

					if ((data->wall == 0 && data->ray_dir_x > 0) || (data->wall == 1 && data->ray_dir_y < 0))
			            temp_texture_x = TEXTURE_SIZE - temp_texture_x - 1;

			        if (data->ray_dir_x == 0)
			        	temp_texture_x = (int)((0.1) * (double)TEXTURE_SIZE);

			        double temp_pixel_ratio = (double)TEXTURE_SIZE / temp_dist;
			        double temp_texture_pos = (temp_start - (H /2) + (temp_dist / 2)) * temp_pixel_ratio;

			        // int temp_texture_y = (int)temp_texture_pos % TEXTURE_SIZE;

					temp_texture_pos = temp_texture_pos + (temp_pixel_ratio * (y - temp_start) );
					int temp_texture_y = (int)temp_texture_pos % TEXTURE_SIZE;

					if (y < temp_start)
						color = 8900331;
					else if (y > temp_end)
						color = 3100463;
					else if (data->contact == 2)
						color = *(unsigned int*)(data->door_close.s_screen.addr + (temp_texture_y * data->door_close.s_screen.line_length + temp_texture_x * ( data->door_close.s_screen.bits_per_pixel / 8)));
					else if (data->contact == 3)
						color = *(unsigned int*)(data->door_open.s_screen.addr + (temp_texture_y * data->door_open.s_screen.line_length + temp_texture_x * ( data->door_open.s_screen.bits_per_pixel / 8)));
					else if (data->wall == 1 && data->ray_dir_y > 0)
						color = *(unsigned int*)(data->south.s_screen.addr + (temp_texture_y * data->south.s_screen.line_length + temp_texture_x * ( data->south.s_screen.bits_per_pixel / 8)));
					else if (data->wall == 1 && data->ray_dir_y < 0)
						color = *(unsigned int*)(data->north.s_screen.addr + (temp_texture_y * data->north.s_screen.line_length + temp_texture_x * ( data->north.s_screen.bits_per_pixel / 8)));
					else if (data->wall == 0 && data->ray_dir_x > 0)
						color = *(unsigned int*)(data->east.s_screen.addr + (temp_texture_y * data->east.s_screen.line_length + temp_texture_x * ( data->east.s_screen.bits_per_pixel / 8)));
					else if (data->wall == 0 && data->ray_dir_x < 0)
						color = *(unsigned int*)(data->west.s_screen.addr + (temp_texture_y * data->west.s_screen.line_length + temp_texture_x * ( data->west.s_screen.bits_per_pixel / 8)));
				}
			}
			else if (data->wall == 1 && data->ray_dir_y > 0)
				color = *(unsigned int*)(data->south.s_screen.addr + (texture_y * data->south.s_screen.line_length + texture_x * ( data->south.s_screen.bits_per_pixel / 8)));
			else if (data->wall == 1 && data->ray_dir_y < 0)
				color = *(unsigned int*)(data->north.s_screen.addr + (texture_y * data->north.s_screen.line_length + texture_x * ( data->north.s_screen.bits_per_pixel / 8)));
			else if (data->wall == 0 && data->ray_dir_x > 0)
				color = *(unsigned int*)(data->east.s_screen.addr + (texture_y * data->east.s_screen.line_length + texture_x * ( data->east.s_screen.bits_per_pixel / 8)));
			else if (data->wall == 0 && data->ray_dir_x < 0)
				color = *(unsigned int*)(data->west.s_screen.addr + (texture_y * data->west.s_screen.line_length + texture_x * ( data->west.s_screen.bits_per_pixel / 8)));
			my_mlx_pixel_put(data, pos, y, color);
			y++;
		}
		while (y < H)
		{
			my_mlx_pixel_put(data, pos, y, 3100463);
			y++;
		}
		pos++;
	}
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
	t_all data;

	if (argc == 2)
	{
		data.map = ft_open_map(&data, argv[1]);
		if (set_pos_player(&data) == -1)
			return (1);
		data.start_time = get_time_ms();
		data.check_door = 0;
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

		data.move_x = 0;
		data.move_y = 0;
		data.rotate = 0;

		data.shoot = 0;
		set_img(&data);
		set_img_anim(&data);

		mlx_hook(data.mlx_win_2, 2, 1L<<0, &on_keypress, &data);
		mlx_hook(data.mlx_win_2, 3, 1L<<1, &on_keyrelease, &data);
		mlx_loop_hook(data.mlx, &ft_move, &data);
		// mlx_hook(data.mlx_win_2, 2 , 1L<<0,&on_keypress_side, &data);
		// mlx_key_hook(data.mlx_win, &on_keypress, &data);
		mlx_hook(data.mlx_win_2, DestroyNotify,
			StructureNotifyMask, &on_destroy, &data);

	
		// mlx_hook(data.mlx_win_2, 6, 1L<<0, &ft_mouse, &data);


		raycasting(&data);
		ft_printf_map(&data);

		// mlx_mouse_hide(data.mlx, data.mlx_win_2);
		// mlx_mouse_show(data.mlx, data.mlx_win_2);
		// mlx_loop_hook(data.mlx, &ft_mouse, &data);
// 
		mlx_loop(data.mlx);
	}
}