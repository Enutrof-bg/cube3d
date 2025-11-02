/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:17:24 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:17:25 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	raycasting(t_all *data)
{
	int	pos;

	pos = 0;
	while (pos < W)
	{
		ft_calculate_ray(data, pos);
		ft_calculate_distance(data);
		ft_algo_dda(data);
		ft_calculate_distance_wall(data, &data->r1);
		ft_render_image(data, pos);
		pos++;
	}
}
