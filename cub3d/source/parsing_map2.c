/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:03:56 by femoreno          #+#    #+#             */
/*   Updated: 2025/06/06 09:50:50 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	inicialice_texture_color(t_window *window)
{
	window->images->texture_n = NULL;
	window->images->texture_s = NULL;
	window->images->texture_e = NULL;
	window->images->texture_w = NULL;
	window->map->map_start = 0;
	window->map->player = 0;
}

void	save_map(t_window *window, int fd, char *line)
{
	int	rows;

	rows = 0;
	close(fd);
	fd = open(window->name, O_RDONLY);
	if (fd == -1)
		error(window, "fallo al abrir archivo con open");
	while (rows < window->map->map_start)
	{
		line = get_next_line(fd);
		free(line);
		rows++;
	}
	rows = 0;
	while (rows < window->map->rows)
	{
		window->map->map[rows] = get_next_line(fd);
		rows++;
	}
	window->map->map[rows] = NULL;
}

void	parsing_map2(t_window *window, int fd)
{
	int		rows;
	char	*line;

	rows = 0;
	line = get_next_line(fd);
	while (line != NULL && *line == '\n')
	{
		free(line);
		line = get_next_line(fd);
		window->map->map_start++;
	}
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		rows++;
	}
	window->map->rows = rows;
	window->map->map = (char **)calloc(rows + 1, sizeof(char *));
	if (window->map->map == NULL)
		error(window, "Error al reservar memoria para el mapa");
	save_map(window, fd, line);
	parsing_map3(window);
}
