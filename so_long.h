/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:03:01 by czheng-c          #+#    #+#             */
/*   Updated: 2023/11/13 11:42:14 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <errno.h>
# include "./libft/libft.h"

typedef struct s_keluar
{
	int	x;
	int	y;
}	t_keluar;

typedef struct s_cash
{
	int	x;
	int	y;
}	t_cash;

typedef struct s_hantu
{
	int	x;
	int	y;
}	t_hantu;

typedef struct s_player
{
	int	x;
	int	y;
	int	coin;
}	t_player;

typedef struct s_map
{
	void	*floor;
	void	*brick;
	void	*texture;
	void	*enemy;
	void	*door1;
	void	*door2;
	void	*coin[10];
}	t_map;

typedef struct s_md
{
	int			width;
	int			height;
	char		map_data[50][50];
	int			coin;
	int			enemy;
	int			player;
	int			finish;
	void		*mlx_ptr;
	void		*win_ptr;
	int			steps;
	t_player	ppos;
	t_map		smap;
	t_cash		money[50];
	t_hantu		ghost[50];
	t_keluar	door;
}	t_md;

void	draw_map(t_md *smd, t_map smap);
void	mapping(t_md *smd);
void	*load_texture(void *mlx_ptr, char *filename, int *width, int *height);
void	check_error(char **av, t_md *smd);
void	up(t_md *smd);
void	down(t_md *smd);
void	left(t_md *smd);
void	right(t_md *smd);
void	message(char *string);
void	pod(void *mlx_ptr, void *win_ptr, t_md *smd);
void	check_keycode(int keycode, t_md *smd);
void	init_coin(t_md *smd, int height, int width);
void	init_enemy(t_md *smd, int height, int width);
void	init_exit(t_md *smd, int height, int width);
void	init(t_md *smd);
int		find_exit(int x, int y, t_md *smd);
int		find_coins(int x, int y, t_md *smd);
void	enemy_movement(void *mlx_ptr, void *win_ptr, t_md *smd);

#endif
