/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:39:39 by guortun-          #+#    #+#             */
/*   Updated: 2024/02/01 22:33:31 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dead(t_philo *philo)
{
	int long	ms;

	ms = (get_time() - philo->data->start);
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	else
		pthread_mutex_unlock(&philo->data->dead_mutex);
	if ((ms - philo->last_eat) > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->dead_mutex);
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->dead_mutex);
		print_message(philo, "died", ms);
		return (1);
	}
	return (0);
}
