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

# define TILE_SIZE 32

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define KEY_ESC 65307

# define DEG_TO_RAD(deg) ((deg) * M_PI / 180.0)

typedef struct s_list
{
	double pos_player_x;
	double pos_player_y;
	char **map;

	int dir_player_x;
	int dir_player_y;

	int angle_player;
	int rotate_speed;

	void *mlx;
	void *mlx_win;

	int map_length;
	int map_heigth;

	int img_width;
	int img_heigth;

	void *img_sol;
	char *dest_sol;

	void *img_wall;
	char *dest_wall;

	void *img_player;
	char *dest_player;

	long start_time;
	long frame_time;


}t_all;

char	**ft_open_map(t_all *data, char *filename);
char	*ft_itoa(int n);
char	**ft_split(char *s, char c);
// char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);

#endif
