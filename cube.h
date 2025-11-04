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
# define CUBE_H

// # define _USE_MATH_DEFINES

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
// # include "gnl/get_next_line.h"
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

# include "ft_printf/ft_printf.h"
# include "parsing/includes/cub3d.h"
# include "parsing/includes/get_next_line.h"

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

# define MS 0.2
# define ROTATE 0.03

// # define TEXTURE_SIZE 64
# define MAP_SIZE_X 40
# define MAP_SIZE_Y 40

# define MASK_MAGENTA 0xD84CE6

// # define DEG_TO_RAD(deg) ((deg) * M_PI / 180.0)

typedef struct s_cub
{
	char	**file;
	char	**map;
	char	**info_map;
	int		line_info;
	int		line_total;

	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
	char	*floor;
	char	*celling;
}t_cub;

typedef struct s_sreen
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}t_screen;

typedef struct s_sprite
{
	void		*img;
	char		*dest;
	int			img_width;
	int			img_heigth;
	t_screen	s_screen;
}t_sprite;

typedef struct s_ratio
{
	int			texture_x;
	int			texture_y;
	double		texture_pos;
	double		pixel_ratio;
	int			dist;
	int			start;
	int			end;
}t_ratio;

typedef struct s_save
{
	int			saved_pos_x;
	int			saved_pos_y;
	double		saved_dist_x;
	double		saved_dist_y;
	int			saved_wall;
	int			saved_contact;
}t_save;

typedef struct s_list
{
	int			ceiling;
	int			floor;

	t_cub		cub;

	t_sprite	anim[15];
	t_ratio		r1;
	double		pos_player_x;
	double		pos_player_y;
	char		**map;

	double		dir_player_x;
	double		dir_player_y;

	double		plane_dir_x;
	double		plane_dir_y;

	int			angle_player;
	int			rotate_speed;

	void		*mlx;
	void		*mlx_win;
	void		*mlx_win_2;

	int			map_length;
	int			map_heigth;

	int			img_width;
	int			img_heigth;

	int			texture_width;
	int			texture_heigth;

	t_sprite	t_sol;
	t_sprite	t_wall;
	t_sprite	t_player;
	t_sprite	north;
	t_sprite	south;
	t_sprite	east;
	t_sprite	west;
	t_sprite	door_close;
	t_sprite	door_open;

	long		start_time;
	long		frame_time;

	t_screen	img;
	t_screen	minimap;

	double		camera_x;

	double		ray_dir_x;
	double		ray_dir_y;

	double		line_length_x;
	double		line_length_y;

	int			steps_x;
	int			steps_y;

	double		distance_x;
	double		distance_y;

	int			player_pos_int_x;
	int			player_pos_int_y;

	int			wall;
	int			contact;

	double		wall_distance;
	double		texture_start;
	double		texture_end;
	double		line_height;

	double		ratio;
	double		ratio_pixel;

	int			mouse_x;
	int			mouse_y;

	double		temp_x;
	double		temp_y;

	int			check_door;
	int			is_door;

	int			move_x;
	int			move_y;
	int			rotate;

	int			shoot;

	int			pixel_x;
	int			pixel_y;
}t_all;

// char	**ft_open_map_2(t_all *data, char *filename);
char	*ft_itoa(int n);
// char	**ft_split(char *s, char c);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strdup(const char *s1);

//ft_free.c
int		on_destroy(t_all *data);
int		ft_destroy_image(t_all *data);
int		ft_destroy_image_anim(t_all *data);
void	free_map(t_all *data);
void	ft_clean_mlx(t_all *data);

//ft_print_debug.c
void	print_data(t_all *data);

//init_.c
void	ft_set_null(t_all *data);
void	ft_set_img_path(t_all *data);
int		set_img(t_all *data);

//init_texture_door.c
int		ft_set_img_door_close(t_all *data);
int		ft_set_img_door_open(t_all *data);

//init_texture_wall.c
int		ft_set_img_north(t_all *data);
int		ft_set_img_south(t_all *data);
int		ft_set_img_east(t_all *data);
int		ft_set_img_west(t_all *data);

//init_texture_minimap.c
int		ft_set_img_sol(t_all *data);
int		ft_set_img_wall(t_all *data);
int		ft_set_img_player(t_all *data);

//init_texture_anim.c
void	set_img_anim(t_all *data);

//init_value.c
void	ft_init_value(t_all *data);

//ft_time.c
long	get_time_ms(void);
long	get_time_micro(void);
void	ft_usleep(long usec);

//hook.c
int		on_keypress(int keysym, t_all *data);
int		on_keyrelease(int keysym, t_all *data);
int		ft_move(t_all *data);
void	all_hook(t_all *data);
//init_dir.c
int		set_pos_player(t_all *data);
int		set_dir_player(t_all *data, char dir);
int		ft_set_dir_2(t_all *data, char dir);

//ft_minimap.c
void	ft_printf_map(t_all *data);
int		ft_minimap_i(t_all *data);
int		ft_minimap_j(t_all *data);

//movement.c
int		move_forward(t_all *data);
int		move_backward(t_all *data);
int		move_left(t_all *data);
int		move_right(t_all *data);

//movement_rotate.c
int		rotate_left(t_all *data);
int		rotate_right(t_all *data);

//movement_side.c
void	ft_move_player_x(t_all *data);
void	ft_move_player_y(t_all *data);
int		check_collision(t_all *data, double new_x, double new_y);

//open_door.c
int		open_close_door(t_all *data);

//print_pixel.c
void	my_mlx_pixel_put(t_all *data, int x, int y, int color);
int		ft_put_xpm_to_img(t_all *data, t_screen img, int x, int y);

//print_anim.c
int		ft_put_anim(t_all *data, t_sprite img, int x, int y);
void	ft_print_anim(t_all *data);

//raycasting.c
void	raycasting(t_all *data);

//raycasting_calculate.c
void	ft_calculate_ray(t_all *data, int pos);
void	ft_calculate_distance(t_all *data);
void	ft_algo_dda(t_all *data);
void	ft_calculate_distance_wall(t_all *data, t_ratio *r1);

//raycasting_render.c
void	ft_calculate_sprite_ratio(t_all *data, t_ratio *r1);
void	ft_render_image(t_all *data, int pos);
void	ft_get_color(t_all *data, int y, int pos, unsigned int *color);
// void	ft_pick_pixel_color(t_all *data, unsigned int *color,
// 			t_sprite ref, t_ratio r1);
void	ft_pick_pixel_color(t_all *data, unsigned int *color,
			t_sprite ref, t_ratio *r1);

//raycasting_door.c
void	ft_render_door(t_all *data, int y, unsigned int *color);
void	ft_dda_continue_door(t_all *data);

int		on_mouse(int x, int y, t_all *data);
int		ft_mouse(t_all *data);

int		ft_open_map(t_all *data, char *filename);

//parsing_map
bool	load_and_check(t_cub *cub);
bool	check_general(t_cub *cub);

//parsing_map_char
bool	floor_celling(char c);
bool	player_char(char c);
bool	check_map_char(t_cub *cub);
bool	valid_char(char c);

//utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		double_tab_lenght(char **tab);
int		ft_atoi(char *str);
int		nb_line_info(char **file, t_cub *cub);
int		nb_line(char *file, t_cub *cub);

//check_valid_map
bool	check_zero_leak(t_cub *cub);
bool	check_sides(t_cub *cub);
bool	check_map_spaces(t_cub *cub);
bool	check_map(t_cub *cub);
bool	check_map_2(char *str);

//parsing_colours
bool	check_numbers(int *tab);
bool	check_rgb_str(char *str);
int		check_rgb_str_2(t_cub *cub);
void	ft_check_colours_1(t_cub *cub);
void	ft_check_colours_2(t_cub *cub);

//check_valid_map_2
int		fill_floor_celling(int index, char *file, t_cub *cub);
void	fill_floor_celling_2(t_cub *cub, int index, char *line);
char	*skip_space(char *str);
int		is_valid(char *file);
bool	check_name(char *file);

//check_valid_map_3
void	check_valide_space_2(t_cub **cub, int i, int j, int k);
void	check_valid_space(t_cub **cub, int f);

//parsing_directions
void	fill_direction_2(t_cub *cub, int index, char *line);
int		fill_direction(int index, char *file, t_cub *cub);
int		directions_texture(char **file, t_cub *cub);

//parsing_loading_map
char	**load_file(char *file, t_cub *cub);
char	**load_info(char **file, t_cub *cub);
char	**load_map(char **file, t_cub *cub);

//free
void	ft_free_tab(char **tab);
void	ft_free_all(t_cub *cub);
void	ft_free_all_2(t_cub *cub);
void	ft_free_all_3(t_cub *cub);

//init
int		init_all(t_cub *cub);

int		ft_count_word(char const *s, char c);
char	*ft_malloc(char const *s, int start, int end);
char	**ft_split(char const *s, char c);
void	ft_free_all_split(char **tab, int last);
int		extern_loop(const char *s, int i, char c, int flag);

#endif
