/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:44:12 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/12 18:29:59 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*pt;

	pt = str;
	while (n-- > 0)
		*pt++ = '\0';
}

/*
int	main(void)
{
	char	str[]="1234567890 Esto es el número bytes";
	char	str2[]="1234567890 Esto es el número bytes";

	bzero(str, 4);
	ft_bzero(str2, 4);

	printf("1 %s$", str);
	printf("\n2 %s$", str2);
	return (0);
}
*/
