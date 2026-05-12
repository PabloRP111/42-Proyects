/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:21:28 by prosas-p          #+#    #+#             */
/*   Updated: 2024/01/04 11:26:46 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size2(unsigned int n)
{
	int	size;
	int	mult;

	size = 1;
	mult = 1;
	while (n / mult > 9)
	{
		size++;
		mult *= 10;
	}
	return (size);
}

void	get_str2(unsigned int n, char *numb, int i, int size)
{
	if (n == 0)
		numb[0] = '0';
	numb[size] = '\0';
	i = size - 1;
	while (n != 0)
	{
		numb[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
}

void	ft_putunsignbr(unsigned int n, int fd, int *nchars)
{
	char	numb[12];
	int		i;
	int		size;

	i = 0;
	size = get_size2(n);
	get_str2(n, numb, i, size);
	while (numb[i] != '\0')
	{
		ft_putchar_fd(numb[i++], fd, nchars);
	}
}
