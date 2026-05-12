/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:09:10 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/18 12:26:56 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptstr;
	int		i;

	ptstr = (char *) str;
	while (c > 255)
		c -= 256;
	i = 0;
	while (ptstr[i] != '\0')
	{
		if (ptstr[i] == c)
			return (&ptstr[i]);
		i++;
	}
	if (ptstr[i] == c)
		return (&ptstr[i]);
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "teste";
	printf("%s",ft_strchr(str, '0'));
	printf("\n%s",strchr(str, '0'));
	return (0);
}
*/
