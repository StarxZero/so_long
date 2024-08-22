/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:51:59 by czheng-c          #+#    #+#             */
/*   Updated: 2023/11/13 10:30:53 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_exit(int x, int y, t_md *smd)
{
	int	r;
	int	l;
	int	d;
	int	u;

	if (smd->map_data[y][x] == '1' || smd->map_data[y][x] == 'V'
	|| x < 0 || x >= smd->width || y < 0 || y >= smd->height
	|| smd->map_data[y][x] == '.' || smd->map_data[y][x] == '$')
		return (0);
	if (smd->map_data[y][x] == 'E')
		return (1);
	if (smd->map_data[y][x] == 'C')
		smd->map_data[y][x] = '$';
	if (smd->map_data[y][x] == '0')
		smd->map_data[y][x] = '.';
	r = find_exit(x + 1, y, smd);
	l = find_exit(x - 1, y, smd);
	d = find_exit(x, y + 1, smd);
	u = find_exit(x, y - 1, smd);
	return (r || l || d || u);
}

int	find_coins(int x, int y, t_md *smd)
{
	static int	duit;

	if (smd->map_data[y][x] == '1' || smd->map_data[y][x] == 'V'
	|| x < 0 || x >= smd->width || y < 0 || y >= smd->height
	|| smd->map_data[y][x] == '0' || smd->map_data[y][x] == 'C'
	|| smd->map_data[y][x] == 'E')
		return (0);
	if (smd->map_data[y][x] == '$')
	{
		duit++;
		smd->map_data[y][x] = 'C';
	}
	if (smd->map_data[y][x] == '.')
		smd->map_data[y][x] = '0';
	find_coins(x + 1, y, smd);
	find_coins(x - 1, y, smd);
	find_coins(x, y + 1, smd);
	find_coins(x, y - 1, smd);
	if (duit == smd->coin)
		return (1);
	return (0);
}
