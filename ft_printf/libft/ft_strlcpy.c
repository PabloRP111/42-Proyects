/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:16:50 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/12 16:57:16 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (dstsize == 0)
		return (i);
	while (src[j] != '\0' && j < dstsize - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
/*
int main(void)
{
    char src[] = "Mundo ";
    char dst[20] = "Hola";
    char dst2[20] = "Hola ";

    printf("1 %lu\n", strlcpy(dst, src, 5));
    printf("2 %s\n", dst);
    printf("\n3 %lu\n", ft_strlcpy(dst2, src, 5));
    printf("4 %s\n", dst2);
    return (0);
}*/
