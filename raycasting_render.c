/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:33:51 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:33:52 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_sprite ft_get_texture_x(t_all *data, t_ratio *r1)
{
	(void)r1;

	t_sprite temp;

	temp = (t_sprite){0};
	if (data->contact == 2 || data->is_door == 1)
		temp = data->door_close;
	else if (data->contact == 3 || data->is_door == 2)
		temp = data->door_open;
	else if (data->wall == 1 && data->ray_dir_y > 0)
		temp = data->south;
	else if (data->wall == 1 && data->ray_dir_y < 0)
		temp = data->north;
	else if (data->wall == 0 && data->ray_dir_x > 0)
		temp = data->east;
	else if (data->wall == 0 && data->ray_dir_x < 0)
		temp = data->west;
	return (temp);
}

void	ft_calculate_sprite_ratio(t_all *data, t_ratio *r1)
{
	t_sprite temp;

	(void)r1;
	if (data->wall == 0)
		data->ratio = data->pos_player_y
			+ data->wall_distance * data->ray_dir_y;
	else
		data->ratio = data->pos_player_x
			+ data->wall_distance * data->ray_dir_x;
	data->ratio -= floor(data->ratio);
	temp = ft_get_texture_x(data, r1);
	r1->texture_x = (int)((1 - data->ratio) * (double)temp.img_width);
	if ((data->wall == 0 && data->ray_dir_x > 0)
		|| (data->wall == 1 && data->ray_dir_y < 0))
		r1->texture_x = temp.img_width - r1->texture_x - 1;
	if (data->ray_dir_x == 0)
		r1->texture_x = (int)((0.1) * (double)temp.img_width);

	// if (r1->texture_x < 0)
	// 	r1->texture_x = 0;
    // if (r1->texture_x >= temp.img_width)
	// 	r1->texture_x = temp.img_width - 1;
	r1->pixel_ratio = (double)temp.img_heigth / (double)r1->dist;
	r1->texture_pos = (r1->start - (H / 2) + ((double)r1->dist / 2)) * r1->pixel_ratio;
}

void	ft_pick_pixel_color(t_all *data, unsigned int *color,
		t_sprite ref, t_ratio *r1)
{
	(void)data;
	r1->texture_y = (int)(r1->texture_pos) % ref.img_heigth;
	*color = *(unsigned int *)(ref.s_screen.addr
			+ (r1->texture_y * ref.s_screen.line_length
				+ r1->texture_x * (ref.s_screen.bits_per_pixel / 8)));
}

void	ft_get_color(t_all *data, int y, int pos, unsigned int *color)
{
	if (pos > W / 2 - 3 && pos < W / 2 + 3 && y > H / 2 - 3 && y < H / 2 + 3)
	{
		*color = 0x0AFF0E;
	}
	else if (data->is_door == 1)
		ft_pick_pixel_color(data, color, data->door_close, &data->r1);
	else if (data->is_door == 2)
	{
		ft_pick_pixel_color(data, color, data->door_open, &data->r1);
		if (*color == MASK_MAGENTA)
		{
			double saved_texture_pos = data->r1.texture_pos;
			ft_render_door(data, y, color);
			data->r1.texture_pos = saved_texture_pos;
		}
	}
	else if (data->wall == 1 && data->ray_dir_y > 0)
		ft_pick_pixel_color(data, color, data->south, &data->r1);
	else if (data->wall == 1 && data->ray_dir_y < 0)
		ft_pick_pixel_color(data, color, data->north, &data->r1);
	else if (data->wall == 0 && data->ray_dir_x > 0)
		ft_pick_pixel_color(data, color, data->east, &data->r1);
	else if (data->wall == 0 && data->ray_dir_x < 0)
		ft_pick_pixel_color(data, color, data->west, &data->r1);
}

void	ft_render_image(t_all *data, int pos)
{
	int				y;
	unsigned int	color;

	y = 0;
	while (y < data->r1.start)
		my_mlx_pixel_put(data, pos, y++, 8900331);
	ft_calculate_sprite_ratio(data, &data->r1);
	while (y < data->r1.end)
	{
		data->r1.texture_pos += data->r1.pixel_ratio;
		ft_get_color(data, y, pos, &color);
		my_mlx_pixel_put(data, pos, y++, color);
	}
	while (y < H)
		my_mlx_pixel_put(data, pos, y++, 3100463);
}
