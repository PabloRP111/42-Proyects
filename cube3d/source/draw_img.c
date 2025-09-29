/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:34:41 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/06 11:09:31 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

double	getwallhit(t_window *window, mlx_texture_t *texture)
{
	double	wallhit;

	if (window->ray->is_vertical == 1)
	{
		wallhit = fmodf((window->ray->v_wallhit_y / BOX_SIZE), 1.0)
			* texture->width;
		if (!window->ray->is_looking_right)
			wallhit = texture->width - wallhit;
	}
	else
	{
		wallhit = fmodf((window->ray->h_wallhit_x / BOX_SIZE), 1.0)
			* texture->width;
		if (!window->ray->is_looking_up)
			wallhit = texture->width - wallhit;
	}
	return (wallhit);
}

mlx_texture_t	*findtexture(t_window *window)
{
	if (window->ray->is_vertical == 1)
	{
		if (!window->ray->is_looking_right)
			return (window->images->texture_w);
		else
			return (window->images->texture_e);
	}
	else
	{
		if (window->ray->is_looking_up)
			return (window->images->texture_n);
		else
			return (window->images->texture_s);
	}
}

uint32_t	shading(t_window *window, uint32_t color)
{
	double		shading_factor;
	int			red;
	int			green;
	int			blue;

	shading_factor = 1.5 - (window->ray->distance / 1000);
	if (shading_factor < 0.2)
		shading_factor = 0.2;
	red = ((color >> 24) & 0xFF) * shading_factor;
	green = ((color >> 16) & 0xFF) * shading_factor;
	blue = ((color >> 8) & 0xFF) * shading_factor;
	color = (red << 24) | (green << 16) | (blue << 8) | (color & 0xFF);
	return (color);
}

void	paintwall(t_window *window, int top, int bottom, uint32_t color)
{
	mlx_texture_t	*texture;
	uint32_t		*pixel;
	double			wallhit;
	double			pixely;
	double			move;

	color = 0;
	texture = findtexture(window);
	pixel = (uint32_t *)texture->pixels;
	wallhit = getwallhit(window, texture);
	move = texture->height / window->ray->wall_height;
	pixely = (top - (SCREEN_HEIGHT / 2) + (window->ray->wall_height / 2))
		* move;
	if (pixely < 0)
		pixely = 0;
	while (top < bottom)
	{
		color = revbytes(pixel[(int)wallhit + (int)pixely * texture->width]);
		color = shading(window, color);
		mlx_put_pixel(window->images->image, window->ray->index, top++, color);
		pixely += move;
	}
}

void	draw_image(t_window *window)
{
	double	top;
	double	bottom;

	window->ray->distance = cos(window->ray->angle - window->cam->rotationx)
		* window->ray->distance;
	window->ray->wall_height = (BOX_SIZE / window->ray->distance)
		* ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2));
	top = (SCREEN_HEIGHT / 2) - (window->ray->wall_height / 2);
	if (top < 0)
		top = 0;
	bottom = (SCREEN_HEIGHT / 2) + (window->ray->wall_height / 2);
	if (bottom > SCREEN_HEIGHT)
		bottom = SCREEN_HEIGHT;
	paintwall(window, top, bottom, 0);
	paintboth(window, top, bottom);
}
