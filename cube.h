/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:18:27 by kevwang           #+#    #+#             */
/*   Updated: 2025/10/27 11:18:29 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

// # define _USE_MATH_DEFINES

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>
# include <math.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define TILE_SIZE 4

# define W 1280
# define H 720

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define KEY_E 101

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define KEY_ESC 65307

# define MS 1
# define ROTATE 0.05

# define TEXTURE_SIZE 256
# define MAP_SIZE_X 40
# define MAP_SIZE_Y 40

# define DEG_TO_RAD(deg) ((deg) * M_PI / 180.0)

typedef struct s_sreen
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;

}t_screen;

typedef struct s_list
{
	double pos_player_x;
	double pos_player_y;
	char **map;

	double dir_player_x;
	double dir_player_y;

	double plane_dir_x;
	double plane_dir_y;

	int angle_player;
	int rotate_speed;

	void *mlx;
	void *mlx_win;
	void *mlx_win_2;

	int map_length;
	int map_heigth;

	int img_width;
	int img_heigth;

	int texture_width;
	int texture_heigth;

	void *img_sol;
	char *dest_sol;
	t_screen sol_s;

	void *img_wall;
	char *dest_wall;
	t_screen wall_s;

	void *img_player;
	char *dest_player;
	t_screen player_s;

	void *img_n;
	char *dest_n;
	t_screen n;

	void *img_s;
	char *dest_s;
	t_screen s;

	void *img_e;
	char *dest_e;
	t_screen e;

	void *img_w;
	char *dest_w;
	t_screen w;

	void *img_door_close;
	char *dest_door_close;
	t_screen door_close;

	void *img_door_open;
	char *dest_door_open;
	t_screen door_open;


	long start_time;
	long frame_time;

	t_screen img;
	t_screen minimap;

	double camera_x;

	double ray_dir_x;
	double ray_dir_y;
	
	double line_length_x;
	double line_length_y;

	int steps_x;
	int steps_y;

	double distance_x;
	double distance_y;

	int player_pos_int_x;
	int player_pos_int_y;

	int wall;
	int contact;

	double wall_distance;
	double texture_start;
	double texture_end;
	double line_height;

	double ratio;
	double ratio_pixel;

	int mouse_x;
	int mouse_y;

	double temp_x;
	double temp_y;

	int check_door;
	int is_door;

	int move_x;
	int move_y;
	int rotate;
}t_all;

char	**ft_open_map(t_all *data, char *filename);
char	*ft_itoa(int n);
char	**ft_split(char *s, char c);
// char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);

#endif
