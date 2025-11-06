/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:15 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/05 17:54:47 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include "../includes/get_next_line.h"

int		fill_floor_celling(int index, char *file, t_cub *cub);
void	fill_floor_celling_2(t_cub *cub, int index, char *line);
char	*skip_space(char *str);
int		is_valid(char *file, t_cub *cub);
bool	check_name(char *file);

int	fill_floor_celling(int index, char *file, t_cub *cub)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (!(file[i] >= '0' && file[i] <= '9'))
		i++;
	while (file[i + j])
		j++;
	line = malloc(sizeof(char) * (j + 1));
	if (!line)
		return (printf("Error\nMalloc failed\n"), 0);
	j = 0;
	while (file[i])
	{
		line[j] = file[i];
		i++;
		j++;
	}
	line[j] = '\0';
	fill_floor_celling_2(cub, index, line);
	return (1);
}

void	fill_floor_celling_2(t_cub *cub, int index, char *line)
{
	if (index == 5)
		cub->floor = line;
	else if (index == 6)
		cub->celling = line;
}

char	*skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (&str[i]);
	}
	return (&str[i]);
}

int	is_valid_2(char *file, t_cub *cub)
{
	if (ft_strncmp(skip_space(file), "F", 1) == 0)
	{
		if (cub->floor)
			return (0);
		return (5);
	}
	else if (ft_strncmp(skip_space(file), "C", 1) == 0)
	{
		if (cub->celling)
			return (0);
		return (6);
	}
	return (0);
}

int	is_valid(char *file, t_cub *cub)
{
	if (ft_strncmp(skip_space(file), "NO", 2) == 0)
	{
		if (cub->no)
			return (0);
		return (1);
	}
	else if (ft_strncmp(skip_space(file), "SO", 2) == 0)
	{
		if (cub->so)
			return (0);
		return (2);
	}
	else if (ft_strncmp(skip_space(file), "WE", 2) == 0)
	{
		if (cub->we)
			return (0);
		return (3);
	}
	else if (ft_strncmp(skip_space(file), "EA", 2) == 0)
	{
		if (cub->ea)
			return (0);
		return (4);
	}
	return (is_valid_2(file, cub));
}

bool	check_name(char *file)
{
	int	i;
	int	valide;

	valide = 0;
	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	i++;
	if (file[i] == 'c')
		valide += 1;
	if (file[i + 1] == 'u')
		valide += 1;
	if (file[i + 2] == 'b')
		valide += 1;
	if (file[i + 3] != '\0')
		return (false);
	if (valide == 3)
		return (true);
	else
		return (false);
}
