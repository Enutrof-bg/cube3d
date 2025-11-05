/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:23:20 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:23:22 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_put_anim(t_all *data, t_sprite img, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	j = 0;
	while (i < img.img_width)
	{
		j = 0;
		while (j < img.img_heigth)
		{
			color = *(unsigned int *)(img.s_screen.addr
					+ (j * img.s_screen.line_length + i
						* (img.s_screen.bits_per_pixel / 8)));
			if (color != MASK_MAGENTA)
				my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_print_anim(t_all *data)
{
	static int	frame = 0;
	int			anim_x;

	anim_x = W / 2 + data->anim[frame].img_width;
	if (frame > 14)
	{
		frame = 0;
		data->shoot = 0;
	}
	if (data->shoot == 1)
	{
		if (anim_x > W || anim_x < 0
			|| data->anim[frame].img_heigth > H)
			return ;
		ft_put_anim(data, data->anim[frame],
			anim_x, H - data->anim[frame].img_heigth);
		if (data->elapsed_time > 60)
		{
			data->frame_time = data->now;
			frame++;
		}
			
	}
}
