/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:08:47 by prosas-p          #+#    #+#             */
/*   Updated: 2024/05/23 10:16:43 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdef.h"

int	ft_isalpha(unsigned int c)
{
	int	nbool;

	nbool = 0;
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		nbool = 1;
	return (nbool);
}
/*
int	main()
{
	printf("%d",ft_isalpha(97));
	printf("\n%d",isalpha(97));
	return (0);
}*/
