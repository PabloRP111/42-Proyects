/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_boy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:50:47 by prosas-p          #+#    #+#             */
/*   Updated: 2024/08/29 11:41:37 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*lonely_philo(void *arg)
{
	t_chair	*philo;
	int		im_dead;

	im_dead = 0;
	philo = (t_chair *)arg;
	philo->id = 1;
	pthread_mutex_lock(&(philo->fork));
	print_lock(philo, "is taking a left fork", 1);
	while (im_dead == 0)
	{
		pthread_mutex_lock(&philo->idata->deadlock);
		if (philo->idata->deads == 1)
			im_dead = 1;
		pthread_mutex_unlock(&philo->idata->deadlock);
	}
	pthread_mutex_unlock(&(philo->fork));
	return (NULL);
}

void	*vigilant(void *arg)
{
	t_chair			*philo;

	philo = (t_chair *)arg;
	while (1)
	{
		if ((get_milisecs(&philo->last_eat) >= philo->idata->t_d))
		{
			pthread_mutex_lock(&(philo->idata->deadlock));
			pthread_mutex_lock(&(philo->idata->wrt_lock));
			printf(RED "\n%ld %d %s\n" RESET,
				get_milisecs(&philo->idata->p_time), philo->id, "is dead");
			philo->idata->deads = 1;
			pthread_mutex_unlock(&(philo->idata->wrt_lock));
			pthread_mutex_unlock(&(philo->idata->deadlock));
			return (NULL);
		}
	}
	return (NULL);
}

int	lonely_boy(t_table *i_data)
{
	t_chair		philo;
	pthread_t	watchmen;

	memset(&philo, 0, sizeof(t_chair));
	philo.idata = i_data;
	if (gettimeofday(&philo.idata->p_time, NULL) != 0)
		return (printf("Error getting time"), 0);
	if (gettimeofday(&philo.last_eat, NULL) != 0)
		return (printf("Error getting time"), 0);
	if ((pthread_mutex_init(&philo.fork, NULL) != 0)
		|| (pthread_mutex_init(&philo.idata->wrt_lock, NULL) != 0)
		|| (pthread_mutex_init(&philo.idata->deadlock, NULL) != 0))
		return (printf("Error at inits mutex"), 0);
	if (pthread_create(&philo.philo, NULL, lonely_philo, &philo) != 0)
		return (printf("Error create thread"), 0);
	if (pthread_create(&watchmen, NULL, vigilant, &philo) != 0)
		return (printf("Error create watchmen"), 0);
	if (pthread_join(watchmen, NULL) != 0)
		return (printf("Error wait watchmen"), 0);
	if (pthread_join(philo.philo, NULL) != 0)
		return (printf("Error wait philo"), 0);
	pthread_mutex_destroy(&philo.fork);
	pthread_mutex_destroy(&philo.idata->deadlock);
	pthread_mutex_destroy(&philo.idata->wrt_lock);
	return (1);
}
