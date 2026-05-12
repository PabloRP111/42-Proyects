/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:50:17 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/18 12:27:11 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptstr;
	int		i;

	ptstr = (char *) str;
	while (c > 255)
		c -= 256;
	i = 0;
	while (ptstr[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (ptstr[i] == c)
			return (&ptstr[i]);
		i--;
	}
	return (0);
}

/*
int	main(void)
{
	char	str[] = "Mapa";
	printf("%s",ft_strrchr(str, '\0'));
	printf("\n%s",strrchr(str, '\0'));
	return (0);
}
*/
