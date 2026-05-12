/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:45:03 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/12 16:17:20 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;

	pt1 = (unsigned char *)s1;
	pt2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*pt1 != *pt2)
			return (*pt1 - *pt2);
		pt1++;
		pt2++;
	}
	return (0);
}
/*
int main()
{
    char str1[] = "Hello";
    char str2[] = "HelloA";

    printf("%d", memcmp(str1, str2, 6));
    printf("%d", ft_memcmp(str1, str2, 6));
    return (0);
}*/
