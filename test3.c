/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:15:20 by czheng-c          #+#    #+#             */
/*   Updated: 2023/11/10 14:33:41 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	t_md	*smd;

	smd = (t_md *)param;
	mlx_destroy_window(smd->mlx_ptr, smd->win_ptr);
	exit(0);
}

int	handle_key_press(int keycode, void *param)
{
	t_md	*smd;

	smd = (t_md *)param;
	if (smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] == 'E'
	|| smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] == 'V')
	{
		if (keycode == 36)
			exit(0);
		else
			return (0);
	}
	mlx_put_image_to_window(smd->mlx_ptr, smd->win_ptr, \
			smd->smap.floor, smd->ppos.x, smd->ppos.y);
	check_keycode(keycode, smd);
	pod(smd->mlx_ptr, smd->win_ptr, smd);
	return (0);
}

void	display_current_frame(void *mlx_ptr, void *win_ptr, t_md *smd, int cf)
{
	int			i;
	static int	count;

	i = -1;
	while (++i < smd->coin)
	{
		if (smd->map_data[smd->money[i].y / 50][smd->money[i].x / 50] == 'C')
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, smd->smap.floor, \
					smd->money[i].x, smd->money[i].y);
			mlx_put_image_to_window(mlx_ptr, win_ptr, smd->smap.coin[cf], \
					smd->money[i].x, smd->money[i].y);
		}
	}
}

int	animation_function(void *param)
{
	static int		cf;
	t_md			*smd;

	smd = (t_md *)param;
	if (smd->map_data[smd->ppos.y / 50][smd->ppos.x / 50] != 'V')
	{
		display_current_frame(smd->mlx_ptr, smd->win_ptr, smd, cf);
		cf = (cf + 1) % 9;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_md	smd;

	if (ac < 2)
		print_n_exit("Need to input map");
	else if (ac > 2)
		print_n_exit("Only one map input needed");
	checkError(ac, av, &smd);
	smd.mlx_ptr = mlx_init();
	smd.win_ptr = mlx_new_window(smd.mlx_ptr, smd.width * 50, \
	smd.height * 50, "Move Pixel Example");
	if (!smd.mlx_ptr || !smd.win_ptr)
		exit(0);
	mapping(&smd);
	draw_map(smd.mlx_ptr, smd.win_ptr, smd, smd.smap);
	mlx_loop_hook(smd.mlx_ptr, &animation_function, &smd);
	mlx_hook(smd.win_ptr, 2, 1L << 0, &handle_key_press, &smd);
	mlx_hook(smd.win_ptr, 17, 0, close_window, &smd);
	mlx_loop(smd.mlx_ptr);
	return (0);
}
