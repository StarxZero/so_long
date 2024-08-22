/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:12:50 by czheng-c          #+#    #+#             */
/*   Updated: 2023/11/13 11:47:32 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_image(t_md *smd, char *string, int width, int height)
{
	void	*temp;

	temp = mlx_xpm_file_to_image(smd->mlx_ptr, string, &width, &height);
	return (temp);
}

void	insert_image(t_md *smd, void *img, int x, int y)
{
	mlx_put_image_to_window(smd->mlx_ptr, smd->win_ptr, img, x, y);
}

void	draw_map(t_md *smd, t_map smap)
{
	int	x;
	int	y;

	y = -1;
	while (++y < smd->height)
	{
		x = -1;
		while (++x < smd->width)
		{
			if (smd->map_data[y][x] == '1')
				insert_image(smd, smap.brick, x * 50, y * 50);
			else
				insert_image(smd, smap.floor, x * 50, y * 50);
			if (smd->map_data[y][x] == 'V')
				insert_image(smd, smap.enemy, x * 50, y * 50);
			else if (smd->map_data[y][x] == 'E')
				insert_image(smd, smap.door1, x * 50, y * 50);
			else if (smd->map_data[y][x] == 'C')
				insert_image(smd, smd->smap.coin[0], x * 50, y * 50);
			else if (smd->map_data[y][x] == 'P')
				insert_image(smd, smap.texture, x * 50, y * 50);
		}
	}
}

void	mapping(t_md *smd)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	smd->smap.brick = put_image(smd, "./sprites/brick.xpm", width, height);
	smd->smap.floor = put_image(smd, "./sprites/floor.xpm", width, height);
	smd->smap.texture = put_image(smd, "./sprites/bob.xpm", width, height);
	smd->smap.enemy = put_image(smd, "./sprites/enemy.xpm", width, height);
	smd->smap.door1 = put_image(smd, "./sprites/door.xpm", width, height);
	smd->smap.door2 = put_image(smd, "./sprites/door2.xpm", width, height);
	smd->smap.coin[0] = put_image(smd, "./sprites/coin1.xpm", width, height);
	smd->smap.coin[1] = put_image(smd, "./sprites/coin2.xpm", width, height);
	smd->smap.coin[2] = put_image(smd, "./sprites/coin3.xpm", width, height);
	smd->smap.coin[3] = put_image(smd, "./sprites/coin4.xpm", width, height);
	smd->smap.coin[4] = put_image(smd, "./sprites/coin5.xpm", width, height);
	smd->smap.coin[5] = put_image(smd, "./sprites/coin6.xpm", width, height);
	smd->smap.coin[6] = put_image(smd, "./sprites/coin7.xpm", width, height);
	smd->smap.coin[7] = put_image(smd, "./sprites/coin8.xpm", width, height);
	smd->smap.coin[8] = put_image(smd, "./sprites/coin9.xpm", width, height);
}
