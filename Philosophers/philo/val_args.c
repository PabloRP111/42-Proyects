/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:51:47 by prosas-p          #+#    #+#             */
/*   Updated: 2024/09/04 12:22:59 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_uint(const char *str, int i)
{
	long long	num;
	int			digit;

	num = 0;
	if (*str == '\0')
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		digit = *str - '0';
		if (num > (LONG_MAX - digit) / 10)
			return (0);
		num = num * 10 + digit;
		str++;
		if (num < INT_MIN || num > INT_MAX)
			return (0);
	}
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (num < 60 && (i == 2 || i == 3 || i == 4))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
		if (num > INT_MAX)
			return (num / 10);
	}
	return (num);
}

int	val_args(char **argv, int argc, t_table *i_data, int i)
{
	while (i < argc)
	{
		if ((is_uint(argv[i], i) != 1))
		{
			printf("\nBad arguments\n");
			return (0);
		}
		i++;
	}
	memset(i_data, 0, sizeof(t_table));
	i_data->n_p = ft_atoi(argv[1]);
	i_data->t_d = ft_atoi(argv[2]);
	i_data->t_e = ft_atoi(argv[3]);
	i_data->t_s = ft_atoi(argv[4]);
	if (argc == 6)
	{
		i_data->n_meals = ft_atoi(argv[5]);
		if (i_data->n_meals == 0)
			return (printf("All philosophers had eaten 0 times"), 0);
	}
	else
		i_data->n_meals = -1;
	if (i_data->n_p == 1)
		return (lonely_boy(i_data), 0);
	return (1);
}
