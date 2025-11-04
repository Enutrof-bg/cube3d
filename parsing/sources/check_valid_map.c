/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:17 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/04 12:01:39 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

bool	check_zero_leak(t_cub *cub);
bool	check_sides(t_cub *cub);
bool	check_map_spaces(t_cub *cub);
bool	check_map(t_cub *cub);
bool	check_map_2(char *str);

bool	check_zero_leak(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '0')
			{
				if (!cub->map[i + 1][j] || !cub->map[i - 1][j])
					return (false);
				else if (cub->map[i + 1][j] == ' ' || cub->map[i - 1][j] == ' ')
					return (printf("3\n"), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_sides(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][0] != ' ')
			{
				if (cub->map[i][0] != '1')
					return (false);
			}
			if (cub->map[i][j + 1] == '\n')
			{
				if (cub->map[i][j] != '1' && cub->map[i][j] != ' ')
					return (printf("2\n"), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

// void	print_map(char **map)
// {
// 	int i = 0;
	
// 	while (map[i])
// 	{
// 		printf("%s", map[i]);
// 		i++;
// 	}
// }

bool	check_map_spaces(t_cub *cub)
{
	int	i;
	int	j;
	int	flag;
	// print_map(cub->map);
	i = 1;
	while (cub->map[i])
	{
		j = 1;
		while (cub->map[i][j])
		{
			flag = 0;
			if (cub->map[i][j] == ' ')
			{
				flag = 1;
				while (cub->map[i][j] && cub->map[i][j] == ' ')
					j++;
			}
			if (flag == 1 && (cub->map[i][j] != '1' && cub->map[i][j + 1]))
				return (printf("1 x = [%d] y = [%d]\n", i, j), false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
		{
			if (str[i] != ' ')
				return (false);
		}
		i++;
	}
	return (true);
}

bool	check_map(t_cub *cub)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (cub->map[i])
	{
		j = 0;
		flag = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] != ' ' && cub->map[i][j] != '\n')
				flag = 1;
			j++;
		}
		if (!flag)
			return (false);
		i++;
	}
	i -= 1;
	if (!check_map_2(cub->map[i]))
		return (false);
	return (true);
}
