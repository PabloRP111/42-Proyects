/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:04:27 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/12 16:58:21 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(unsigned int n)
{
	int	nbool;

	nbool = 1;
	if (!((n >= 'a' && n <= 'z')
			|| (n >= 'A' && n <= 'Z') || (n >= '0' && n <= '9')))
		nbool = 0;
	return (nbool);
}
/*
int	main()
{
	int n;

	n = 90;
	printf("%d", ft_isalnum(n));
	printf("%d", isalnum(n));
	return (0);
}*/
