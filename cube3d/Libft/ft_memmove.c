/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:15:16 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/14 18:55:24 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	if (d < s || d >= s + n)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n-- > 0)
			*(--d) = *(--s);
	}
	return (dest);
}

/*
int main(void) {
    char src[] = "perro";
    char dest[6];

    char *start = src + 2;
    strcpy(dest, start);
    ft_memmove(dest, src, 17);
    printf("%s", src);

    return 0;
}*/