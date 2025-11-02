/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_door.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:37:50 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:37:51 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_render_door_recursive(t_all *data, int y,
		unsigned int *color, int *recursive)
{
	(*recursive)++;
	data->contact = 0;
	ft_render_door(data, y, color);
	(*recursive)--;
}

void	ft_render_door_color(t_all *data, int y,
		t_ratio *r, unsigned int *color)
{
	static int	recursive = 0;

	r->texture_pos = r->texture_pos + (r->pixel_ratio * (y - r->start));
	r->texture_y = (int)r->texture_pos % TEXTURE_SIZE;
	if (y < r->start)
		*color = 8900331;
	else if (y > r->end)
		*color = 3100463;
	else if (data->contact == 2)
		ft_pick_pixel_color(data, color, data->door_close, *r);
	else if (data->contact == 3)
	{
		ft_pick_pixel_color(data, color, data->door_open, *r);
		if (*color == MASK_MAGENTA && recursive < 5)
			ft_render_door_recursive(data, y, color, &recursive);
	}
	else if (data->wall == 1 && data->ray_dir_y > 0)
		ft_pick_pixel_color(data, color, data->south, *r);
	else if (data->wall == 1 && data->ray_dir_y < 0)
		ft_pick_pixel_color(data, color, data->north, *r);
	else if (data->wall == 0 && data->ray_dir_x > 0)
		ft_pick_pixel_color(data, color, data->east, *r);
	else if (data->wall == 0 && data->ray_dir_x < 0)
		ft_pick_pixel_color(data, color, data->west, *r);
}

void	ft_dda_continue_door(t_all *data)
{
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
		if (data->player_pos_int_x < 0 || data->player_pos_int_y < 0
			|| data->player_pos_int_x >= data->map_length
			|| data->player_pos_int_y >= data->map_heigth)
			break ;
		if (data->map[data->player_pos_int_y][data->player_pos_int_x] == '1')
			data->contact = 1;
		if (data->map[data->player_pos_int_y][data->player_pos_int_x] == 'D')
			data->contact = 2;
		if (data->map[data->player_pos_int_y][data->player_pos_int_x] == 'O')
			data->contact = 3;
	}
}

void	ft_render_door(t_all *data, int y, unsigned int *color)
{
	t_ratio	r;
	t_save	save;

	save.saved_pos_x = data->player_pos_int_x;
	save.saved_pos_y = data->player_pos_int_y;
	save.saved_dist_x = data->distance_x;
	save.saved_dist_y = data->distance_y;
	save.saved_wall = data->wall;
	save.saved_contact = data->contact;
	ft_dda_continue_door(data);
	if (data->contact != 0)
	{
		ft_calculate_distance_wall(data, &r);
		ft_calculate_sprite_ratio(data, &r);
		ft_render_door_color(data, y, &r, color);
	}
	data->player_pos_int_x = save.saved_pos_x;
	data->player_pos_int_y = save.saved_pos_y;
	data->distance_x = save.saved_dist_x;
	data->distance_y = save.saved_dist_y;
	data->wall = save.saved_wall;
	data->contact = save.saved_contact;
}
