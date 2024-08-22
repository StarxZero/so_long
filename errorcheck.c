/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:32:16 by czheng-c          #+#    #+#             */
/*   Updated: 2023/11/13 10:38:36 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char *name, char *target)
{
	int	len;
	int	len2;
	int	i;
	int	j;

	i = -4;
	j = 0;
	len = ft_strlen(name);
	len2 = ft_strlen(target);
	while (len + i < len)
	{
		if (name[len + i++] != target[j++])
			print_n_exit("Not .ber extension");
	}
}

void	check_content(int h, int w, t_md *smd)
{
	while (++h < smd->height)
	{
		w = -1;
		while (++w < smd->width)
		{
			if (smd->map_data[h][w] == 'C')
				init_coin(smd, h, w);
			else if (smd->map_data[h][w] == 'P')
			{
				smd->player++;
				smd->ppos.y = h;
				smd->ppos.x = w;
			}
			else if (smd->map_data[h][w] == 'E')
				init_exit(smd, h, w);
			else if (smd->map_data[h][w] == 'V')
				init_enemy(smd, h, w);
			else if (smd->map_data[h][w] != '1' && smd->map_data[h][w] != '0')
				print_n_exit("Foreign object detected");
		}
	}
	if (smd->coin < 1 || smd->player != 1 || smd->finish != 1)
		print_n_exit("You're missing either coin, player or exit");
}

void	spotcheck(t_md *smd)
{
	int	w;
	int	h;

	h = -1;
	while (++h < smd->height)
	{
		w = -1;
		while (++w < smd->width)
			if (smd->map_data[0][w] != '1'
			|| smd->map_data[smd->height - 1][w] != '1')
				print_n_exit("Missing wall for width");
		if (smd->map_data[h][0] != '1'
		|| smd->map_data[h][smd->width - 1] != '1')
			print_n_exit("Missing wall for height");
	}
	if (smd->height == smd->width)
		print_n_exit("Square map detected!");
	if (smd->width > 10 || smd->height > 10)
		write(1, "Please wait\n", 12);
}

void	populate(int fd, char *string, t_md *smd)
{
	int	i;
	int	j;

	i = 0;
	while (string != NULL)
	{
		j = -1;
		while (string[++j] != '\0')
		{
			if (j > smd->width && smd->width != 0)
				print_n_exit("The map is not a rectangle");
			if (string[j] == '\n')
				break ;
			smd->map_data[i][j] = string[j];
		}
		if (smd->width != 0 && j != smd->width)
			print_n_exit("The map is not a rectangle");
		else
			smd->width = j;
		smd->map_data[i++][j] = '\0';
		free(string);
		string = get_next_line(fd);
	}
	smd->height = i;
	smd->map_data[i][0] = '\0';
}

void	check_error(char **av, t_md *smd)
{
	char	*filename;
	int		fd;
	char	*string;

	filename = ft_strjoin("maps/", av[1]);
	check_ber(filename, ".ber");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		perror_n_exit("Error");
	else
	{
		init(smd);
		string = get_next_line(fd);
		populate(fd, string, smd);
		close(fd);
		free(filename);
		spotcheck(smd);
		check_content(-1, -1, smd);
		if (find_exit(smd->ppos.x, smd->ppos.y, smd) != 1)
			print_n_exit("No path found");
		if (find_coins(smd->ppos.x, smd->ppos.y, smd) != 1)
			print_n_exit("Coins being blocked by something.");
		smd->ppos.x *= 50;
		smd->ppos.y *= 50;
	}
}
