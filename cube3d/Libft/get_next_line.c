/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:10:08 by prosas-p          #+#    #+#             */
/*   Updated: 2024/10/11 16:49:14 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*end_line_nextl(char **back, char **readed)
{
	char	*aux;

	if (*back != NULL)
	{
		if ((*back[0] != '\0') && (*back[0] != '\n'))
		{
			aux = ft_strdup_nextl(back);
			free_fail_nextl(readed, back);
			return (aux);
		}
	}
	free_fail_nextl(readed, NULL);
	return (NULL);
}

void	get_back_nextl(char **back, char **line, char **readed)
{
	char	*aux;
	int		i;

	i = 0;
	aux = NULL;
	free_fail_nextl(readed, NULL);
	while ((line[0][i] == back[0][i]) && (line[0][i] != '\0'))
		i++;
	if (back[0][i] != '\0')
		aux = ft_substr_nextl(*back, i, (ft_strlen_nextl(*back, 0) - i));
	free_fail_nextl(back, NULL);
	*back = aux;
}

char	*get_line_nextl(char **back)
{
	char	*line;
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strdup_nextl(back);
	if (aux != NULL)
	{
		line = malloc(ft_strlen_nextl(aux, 0) + 1);
		if (!line)
			return (free_fail_nextl(back, NULL));
		while ((i == 0 || (aux[i - 1] != '\n')) && (aux[i] != '\0'))
		{
			line[i] = aux[i];
			i++;
		}
		line[i] = '\0';
		free_fail_nextl(&aux, NULL);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*back[4096];
	char		*readed;
	char		*line;
	int			bytes_reades;

	if (fd < 0)
		return (NULL);
	line = NULL;
	bytes_reades = 1;
	readed = (char *)malloc(BUFFER_SIZE + 1);
	if (readed == NULL)
		return (free_fail_nextl(&back[fd], NULL));
	while (back[fd] == NULL || ft_strlen_nextl(back[fd], 1) == 0)
	{
		bytes_reades = read(fd, readed, BUFFER_SIZE);
		if (bytes_reades == -1)
			return (free_fail_nextl(&back[fd], &readed));
		readed[bytes_reades] = '\0';
		if (bytes_reades == 0)
			return (end_line_nextl(&back[fd], &readed));
		back[fd] = ft_strjoin_nextl(&back[fd], &readed);
	}
	line = get_line_nextl(&back[fd]);
	get_back_nextl(&back[fd], &line, &readed);
	return (line);
}
