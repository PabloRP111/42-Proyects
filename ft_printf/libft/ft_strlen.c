/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:20:44 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/12 17:51:13 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}
/*
int main (void)
{
	char	*str ="123456789";
	char    *str2 ="123456789";

	printf("%lu", strlen(str2));
	printf("%d", ft_strlen(str));
	return (0);
}
*/
