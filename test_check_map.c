/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:35:02 by kevwang           #+#    #+#             */
/*   Updated: 2025/10/27 11:35:03 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_map_size(t_all *data, char **map)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j + 1] == '\0')
			{
				if ((j + 1) != len)
				{
					// ft_printf("Error\nMap dimmensions invalides\n");
					// ft_map_invalid(map);
				}
			}
			j++;
		}
		i++;
	}
	data->map_heigth = i;
	data->map_length = len;
}

char	*ft_return_gnl(char **str, char **result, char **temp, int *fd)
{
	while (*str)
	{
		*temp = ft_strjoin(*result, *str);
		if (!(*temp))
			return (NULL);
		free(*result);
		*result = NULL;
		*result = *temp;
		free(*str);
		*str = NULL;
		*str = get_next_line(*fd);
	}
	close(*fd);
	return (*result);
}

char	*ft_open(char *filename)
{
	char	*str;
	char	*result;
	char	*temp;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFilename invalid\n");
		exit(EXIT_FAILURE);
	}
	result = ft_strdup("");
	if (!result)
		return (NULL);
	str = get_next_line(fd);
	if (!str)
		return (NULL);
	return (ft_return_gnl(&str, &result, &temp, &fd));
}

int	ft_check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	i = i - 4;
	if (filename[i] == '.' && filename[i + 1] == 'b'
		&&filename[i + 2] == 'e' && filename[i + 3] == 'r')
		return (0);
	else
		return (1);
}

char	**ft_open_map(t_all *data, char *filename)
{
	char	*str;
	char	**result;

	// if (ft_check_filename(filename) == 1)
	// {
	// 	ft_printf("Error\nFilename invalid\n");
	// 	exit(EXIT_FAILURE);
	// }
	str = ft_open(filename);
	if (!str)
		return (NULL);
	result = ft_split(str, '\n');
	if (!result)
		return (NULL);
	ft_map_size(data, result);
	free(str);
	return (result);
}
