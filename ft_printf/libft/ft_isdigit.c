/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:28:37 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/12 16:15:25 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_isdigit(unsigned int c)
{
	int	nbool;

	nbool = 0;
	if (c >= '0' && c <= '9')
		nbool = 1;
	return (nbool);
}

/*
int	main()
{
	printf("%d",ft_isdigit(48));
	printf("\n%d",isdigit(48));
	return (0);
}*/
