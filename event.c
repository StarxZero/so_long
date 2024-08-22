/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:45:47 by czheng-c          #+#    #+#             */
/*   Updated: 2023/11/13 10:41:13 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pod(void *mlx_ptr, void *win_ptr, t_md *smd)
{
	char	*steps;

	steps = ft_itoa(smd->steps);
	mlx_put_image_to_window(mlx_ptr, win_ptr, smd->smap.brick, 0, 0);
	mlx_string_put(mlx_ptr, win_ptr, 0, 0, 0xFFFFFF, steps);
	free(steps);
	if (smd->ppos.coin == smd->coin)
	{
		mlx_put_image_to_window(mlx_ptr, win_ptr, smd->smap.floor, \
				smd->door.x, smd->door.y);
		mlx_put_image_to_window(mlx_ptr, win_ptr, smd->smap.door2, \
				smd->door.x, smd->door.y);
	}
	if (smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] == 'E')
		message("Congrats!!");
	else if (smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] == 'V')
		message("You die!");
	else
	{
		mlx_put_image_to_window(mlx_ptr, win_ptr, smd->smap.floor, \
				smd->ppos.x, smd->ppos.y);
		mlx_put_image_to_window(mlx_ptr, win_ptr, smd->smap.texture, \
				smd->ppos.x, smd->ppos.y);
	}
}

void	check_keycode(int keycode, t_md *smd)
{
	if (keycode == 13 && \
			smd->map_data[(smd->ppos.y - 50) / 50][smd->ppos.x / 50] != '1')
		up(smd);
	else if (keycode == 1 && \
			smd->map_data[(smd->ppos.y + 50) / 50][smd->ppos.x / 50] != '1')
		down(smd);
	else if (keycode == 0 && \
			smd->map_data[smd->ppos.y / 50][(smd->ppos.x - 50) / 50] != '1')
		left(smd);
	else if (keycode == 2 && \
			smd->map_data[smd->ppos.y / 50][(smd->ppos.x + 50) / 50] != '1')
		right(smd);
	else if (keycode == 53)
		exit(0);
}

void	message(char *string)
{
	ft_printf("%s\n", string);
	exit(0);
}
