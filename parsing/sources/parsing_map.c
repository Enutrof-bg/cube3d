/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:30 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/05 17:02:48 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

bool	load_and_check(t_cub *cub);
bool	check_general(t_cub *cub);

bool	load_and_check(t_cub *cub)
{
	cub->info_map = load_info(cub->file, cub);
	if (!cub->info_map)
		return (false);
	cub->map = load_map(cub->file, cub);
	if (!cub->map)
		return (false);
	if (!check_general(cub))
		return (false);
	return (true);
}

bool	check_general(t_cub *cub)
{
	if (!check_map(cub))
		return (printf("Error\nFile .cub non correct1\n"), false);
	check_valid_space(&cub, 0);
	if (!check_sides(cub))
		return (printf("Error\nMap non correct\n"), false);
	if (!check_map_spaces(cub) || !check_zero_leak(cub))
		return (printf("Error\nMap non correct\n"), false);
	if (!check_map_char(cub))
		return (printf("Error\nInvalides char in map\n"), false);
	if (!directions_texture(cub->info_map, cub))
		return (printf("Error\nTexture directions invalid\n"), false);
	if (!check_rgb_str(cub->celling) || !check_rgb_str(cub->floor))
		return (printf("Error\nInvalid RGB values\n"), false);
	if (!ft_check_colours_1(cub) || !ft_check_colours_2(cub))
		return (printf("Error\nMalloc failded\n"), false);
	if (!check_numbers(cub->f) || !check_numbers(cub->c))
		return (printf("Error\nInvalid RGB values\n"), false);
	return (true);
}
