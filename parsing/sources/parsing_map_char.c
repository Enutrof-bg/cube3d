/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:27 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/04 13:34:14 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

bool	floor_celling(char c);
bool	player_char(char c);
bool	check_map_char(t_cub *cub);
bool	valid_char(char c);

bool	floor_celling(char c)
{
	if (c == '1' || c == '0')
		return (true);
	else if ((c >= 9 && c <= 23) || c == 32)
		return (true);
	else
		return (false);
}

bool	player_char(char c)
{
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return (true);
	return (false);
}

bool	door_char(char c)
{
	if (c == 'O' || c == 'D')
		return (true);
	return (false);
}

bool	check_map_char(t_cub *cub)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	count_player = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (!floor_celling(cub->map[i][j]) && !door_char(cub->map[i][j]))
			{
				if (player_char(cub->map[i][j]))
					count_player++;
				else
					return (false);
			}
			j++;
		}
		i++;
	}
	if (count_player != 1)
		return (false);
	return (true);
}

bool	valid_char(char c)
{
	if (c == '0')
		return (true);
	return (false);
}
