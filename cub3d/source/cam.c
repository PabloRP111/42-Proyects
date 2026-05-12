/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:53:26 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/06 07:56:37 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	ft_rotation(t_window *window, int side)
{
	if (window->end_game == 1)
		return ;
	if (side == 1)
	{
		if ((window->cam->rotationx + ROTATION_SPEED) > 2 * PI)
			window->cam->rotationx += ROTATION_SPEED - (2 * PI);
		else
			window->cam->rotationx += ROTATION_SPEED;
	}
	else if (side == 2)
	{
		if ((window->cam->rotationx - ROTATION_SPEED) < 0)
			window->cam->rotationx += (2 * PI) - ROTATION_SPEED;
		else
			window->cam->rotationx -= ROTATION_SPEED;
	}
	ray_casting(window);
}

void	ft_check_move(t_window *window, int x, int y)
{
	int	new_x;
	int	new_y;
	int	map_x;
	int	map_y;

	new_x = roundf(window->cam->x + x);
	new_y = roundf(window->cam->y + y);
	map_x = new_x / BOX_SIZE;
	map_y = new_y / BOX_SIZE;
	if (window->map->map[map_y][map_x] != '1')
	{
		window->cam->x = new_x;
		window->cam->y = new_y;
		change_map(window);
	}
}

void	ft_move(t_window *window, int key, double x, double y)
{
	if (window->end_game == 1)
		return ;
	if (key == 1)
	{
		x = cos(window->cam->rotationx) * PLAYER_SPEED;
		y = -sin(window->cam->rotationx) * PLAYER_SPEED;
	}
	else if (key == 2)
	{
		x = cos(window->cam->rotationx + PI / 2) * PLAYER_SPEED;
		y = -sin(window->cam->rotationx + PI / 2) * PLAYER_SPEED;
	}
	else if (key == 3)
	{
		x = -cos(window->cam->rotationx) * PLAYER_SPEED;
		y = sin(window->cam->rotationx) * PLAYER_SPEED;
	}
	else if (key == 4)
	{
		x = cos(window->cam->rotationx - PI / 2) * PLAYER_SPEED;
		y = -sin(window->cam->rotationx - PI / 2) * PLAYER_SPEED;
	}
	ft_check_move(window, x, y);
	ray_casting(window);
}
