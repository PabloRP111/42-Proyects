/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:39:45 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/18 08:03:04 by prosas-p         ###   ########.fr       */
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

static void	convert_to_str(char *numb, int n, int neg, int size)
{
	int	i;

	numb[size] = '\0';
	if (neg)
		numb[0] = '-';
	i = size - 1;
	while (n != 0)
	{
		numb[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*numb;
	int		neg;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	size = get_size(n) + neg + 1;
	numb = (char *)malloc(sizeof(char) * size);
	if (!numb)
		return (0);
	convert_to_str(numb, n, neg, size - 1);
	return (numb);
}

/*
int main()
{
    int num = 0;
    char *result = ft_itoa(num);

    if (result != NULL)
    {
        printf("Integer: %d, String: %s\n", num, result);
        free(result);
    }
    else
    {
        printf("Error: ft_itoa devuelve NULL");
    }
    return (0);
}
*/
