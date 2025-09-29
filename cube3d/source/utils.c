/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femoreno <femoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:55:11 by femoreno          #+#    #+#             */
/*   Updated: 2025/06/06 12:32:46 by femoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"
//rgba, argb, barg, gbar, 
uint32_t	rgb_to_hex(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((uint32_t)r << 24 | (uint32_t)g << 16 | (uint32_t)b << 8
		| (uint32_t)a);
}

char	get_map_tile(int map_x, int map_y, t_window *window, int vert)
{
	if (vert == 1)
	{
		if (
			(window->map->map[map_y][map_x - 1] == '1') ||
			(window->map->map[map_y][map_x] == '1') ||
			(window->map->map[map_y][map_x] == ' '))
			return (1);
	}
	else
	{
		if ((window->map->map[map_y - 1][map_x] == '1') ||
			(window->map->map[map_y][map_x] == '1') ||
			(window->map->map[map_y][map_x] == ' '))
			return (1);
	}
	return (0);
}

int	is_inside_map(double wallhit_x, double wallhit_y, t_window *window)
{
	int	x;
	int	y;

	if (wallhit_x < 0 || wallhit_y < 0)
		return (0);
	x = (int)floor(wallhit_x / BOX_SIZE);
	y = (int)floor(wallhit_y / BOX_SIZE);
	if (y < 0 || y >= window->map->rows)
		return (0);
	if (x < 0 || x >= (int)ft_strlen(window->map->map[y]))
		return (0);
	return (1);
}

void	show_map(t_window *window)
{
	int	i;
	int	j;

	if (!window || !window->map || !window->map->map)
		return ;
	i = 0;
	j = 0;
	while (window->map->map[i])
	{
		j = 0;
		while (window->map->map[i][j])
		{
			printf("%c", window->map->map[i][j]);
			j++;
		}
		i++;
	}
	printf("\nFloor: %d", window->images->rgb[0]);
	printf("\nCeiling: %d", window->images->rgb[1]);
	printf("\nMap_pj_x: %d  Cam x: %f Cam rotation_x: %f",
		window->map->player_x_pos, window->cam->x, window->cam->rotationx);
	printf("\nMap_pj_y: %d Cam y: %f\n",
		window->map->player_y_pos, window->cam->y);
}

void	change_map(t_window *window)
{
	int	x;
	int	y;

	x = (int)floor(window->cam->x / BOX_SIZE);
	y = (int)floor(window->cam->y / BOX_SIZE);
	if (x != window->map->player_x_pos
		|| y != window->map->player_y_pos)
	{
		window->map->map[window->map->player_y_pos]
		[window->map->player_x_pos] = '0';
		window->map->map[y][x] = window->map->orientation;
		window->map->player_x_pos = x;
		window->map->player_y_pos = y;
	}
}
