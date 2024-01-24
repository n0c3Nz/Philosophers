/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:35:22 by guortun-          #+#    #+#             */
/*   Updated: 2024/01/24 19:43:22 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_eat_count(t_philo *philo)
{
	if (philo->data->must_eat_count >= 0)
	{
		if (philo->eat_count < philo->data->must_eat_count)
			return (0);
		else
			return (1);
	}
	return (0);
}

int	eating(t_philo *philo)
{
	int long	ms;

	ms = (get_time() - philo->data->start);
	if (!(dead(philo)))
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms\t%d has taken a fork\n", ms, philo->id);
		printf("%ldms\t%d has taken a fork\n", ms, philo->id);
		printf("%ldms\t%d is eating\n", ms, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		philo->last_eat = get_time() - philo->data->start;
		powernap(philo->data->time_to_eat);
		philo->eat_count++;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	return (-1);
}
