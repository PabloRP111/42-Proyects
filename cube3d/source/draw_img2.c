/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:56:21 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/06 07:46:05 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	paintboth(t_window *window, int top, int bottom)
{
	int	i;

	i = 0;
	while (i < top)
		mlx_put_pixel(window->images->image, window->ray->index, i++,
			window->images->rgb[COLOR_C]);
	i = bottom;
	while (i < SCREEN_HEIGHT)
		mlx_put_pixel(window->images->image, window->ray->index, i++,
			window->images->rgb[COLOR_F]);
}

int	revbytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}
