/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:35:08 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/04 12:17:13 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

void	check_valide_space_2(t_cub **cub, int i, int j, int k);
void	check_valid_space(t_cub **cub, int f);
void	check_valid_space_3(t_cub **cub, int i, int j);

void	check_valid_space_3(t_cub **cub, int i, int j)
{
	if (j + 1 < (int)ft_strlen((*cub)->map[i])
		&& valid_char((*cub)->map[i][j + 1]))
		(*cub)->map[i][j] = '0';
	if (valid_char((*cub)->map[i][j - 1]))
		(*cub)->map[i][j] = '0';
	if (j < (int)ft_strlen((*cub)->map[i + 1])
		&& valid_char((*cub)->map[i + 1][j]))
		(*cub)->map[i][j] = '0';
	if (j < (int)ft_strlen((*cub)->map[i - 1])
		&& valid_char((*cub)->map[i - 1][j]))
		(*cub)->map[i][j] = '0';
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

void	check_valide_space_2(t_cub **cub, int i, int j, int k)
{
	check_valid_space_3(cub, i, j);
	if ((*cub)->map[i][j - 1] == '1')
	{
		while (j + k < (int)ft_strlen((*cub)->map[i])
			&& (*cub)->map[i][j + k] && (*cub)->map[i][j + k] != '1')
		{
			if ((*cub)->map[i][j + k] && (*cub)->map[i][j + k] == '0')
			{
				while (j < k)
				{
					if ((*cub)->map[i][j] != '1')
						(*cub)->map[i][j] = '0';
					j++;
				}
			}
			k++;
		}
	}
}

void	check_valid_space(t_cub **cub, int f)
{
	int	i;
	int	j;

	f++;
	i = 1;
	while (i < (double_tab_lenght((*cub)->map) - 1))
	{
		j = 1;
		while (j < ((int)ft_strlen((*cub)->map[i]) - 1))
		{
			if ((*cub)->map[i][j] == ' ')
				check_valide_space_2(cub, i, j, 0);
			j++;
		}
		i++;
	}
	if (f == 10)
		return ;
	check_valid_space(cub, f);
}
