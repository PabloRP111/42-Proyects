/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:10:08 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/14 18:03:39 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*ptsrc;
	unsigned char		*ptdest;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptdest = (unsigned char *) dst;
	ptsrc = (const unsigned char *) src;
	while (n-- > 0)
		*ptdest++ = *ptsrc++;
	return (dst);
}
/*
int main(void)
{
	char dest[] = "No soy la copia copia";
	char src[] = "No soy la copia copia";
	char dest2[] = "No soy la copia copia";
	
	printf("%s", memcpy(dest2, src, sizeof(src)));
	printf("\n%s", ft_memcpy(dest, src, sizeof(src)));
	return (0);
}*/
