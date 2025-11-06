/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_loading_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:25 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/04 16:24:11 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

char	**load_file(char *file, t_cub *cub);
char	**load_info(char **file, t_cub *cub);
char	**load_map(char **file, t_cub *cub);

char	**load_file(char *file, t_cub *cub)
{
	int		fd;
	int		lines;
	int		i;
	char	**map;
	char	*line;

	i = 0;
	lines = nb_line(file, cub);
	if (lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (close(fd), map);
}

char	**load_info(char **file, t_cub *cub)
{
	int		lines;
	char	**info;
	int		i;

	i = 0;
	lines = nb_line_info(file, cub);
	info = malloc(sizeof(char *) * (lines + 1));
	if (!info)
		return (printf("Error\nMalloc failed\n"), NULL);
	while (i < lines)
	{
		info[i] = ft_strdup(file[i]);
		if (!info[i])
			return (ft_free_tab(info), info = NULL, NULL);
		i++;
	}
	info[i] = NULL;
	return (info);
}

char	**load_map(char **file, t_cub *cub)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (cub->line_total - cub->line_info + 1));
	if (!map)
		return (printf("Error\nMalloc failed\n"), NULL);
	while (file[cub->line_info + i])
	{
		map[i] = ft_strdup(file[cub->line_info + i]);
		if (!map[i])
			return (ft_free_tab(map), map = NULL, NULL);
		i++;
	}
	map[i] = NULL;
	return (map);
}
