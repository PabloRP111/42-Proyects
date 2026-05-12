/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:08:44 by prosas-p          #+#    #+#             */
/*   Updated: 2024/01/04 12:18:07 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		pos;
	int		nchars;

	if (write(1, "", 0) == -1)
		return (-1);
	pos = 0;
	nchars = 0;
	va_start(args, format);
	while (format[pos] != '\0')
	{
		if (format[pos] == '%')
		{
			pos++;
			ft_printvar((char *)format, args, &pos, &nchars);
		}
		else
			ft_putchar_fd(format[pos], 1, &nchars);
		pos++;
	}
	va_end(args);
	return (nchars);
}
/*
int	main(void)
{
	int len;
	//int num = -11;

	len = 0;
	len = ft_printf("Funca? %x ", -42);
	printf("\n%d \n", len);
	len = printf("Funca? %x ", -42);
	printf("\n%d", len);
}
*/