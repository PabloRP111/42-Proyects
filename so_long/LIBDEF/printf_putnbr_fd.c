/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:28:17 by prosas-p          #+#    #+#             */
/*   Updated: 2024/05/23 13:47:06 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdef.h"

static int	get_size(int n)
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

void	get_str(int n, char *numb, int i, int size)
{
	if (n == -2147483648)
	{
		numb[0] = '-';
		numb[1] = '2';
		n = 147483648;
		i = 2;
		size = 11;
	}
	if (n == 0)
		numb[0] = '0';
	numb[size] = '\0';
	if (n < 0 && n != -2147483648)
	{
		numb[0] = '-';
		n = -n;
	}
	i = size - 1;
	while (n != 0)
	{
		numb[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
}

void	printf_putnbr_fd(int n, int fd, int *nchars)
{
	char	numb[12];
	int		i;
	int		size;

	i = 0;
	if (n >= 0)
		size = get_size(n);
	else
	{
		size = get_size(n * -1);
		size++;
	}
	get_str(n, numb, i, size);
	while (numb[i] != '\0')
	{
		printf_putchar_fd(numb[i++], fd, nchars);
	}
}
