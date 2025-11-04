/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:21:12 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:21:12 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	my_mlx_pixel_put(t_all *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= W || y < 0 || y >= H)
		return ;
	dst = data->img.addr + (y * data->img.line_length + x
			* (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_put_xpm_to_img(t_all *data, t_screen img, int x, int y)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	j = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			color = *(unsigned int *)(img.addr + (j * img.line_length
						+ i * (img.bits_per_pixel / 8)));
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}
