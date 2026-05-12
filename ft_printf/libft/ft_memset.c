/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:53:07 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/12 16:56:33 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*pt;

	pt = str;
	while (n-- > 0)
		*pt++ = (unsigned char) c;
	return (str);
}

/*
int main (void)
{
	char	str[]="1234567890 Esto es el número bytes";
	int 	c;

	c = 'A';
	printf("%s\n", memset(str, c, 0));
	printf("%s", ft_memset(str, c, 0));
	return (0);
}*/
