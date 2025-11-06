/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:20:18 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/04 16:35:31 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

bool	check_numbers(int *tab);
bool	check_rgb_str(char *str);
int		check_rgb_str_2(t_cub *cub);
int		ft_check_colours_1(t_cub *cub);
int		ft_check_colours_2(t_cub *cub);

bool	check_numbers(int *tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (tab[i] < 0 || tab[i] > 255)
			return (false);
		i++;
	}
	return (true);
}

bool	check_rgb_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (false);
	while (i < (int)ft_strlen(str) - 1)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] == ',')
				count++;
			else if (!((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
				return (false);
		}
		i++;
	}
	if (count != 2)
		return (false);
	return (true);
}

int	check_rgb_str_2(t_cub *cub)
{
	if (ft_strlen(cub->celling) < 5 || ft_strlen(cub->celling) > 11)
		return (0);
	if (ft_strlen(cub->floor) < 5 || ft_strlen(cub->floor) > 11)
		return (0);
	return (1);
}

int	ft_check_colours_1(t_cub *cub)
{
	char	**values;
	int		i;

	i = 0;
	values = ft_split(cub->floor, ',');
	if (!values)
		return (0);
	while (values[i] && i < 3)
	{
		cub->f[i] = ft_atoi(values[i]);
		i++;
	}
	ft_free_tab(values);
	return (1);
}

int	ft_check_colours_2(t_cub *cub)
{
	char	**values;
	int		i;

	i = 0;
	values = ft_split(cub->celling, ',');
	if (!values)
		return (0);
	while (values[i] && i < 3)
	{
		cub->c[i] = ft_atoi(values[i]);
		i++;
	}
	ft_free_tab(values);
	return (1);
}
