/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femoreno <femoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:51:15 by femoreno          #+#    #+#             */
/*   Updated: 2025/06/06 12:34:04 by femoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

char	*del_extra_spaces(t_window *window, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line && line[i] && line[i] == ' ')
		i++;
	if (!line || !line[i])
	{
		free(line);
		error(window, "Error en la transcripcion");
	}
	while (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'
		&& line[j] != '\r' && line[j] != '\v' && line[j] != '\f')
		j++;
	line[j] = '\0';
	return (line + i);
}

void	save_color(char *line, unsigned int *color, t_window *window)
{
	char	**rgb;
	int		i;

	i = 0;
	rgb = ft_split(line, ',');
	while (rgb && rgb[i])
		i++;
	if (i != 3)
		error(window, "Error en el formato RGB");
	i = -1;
	*color = rgb_to_hex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), 255);
	while (rgb && rgb[++i])
	{
		free(rgb[i]);
		rgb[i] = NULL;
	}
	if (rgb)
		free(rgb);
	rgb = NULL;
}

void	save_texture(char *line, t_window *window, mlx_texture_t **texture)
{
	if (*texture != NULL)
		error(window, "Error: una textura se inicializa dos veces");
	*texture = mlx_load_png(line);
	if (!(*texture))
		error(window, "Error: no se pudo cargar la textura");
	else
		printf("texture: %s save correctly\n", line);
}

int	save_texture_color(t_window *window, char *line)
{
	while (line && (*line == ' ' || *line == '\t'
			|| *line == '\r' || *line == '\v' || *line == '\f'))
		line++;
	if (!ft_strncmp("NO ", line, 3))
		return (save_texture(del_extra_spaces(window, line + 3),
				window, &window->images->texture_n), 1);
	else if (!ft_strncmp("SO ", line, 3))
		return (save_texture(del_extra_spaces(window, line + 3),
				window, &window->images->texture_s), 1);
	else if (!ft_strncmp("WE ", line, 3))
		return (save_texture(del_extra_spaces(window, line + 3),
				window, &window->images->texture_w), 1);
	else if (!ft_strncmp("EA ", line, 3))
		return (save_texture(del_extra_spaces(window, line + 3),
				window, &window->images->texture_e), 1);
	else if (!ft_strncmp("F ", line, 2))
		return (save_color(del_extra_spaces(window, line + 2),
				&window->images->rgb[COLOR_F], window), 1);
	else if (!ft_strncmp("C ", line, 2))
		return (save_color(del_extra_spaces(window, line + 2),
				&window->images->rgb[COLOR_C], window), 1);
	else if (*line == '\n')
		return (0);
	error(window, "Incoherencia en la inicialización de texturas y colores");
	return (-1);
}

void	parsing_map(t_window *window, int tc)
{
	int		fd;
	char	*line;

	window->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!window || !window->map)
		error(window, "Error al reservar memoria para la estructura mapa");
	window->images = (t_images *)ft_calloc(1, sizeof(t_images));
	inicialice_texture_color(window);
	if (!window || !window->images)
		error(window, "Error al reservar memoria para la estructura imágen");
	fd = open(window->name, O_RDONLY);
	if (fd == -1)
		error(window, "fallo al abrir archivo con open");
	while (tc < 6)
	{
		line = get_next_line(fd);
		if (!line)
			error(window, "Algo fallo durante la lectura de texturas");
		tc += save_texture_color(window, line);
		free(line);
		line = NULL;
		window->map->map_start++;
	}
	parsing_map2(window, fd);
}
