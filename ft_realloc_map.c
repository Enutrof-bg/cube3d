/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:58:23 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/05 11:58:23 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	find_biggest_line(t_all *data)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (data->map[i])
	{
		if ((int)ft_strlen(data->map[i]) > line)
			line = (int)ft_strlen(data->map[i]) - 1;
		i++;
	}
	return (line);
}

int	ft_replace(t_all *data, int i, int line)
{
	int		j;
	char	*temp;

	j = 0;
	if ((int)ft_strlen(data->map[i]) < line)
	{
		temp = data->map[i];
		data->map[i] = malloc(sizeof(char) * (line + 1));
		if (!data->map[i])
			return (data->map[i] = temp, 0);
		ft_strcpy(data->map[i], temp);
		j = (int)ft_strlen(temp) - 1;
		free(temp);
		while (j < line)
		{
			data->map[i][j] = ' ';
			j++;
		}
		data->map[i][j] = '\0';
	}
	return (1);
}

int	realloc_minimap(t_all *data)
{
	int		i;
	int		line;

	i = 0;
	line = find_biggest_line(data);
	while (data->map[i])
	{
		if (ft_replace(data, i, line) == 0)
			return (0);
		i++;
	}
	return (1);
}