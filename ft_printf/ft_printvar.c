/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:21:39 by prosas-p          #+#    #+#             */
/*   Updated: 2024/01/04 11:46:22 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexa(unsigned int n, char typehex, int *nchars)
{
	char	*hexa;
	int		i;

	hexa = "0123456789ABCDEF";
	i = 1;
	if (typehex == 'x')
		hexa = "0123456789abcdef";
	while (n / i >= 16)
		i *= 16;
	while (i > 0)
	{
		ft_putchar_fd(hexa[n / i], 1, nchars);
		n %= i;
		i /= 16;
	}
}

void	ft_printhexal(unsigned long long n, int *nchars)
{
	unsigned long long		i;
	char					*hexa;

	hexa = "0123456789abcdef";
	i = 1;
	while (n / i >= 16)
		i *= 16;
	while (i > 0)
	{
		ft_putchar_fd(hexa[n / i], 1, nchars);
		n = n % i;
		i /= 16;
	}
}

void	ft_printpointer(unsigned long long p, int *nchars)
{
	ft_putstr_fd("0x", 1, nchars);
	ft_printhexal(p, nchars);
}

void	ft_unsigned(va_list args, int *nchars)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_putunsignbr(n, 1, nchars);
}

void	ft_printvar(char *format, va_list args, int *pos, int *nchars)
{
	if (format[*pos] == '%')
		ft_putchar_fd('%', 1, nchars);
	else if (format[*pos] == 'c')
		ft_putchar_fd(va_arg(args, int), 1, nchars);
	else if (format[*pos] == 's')
		ft_putstr_fd(va_arg(args, char *), 1, nchars);
	else if (format[*pos] == 'u')
		ft_unsigned(args, nchars);
	else if (format[*pos] == 'd' || format[*pos] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, nchars);
	else if (format[*pos] == 'x' || format[*pos] == 'X')
		ft_printhexa(va_arg(args, int), format[*pos], nchars);
	else if (format[*pos] == 'p')
		ft_printpointer(va_arg(args, unsigned long long), nchars);
	else
		*nchars = -1;
}
