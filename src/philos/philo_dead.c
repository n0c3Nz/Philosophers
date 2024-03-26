/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:39:39 by guortun-          #+#    #+#             */
/*   Updated: 2024/03/21 16:12:28 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_dead(t_philo *philo, int long ms)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->print_ok)
	{
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_lock(&philo->data->print);
	printf("%ld\t%d %s\n", ms, philo->id, "died");
	philo->data->print_ok = 1;
	pthread_mutex_unlock(&philo->data->print);
}

int	self_dead(t_philo *philo, int long ms)
{
	if ((ms - philo->last_eat) >= philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->dead_mutex);
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->dead_mutex);
		print_dead(philo, ms);
		return (1);
	}
	return (0);
}

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
	if (self_dead(philo, ms))
		return (1);
	return (0);
}
