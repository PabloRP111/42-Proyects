/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:35:27 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/12 16:58:30 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(unsigned int n)
{
	int	nbool;

	nbool = 1;
	if (!(n >= 0 && n <= 127))
		nbool = 0;
	return (nbool);
}

/*
int	main(void)
{
	int n;

	n = 128;
	printf("%d", ft_isascii(n));
	printf("%d", isascii(n));
	return (0);
}*/
