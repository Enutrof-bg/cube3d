/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_anim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:30:38 by kevwang           #+#    #+#             */
/*   Updated: 2025/11/02 14:30:38 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//tkt
void	set_img_anim(t_all *data)
{
	int					i;
	static const char	*paths[15] = {
		"./img/anim/anim1.xpm", "./img/anim/anim2.xpm", "./img/anim/anim3.xpm",
		"./img/anim/anim4.xpm", "./img/anim/anim5.xpm", "./img/anim/anim6.xpm",
		"./img/anim/anim7.xpm", "./img/anim/anim8.xpm", "./img/anim/anim9.xpm",
		"./img/anim/anim10.xpm", "./img/anim/anim11.xpm",
		"./img/anim/anim12.xpm", "./img/anim/anim13.xpm",
		"./img/anim/anim14.xpm", "./img/anim/anim15.xpm"};

	i = 0;
	while (i < 15)
	{
		data->anim[i].dest = (char *)paths[i];
		data->anim[i].img = mlx_xpm_file_to_image(data->mlx,
				data->anim[i].dest, &data->anim[i].img_width,
				&data->anim[i].img_heigth);
		if (!data->anim[i].img)
			return (printf("Prout %d\n", i), exit(1));
		data->anim[i].s_screen.addr = mlx_get_data_addr(data->anim[i].img,
				&data->anim[i].s_screen.bits_per_pixel,
				&data->anim[i].s_screen.line_length,
				&data->anim[i].s_screen.endian);
		i++;
	}
}
