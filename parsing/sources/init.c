/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:08:43 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/02 16:55:21 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_all(t_cub *cub)
{
	cub->file = NULL;
	cub->info_map = NULL;
	cub->line_info = 0;
	cub->line_total = 0;
	cub->map = NULL;
	cub->ea = NULL;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->celling = NULL;
	cub->floor = NULL;
	return (1);
}
