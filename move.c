/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:55:40 by czheng-c          #+#    #+#             */
/*   Updated: 2023/11/10 14:11:41 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_md *smd)
{
	if (smd->map_data[(smd->ppos.y - 50) / 50][smd->ppos.x / 50] == 'E'
	&& smd->ppos.coin != smd->coin)
		return ;
	smd->ppos.y -= 1 * 50;
	smd->steps++;
	ft_printf("Move count:%d\n", smd->steps);
	if (smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] == 'C')
	{
		smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] = '0';
		smd->ppos.coin++;
	}
}

void	down(t_md *smd)
{
	if (smd->map_data[(smd->ppos.y + 50) / 50][smd->ppos.x / 50] == 'E'
	&& smd->ppos.coin != smd->coin)
		return ;
	smd->ppos.y += 1 * 50;
	smd->steps++;
	ft_printf("Move count:%d\n", smd->steps);
	if (smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] == 'C')
	{
		smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] = '0';
		smd->ppos.coin++;
	}
}

void	left(t_md *smd)
{
	if (smd->map_data[smd->ppos.y / 50][(smd->ppos.x - 50) / 50] == 'E'
	&& smd->ppos.coin != smd->coin)
		return ;
	smd->ppos.x -= 1 * 50;
	smd->steps++;
	ft_printf("Move count:%d\n", smd->steps);
	if (smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] == 'C')
	{
		smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] = '0';
		smd->ppos.coin++;
	}
}

void	right(t_md *smd)
{
	if (smd->map_data[smd->ppos.y / 50][(smd->ppos.x + 50) / 50] == 'E'
	&& smd->ppos.coin != smd->coin)
		return ;
	smd->ppos.x += 1 * 50;
	smd->steps++;
	ft_printf("Move count:%d\n", smd->steps);
	if (smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] == 'C')
	{
		smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] = '0';
		smd->ppos.coin++;
	}
}
