/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femoreno <femoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:20:44 by prosas-p          #+#    #+#             */
/*   Updated: 2024/11/25 17:01:00 by femoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s && s[n] != '\0')
		n++;
	return (n);
}

size_t	ft_strlenc(const char *s, char c)
{
	size_t	n;

	n = 0;
	while (s && s[n] && s[n] != c)
		n++;
	return (n);
}
