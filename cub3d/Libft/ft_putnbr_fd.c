/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:28:17 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/18 10:04:39 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	ft_putnbr_fd(int n, int fd)
{
	char	numb[12];
	int		i;
	int		size;

	i = 0;
	if (n >= 0)
	{
		size = get_size(n);
	}
	else
	{
		size = get_size(n * -1);
		size++;
	}
	get_str(n, numb, i, size);
	while (numb[i] != '\0')
	{
		ft_putchar_fd(numb[i++], fd);
	}
}
/*
int	main(void)
{
	int		n;
	int		fd;

	n = -2147483648;
	fd = 1;
	ft_putnbr_fd(n, fd);
	return (0);
}*/
