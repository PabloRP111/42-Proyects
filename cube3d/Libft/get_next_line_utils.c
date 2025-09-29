/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:10:34 by prosas-p          #+#    #+#             */
/*   Updated: 2024/10/11 16:48:35 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_nextl(char *s, unsigned int start, unsigned int len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (start > ft_strlen_nextl(s, 0))
		return (NULL);
	if (len > (ft_strlen_nextl(s, 0) - start))
		len = (ft_strlen_nextl(s, 0) - start);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	while (s[i] != '\0' && i < start)
		i++;
	while (s[i] != '\0' && j < len)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}

char	*free_fail_nextl(char **s1, char **s2)
{
	if (*s1 != NULL)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 != NULL)
	{
		if (*s2 != NULL)
		{
			free(*s2);
			*s2 = NULL;
		}
	}
	return (NULL);
}

char	*ft_strjoin_nextl(char **s1, char **s2)
{
	char	*str;
	int		i;
	int		j;

	if (*s1 == NULL)
		return (ft_strdup_nextl(s2));
	i = 0;
	j = 0;
	str = (char *) malloc((ft_strlen_nextl(*s1, 0)
				+ ft_strlen_nextl(*s2, 0) + 1));
	if (!str)
		return (free_fail_nextl(s1, s2));
	while (s1[0][i] != '\0')
	{
		str[i] = s1[0][i];
		i++;
	}
	while (s2[0][j] != '\0')
	{
		str[i + j] = s2[0][j];
		j++;
	}
	str[i + j] = '\0';
	free_fail_nextl(s1, NULL);
	return (str);
}

unsigned int	ft_strlen_nextl(const char *s, int boolxd)
{
	unsigned int	n;

	n = 0;
	if (s == NULL)
		return (0);
	if (boolxd == 0)
	{
		while (s[n] != '\0')
			n++;
	}
	else if (boolxd == 1)
	{
		while (s[n] != '\0')
		{
			if (s[n] == '\n')
				return (1);
			n++;
		}
		return (0);
	}
	return (n);
}

char	*ft_strdup_nextl(char **s1)
{
	int		len;
	char	*dup;
	int		i;

	len = ft_strlen_nextl(*s1, 0);
	if (len == 0)
		len = 1;
	dup = malloc(len + 1);
	if (!dup)
		return (free_fail_nextl(s1, NULL));
	i = 0;
	while (s1[0][i] != '\0')
	{
		dup[i] = s1[0][i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
