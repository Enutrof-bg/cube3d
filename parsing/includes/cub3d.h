/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:41:17 by vafavard          #+#    #+#             */
/*   Updated: 2025/11/03 12:15:53 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../../cube.h"

// typedef struct s_cub
// {
// 	char    **file;
// 	char    **map;
// 	char    **info_map;
// 	int     line_info;
// 	int     line_total;
// 	char    *NO;
// 	char    *SO;
// 	char    *WE;
// 	char    *EA;
// 	int     *F;
// 	int     *C;
// 	char    *floor;
// 	char    *celling;
//}t_cub;

//main.c
// int ft_open_map(t_all *data, char *filename);

// //parsing_map
// bool	load_and_check(t_cub *cub);
// bool	check_general(t_cub *cub);

// //parsing_map_char
// bool	floor_celling(char c); 
// bool	player_char(char c);
// bool	check_map_char(t_cub *cub);
// bool	valid_char(char c);

// //utils
// int		ft_strncmp(const char *s1, const char *s2, size_t n);
// int		double_tab_lenght(char **tab);
// int		ft_atoi(char *str);
// int		nb_line_info(char **file, t_cub *cub);
// int		nb_line(char *file, t_cub *cub);

// //check_valid_map
// bool	check_zero_leak(t_cub *cub);
// bool	check_sides(t_cub *cub);
// bool	check_map_spaces(t_cub *cub);
// bool	check_map(t_cub *cub);
// bool	check_map_2(char *str);

// //parsing_colours
// bool	check_numbers(int *tab);
// bool	check_rgb_str(char *str);
// int		check_rgb_str_2(t_cub *cub);
// void	ft_check_colours_1(t_cub *cub);
// void	ft_check_colours_2(t_cub *cub);

// //check_valid_map_2
// int		fill_floor_celling(int index, char *file, t_cub *cub);
// void	fill_floor_celling_2(t_cub *cub, int index, char *line);
// char	*skip_space(char *str);
// int		is_valid(char *file);
// bool	check_name(char *file);

// //check_valid_map_3
// void	check_valide_space_2(t_cub **cub, int i, int j, int k);
// void	check_valid_space(t_cub **cub, int f);

// //parsing_directions
// void	fill_direction_2(t_cub *cub, int index, char *line);
// int		fill_direction(int index,char *file, t_cub *cub);
// int		directions_texture(char **file, t_cub *cub);

// //parsing_loading_map
// char	**load_file(char *file, t_cub *cub);
// char	**load_info(char **file, t_cub *cub);
// char	**load_map(char **file, t_cub *cub);

// //free
// void    ft_free_tab(char **tab);
// void    ft_free_all(t_cub *cub);
// void    ft_free_all_2(t_cub *cub);
// void    ft_free_all_3(t_cub *cub);

// //init
// int    init_all(t_cub *cub);

// int		ft_count_word(char const *s, char c);
// char	*ft_malloc(char const *s, int start, int end);
// char	**ft_split(char const *s, char c);
// void	ft_free_all_split(char **tab, int last);
// int		extern_loop(const char *s, int i, char c, int flag);

#endif
