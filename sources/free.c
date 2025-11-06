/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:03:49 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/02 16:54:34 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_free_tab(char **tab);
void	ft_free_all(t_cub *cub);
void	ft_free_all_2(t_cub *cub);
void	ft_free_all_3(t_cub *cub);

void	ft_free_all(t_cub *cub)
{
	if (cub->file)
	{
		ft_free_tab(cub->file);
		cub->file = NULL;
	}
	if (cub->info_map)
	{
		ft_free_tab(cub->info_map);
		cub->info_map = NULL;
	}
	if (cub->map)
	{
		ft_free_tab(cub->map);
		cub->map = NULL;
	}
	if (cub->ea)
	{
		free(cub->ea);
		cub->ea = NULL;
	}
	ft_free_all_2(cub);
}

void	ft_free_all_2(t_cub *cub)
{
	if (cub->no)
	{
		free(cub->no);
		cub->no = NULL;
	}
	if (cub->so)
	{
		free(cub->so);
		cub->so = NULL;
	}
	if (cub->we)
	{
		free(cub->we);
		cub->we = NULL;
	}
	ft_free_all_3(cub);
}

void	ft_free_all_3(t_cub *cub)
{
	if (cub->floor)
	{
		free(cub->floor);
		cub->floor = NULL;
	}
	if (cub->celling)
	{
		free(cub->celling);
		cub->celling = NULL;
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
