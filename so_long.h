/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:03:01 by czheng-c          #+#    #+#             */
/*   Updated: 2023/08/15 12:00:46 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SO_LONG_H_
# define _SO_LONG_H_
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    int width;
    int height;
} Button;

#endif
