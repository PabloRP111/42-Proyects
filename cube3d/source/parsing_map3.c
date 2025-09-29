/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:32:56 by femoreno          #+#    #+#             */
/*   Updated: 2025/05/12 17:34:00 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	is_caracter_valid(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& c != ' ' && c != '\n' && c != '\0')
		return (1);
	return (0);
}

void	invalid_caracter(t_window *window, int i, int j)
{
	if (window->map->map[i][j] != '0' && window->map->map[i][j] != '1'
		&& window->map->map[i][j] != 'N' && window->map->map[i][j] != 'S'
		&& window->map->map[i][j] != 'E' && window->map->map[i][j] != 'W')
		error(window, "Error: caracter invalido en el mapa");
}

void	map_is_valid(t_window *window, int i, int j)
{
	invalid_caracter(window, (i + 1), j);
	invalid_caracter(window, i, (j + 1));
	invalid_caracter(window, (i + 1), (j + 1));
	invalid_caracter(window, (i - 1), j);
	invalid_caracter(window, i, (j - 1));
	invalid_caracter(window, (i - 1), (j - 1));
	invalid_caracter(window, (i + 1), (j - 1));
	invalid_caracter(window, (i - 1), (j + 1));
	if (window->map->map[i][j] == 'N' || window->map->map[i][j] == 'S'
		|| window->map->map[i][j] == 'E' || window->map->map[i][j] == 'W')
	{
		window->map->player_x_pos = j;
		window->map->player_y_pos = i;
		window->map->player++;
		window->map->orientation = window->map->map[i][j];
		if (window->map->player != 1)
			error(window, "Error: hay mas de un jugador");
	}
}

void	parsing_map3(t_window *window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (window->map->map[i])
	{
		j = 0;
		while (window->map->map[i][j])
		{
			if (is_caracter_valid(window->map->map[i][j]) == 0)
			{
				if (window->map->map[i][j] == 'N'
					|| window->map->map[i][j] == 'S'
					|| window->map->map[i][j] == 'E'
					|| window->map->map[i][j] == 'W'
					|| window->map->map[i][j] == '0')
					map_is_valid(window, i, j);
			}
			else
				error(window, "Error: el mapa no es valido");
			j++;
		}
		i++;
	}
}
