/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:35:26 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/05 16:36:00 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"
#include "../includes/get_next_line.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		double_tab_lenght(char **tab);
int		ft_atoi(char *str);
int		nb_line_info(char **file, t_cub *cub);
int		nb_line(char *file, t_cub *cub);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	double_tab_lenght(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	nb;
	int	i;

	nb = -1;
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (nb == -1)
				nb = 0;
			nb = nb * 10 + (str[i] - '0');
			i++;
		}
	}
	return (nb);
}

int	nb_line_info(char **file, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == '\n' || file[i][j] == ' ')
			j++;
		if (file[i][j] == '1')
			return (cub->line_info = i, i);
		i += 1;
	}
	return (i);
}

int	nb_line(char *file, t_cub *cub)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	cub->line_total = count;
	return (count);
}
