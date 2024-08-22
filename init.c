/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:55:30 by czheng-c          #+#    #+#             */
/*   Updated: 2023/11/10 13:56:41 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_coin(t_md *smd, int height, int width)
{
	smd->money[smd->coin].x = width * 50;
	smd->money[smd->coin].y = height * 50;
	smd->coin++;
}

void	init_enemy(t_md *smd, int height, int width)
{
	smd->ghost[smd->enemy].x = width * 50;
	smd->ghost[smd->enemy].y = height * 50;
	smd->enemy++;
}

void	init_exit(t_md *smd, int height, int width)
{
	smd->door.x = width * 50;
	smd->door.y = height * 50;
	smd->finish++;
}

void	init(t_md *smd)
{
	smd->width = 0;
	smd->height = 0;
	smd->coin = 0;
	smd->enemy = 0;
	smd->player = 0;
	smd->finish = 0;
	smd->ppos.x = 0;
	smd->ppos.y = 0;
	smd->ppos.coin = 0;
	smd->steps = 0;
	smd->door.x = 0;
	smd->door.y = 0;
}
