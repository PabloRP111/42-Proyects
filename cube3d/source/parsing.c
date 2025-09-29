/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:55:16 by femoreno          #+#    #+#             */
/*   Updated: 2025/06/06 09:53:01 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	map_name(t_window	*window, char *name)
{
	int	i;

	i = ft_strlen(name);
	while (name[--i] != '.')
		if (i == 0)
			error(window,
				"Archivo de mapa no compatible, falta extension .cub");
	if (name[i + 1] != 'c' || name[i + 2] != 'u' || name[i + 3] != 'b'
		|| name[i + 4] != '\0')
		error(window,
			"Archivo de mapa no compatible, la extension no es .cub");
}

void	parsing(int argc, char **argv, t_window	*window)
{
	if (argc != 2)
		error(window, "Numero de argumentos incorrecto");
	window->name = strdup(argv[1]);
	if (!window->name)
		error(window, "Error: strdup falló");
	map_name(window, window->name);
	parsing_map(window, 0);
}
