/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_directions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:23 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/05 17:51:15 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include "../includes/get_next_line.h"

bool	fill_direction_2(t_cub *cub, int index, char *line);
int		fill_direction(int index, char *file, t_cub *cub);
int		directions_texture(char **file, t_cub *cub);
bool	is_white_space(char c);

bool	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}


bool	fill_direction_2(t_cub *cub, int index, char *line)
{
	if (index == 1)
	{
		cub->no = line;
		return (true);
	}
	else if (index == 2)
	{
		cub->so = line;
		return (true);
	}
	else if (index == 3)
	{
		cub->we = line;
		return (true);
	}
	else if (index == 4)
	{
		cub->ea = line;
		return (true);
	}
	else
		return (printf("3\n"), false);
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
	if (j > 0 && line[j - 1] == '\n')
		line[j - 1] = '\0';
	line[j] = '\0';
	if (!fill_direction_2(cub, index, line))
		return (printf("2\n"), 0);
	// fill_direction_2(cub, index, line);
	return (1);
}

bool	there_is_char(char *str)
{
	int i;
	
	i = 0;

	while (str[i])
	{
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		{
			if (str[i] != '\n')
				return (false);
		}
		i++;
	}
	return (true);
}

int	directions_texture(char **file, t_cub *cub)
{
	int	i;
	int	index;

	i = 0;
	while (cub->info_map[i])
	{
		if (is_valid(cub->info_map[i], cub))
		{
			index = is_valid(cub->info_map[i], cub);
			if (index >= 5)
			{
				if (!fill_floor_celling(index, file[i], cub))
					return (ft_free_all(cub), 0);
			}
			else if (!fill_direction(index, file[i], cub))
			{
				ft_free_all(cub);
				return (printf("1\n"), 0);
			}
		}
		else if (!there_is_char(cub->info_map[i]))
			return (/*printf("%s\n",cub->info_map[i]), */0);
		i++;

	}
	return (1);
}
