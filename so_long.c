/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:02:16 by czheng-c          #+#    #+#             */
/*   Updated: 2023/08/15 11:43:14 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// int deal_key(int key, void *param)
// {
// 	ft_putchar('X');
// 	mlx_pixel_put(mlx_ptr, win_ptr, );
// 	return (0);
// }

int key_press(int keycode, void *param)
{
	printf("Key pressed: %d\n", keycode);
	return 0;
}

int mouse_click(int button, int x, int y, void *param)
{
	printf("Mouse click: Button %d at position (%d, %d)\n", button, x, y);
	return 0;
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "My first window!");
	
	//handle key press
	//mlx_hook(win_ptr, 2, 1L << 0, &key_press, NULL);

	//output string
	//mlx_string_put(mlx_ptr, win_ptr, 200, 50, 0xFFFFFF, "Hello World");

	//handle mouse
	//mlx_hook(win_ptr, 4, 1L << 2, &mouse_click, NULL);

	//put dot
	//mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFF0000);
	// mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	// mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	//printf("hello");
	mlx_destroy_window(mlx_ptr, win_ptr);
	free(mlx_ptr);
	free(win_ptr);
}
