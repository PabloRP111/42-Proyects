/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 07:51:21 by prosas-p          #+#    #+#             */
/*   Updated: 2024/09/04 17:55:15 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_vals(t_table *i_data, int *i)
{
	*i = -1;
	i_data->deads = 0;
	if (pthread_mutex_init(&(i_data->deadlock), NULL) != 0)
		return (printf("\nInit deadlock\n"), 0);
	if (pthread_mutex_init(&(i_data->padlock), NULL) != 0)
		return (printf("\nInit padlock\n"), 0);
	if (pthread_mutex_init(&(i_data->wrt_lock), NULL) != 0)
		return (printf("\nInit write lock\n"), 0);
	if (pthread_mutex_init(&(i_data->start_lock), NULL) != 0)
		return (printf("\nInit start lock\n"), 0);
	return (1);
}

void	end_threads(t_chair *philos)
{
	int	i;
	int	n_p;

	i = 0;
	n_p = philos->idata->n_p;
	while (i < n_p)
	{
		if (pthread_join(philos[i].philo, NULL) != 0)
			break ;
		i++;
	}
	i = 0;
	while (i < n_p)
	{
		if ((pthread_mutex_destroy(&(philos[i].fork)) != 0)
			|| (pthread_mutex_destroy(&(philos[i].eat_lock)) != 0))
			break ;
		i++;
	}
	pthread_mutex_destroy(&(philos->idata->padlock));
	pthread_mutex_destroy(&(philos->idata->deadlock));
	pthread_mutex_destroy(&(philos->idata->wrt_lock));
	pthread_mutex_destroy(&(philos->idata->start_lock));
	free(philos);
}

void	free_and_exit(t_chair *philos, char *error)
{
	printf("\n%s\n", error);
	end_threads(philos);
}
