/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:23:58 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/12 16:57:12 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (dstsize <= i)
		j += dstsize;
	else
		j += i;
	while (src[k] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (j);
}

/*
int main(void)
{
    char    src[] = "World : )";
    char    dest[20] = "Hello ";
    char    dest2[20] = "Hello ";

    printf("1 %lu\n", strlcat(dest, src, 15));
    printf("2 %lu\n", ft_strlcat(dest2, src, 15));
    printf("3 %s\n", dest);
    printf("4 %s\n",dest2);
    return (0);
}*/
