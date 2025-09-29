/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros_and_frees.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:32:15 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/06 10:40:32 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	free_textures_and_image(t_window *window)
{
	if (!window)
		return ;
	if (window->images)
	{
		if (window->images->texture_n != NULL)
			mlx_delete_texture(window->images->texture_n);
		if (window->images->texture_s != NULL)
			mlx_delete_texture(window->images->texture_s);
		if (window->images->texture_e != NULL)
			mlx_delete_texture(window->images->texture_e);
		if (window->images->texture_w != NULL)
			mlx_delete_texture(window->images->texture_w);
		window->images->texture_n = NULL;
		window->images->texture_s = NULL;
		window->images->texture_e = NULL;
		window->images->texture_w = NULL;
	}
	if (window->images && window->images->image)
	{
		mlx_delete_image(window->mlx, window->images->image);
		window->images->image = NULL;
	}
	free(window->images);
	window->images = NULL;
}

void	free_map(t_window *window)
{
	int	i;

	if (!window || !window->map || !window->map->map)
		return ;
	i = 0;
	while (window->map->map[i] != NULL)
	{
		free(window->map->map[i]);
		i++;
	}
	free(window->map->map);
	free(window->map);
	window->map = NULL;
}

void	error(t_window	*window, char *text)
{
	while (*text)
		write(2, text++, 1);
	write(2, "\n", 1);
	if (window)
	{
		window->end_game = 1;
		if (window->images)
			free_textures_and_image(window);
		if (window->map)
			free_map(window);
		if (window->cam)
			free(window->cam);
		if (window->name)
			free(window->name);
		window->name = NULL;
		window->cam = NULL;
		window->ray = NULL;
		if (window->mlx)
		{
			mlx_close_window(window->mlx);
			mlx_terminate(window->mlx);
		}
	}
	exit(EXIT_FAILURE);
}

void	end_game(void *param)
{
	t_window	*window;

	window = (t_window *)param;
	window->end_game = 1;
	mlx_close_window(window->mlx);
	free_map(window);
	free_textures_and_image(window);
	if (window->cam)
		free(window->cam);
	if (window->name)
		free(window->name);
	window->name = NULL;
	window->cam = NULL;
	window->ray = NULL;
}
