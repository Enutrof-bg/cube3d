/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_directions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:23 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/05 12:15:58 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

void	fill_direction_2(t_cub *cub, int index, char *line);
int		fill_direction(int index, char *file, t_cub *cub);
int		directions_texture(char **file, t_cub *cub);
bool	is_white_space(char c);

bool	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}


void	fill_direction_2(t_cub *cub, int index, char *line)
{
	if (index == 1)
		cub->no = line;
	else if (index == 2)
		cub->so = line;
	else if (index == 3)
		cub->we = line;
	else if (index == 4)
		cub->ea = line;
}

int	fill_direction(int index, char *file, t_cub *cub)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (is_white_space(file[i]))
		i++;
	i+=2;
	while (is_white_space(file[i]))
		i++;
	while (file[i + j] && !is_white_space(file[i + j]))
		j++;
	line = malloc(sizeof(char) * (j + 1));
	if (!line)
		return (printf("Error\nMalloc failed\n"), 0);
	j = 0;
	while (file[i] && !is_white_space(file[i]))
		line[j++] = file[i++];
	if (line[j - 1] == '\n')
		line[j - 1] = '\0';
	line[j] = '\0';
	fill_direction_2(cub, index, line);
	return (1);
}

int	directions_texture(char **file, t_cub *cub)
{
	int	i;
	int	index;

	i = 0;
	while (cub->info_map[i])
	{
		if (is_valid(cub->info_map[i]))
		{
			index = is_valid(cub->info_map[i]);
			if (index >= 5)
			{
				if (!fill_floor_celling(index, file[i], cub))
					return (ft_free_all(cub), 0);
			}
			else if (!fill_direction(index, file[i], cub))
			{
				ft_free_all(cub);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
