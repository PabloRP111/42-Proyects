/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:28:37 by prosas-p          #+#    #+#             */
/*   Updated: 2024/11/04 20:02:30 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

int	ft_isdigit(unsigned int c)
{
	return (c >= '0' && c <= '9');
}

/*
int	main()
{
	printf("%d",ft_isdigit(48));
	printf("\n%d",isdigit(48));
	return (0);
}*/
