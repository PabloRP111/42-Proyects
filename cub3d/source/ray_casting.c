/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:49:49 by femoreno          #+#    #+#             */
/*   Updated: 2025/06/06 08:55:17 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

double	ray_distance_v(t_window *window, t_ray *ray)
{
	int		map_x;
	int		map_y;

	while (is_inside_map(ray->v_wallhit_x, ray->v_wallhit_y, window))
	{
		map_x = (int)(ray->v_wallhit_x) / BOX_SIZE;
		map_y = (int)(ray->v_wallhit_y) / BOX_SIZE;
		if (get_map_tile(map_x, map_y, window, 1) == 1)
			break ;
		ray->v_wallhit_x += ray->v_step_x;
		ray->v_wallhit_y += ray->v_step_y;
	}
	return (sqrt(pow(ray->v_wallhit_x - window->cam->x, 2)
			+ pow(ray->v_wallhit_y - window->cam->y, 2)));
}

double	ray_distance_h(t_window *window, t_ray *ray)
{
	int		map_x;
	int		map_y;

	while (is_inside_map(ray->h_wallhit_x, ray->h_wallhit_y, window))
	{
		map_x = floor(ray->h_wallhit_x / BOX_SIZE);
		map_y = floor(ray->h_wallhit_y / BOX_SIZE);
		if (get_map_tile(map_x, map_y, window, 0) == 1)
			break ;
		ray->h_wallhit_x += ray->h_step_x;
		ray->h_wallhit_y += ray->h_step_y;
	}
	return (sqrt(pow(ray->h_wallhit_x - window->cam->x, 2)
			+ pow(ray->h_wallhit_y - window->cam->y, 2)));
}

void	calculate_ray_stepping(t_window *window, double tan_value,
	double dist_h, double dist_v)
{
	if (window->ray->is_looking_up)
		window->ray->h_step_y *= -1;
	window->ray->h_step_x = BOX_SIZE / tan_value;
	if (!window->ray->is_looking_up)
		window->ray->h_step_x *= -1;
	if (!window->ray->is_looking_right)
		window->ray->v_step_x *= -1;
	window->ray->v_step_y = BOX_SIZE * tan_value;
	if (window->ray->is_looking_right)
		window->ray->v_step_y *= -1;
	dist_h = ray_distance_h(window, window->ray);
	dist_v = ray_distance_v(window, window->ray);
	if (dist_h <= dist_v)
	{
		window->ray->distance = dist_h;
		window->ray->is_vertical = 0;
	}
	else
	{
		window->ray->distance = dist_v;
		window->ray->is_vertical = 1;
	}
}

void	calculate_intercepts(t_window *window, t_ray *ray)
{
	double	tan_value;

	tan_value = tan(ray->angle);
	ray->is_looking_up = (ray->angle < PI);
	ray->is_looking_right = (ray->angle < PI / 2 || ray->angle > 3 * PI / 2);
	if (!ray->is_looking_up)
		ray->h_wallhit_y = floor(window->cam->y / BOX_SIZE)
			* BOX_SIZE + BOX_SIZE;
	else
		ray->h_wallhit_y = floor(window->cam->y / BOX_SIZE) * BOX_SIZE;
	ray->h_wallhit_x = window->cam->x + (window->cam->y - ray->h_wallhit_y)
		/ tan(ray->angle);
	if (ray->is_looking_right)
		ray->v_wallhit_x = floor(window->cam->x / BOX_SIZE)
			* BOX_SIZE + BOX_SIZE;
	else
		ray->v_wallhit_x = floor(window->cam->x / BOX_SIZE) * BOX_SIZE;
	ray->v_wallhit_y = window->cam->y + (window->cam->x - ray->v_wallhit_x)
		* tan(ray->angle);
	window->ray->h_step_y = BOX_SIZE;
	window->ray->v_step_x = BOX_SIZE;
	calculate_ray_stepping(window, tan_value, 0, 0);
}

void	ray_casting(t_window *window)
{
	t_ray	ray;
	int		index;

	index = SCREEN_WIDTH - 1;
	ft_memset(&ray, 0, sizeof(t_ray));
	window->ray = &ray;
	ray.angle = fmod((window->cam->rotationx - (FOV_ANGLE / 2) + 2 * PI),
			2 * PI);
	while (index > 0)
	{
		ray.index = index;
		ray.is_vertical = 0;
		calculate_intercepts(window, &ray);
		ray.wall_height = (BOX_SIZE / ray.distance)
			* window->cam->dist_to_proj_plane;
		draw_image(window);
		ray.angle += FOV_ANGLE / SCREEN_WIDTH;
		ray.angle = fmod(window->ray->angle + 2 * PI, 2 * PI);
		index--;
	}
}
