/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:35:22 by guortun-          #+#    #+#             */
/*   Updated: 2024/03/26 12:35:07 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	lock_forks(t_philo *philo)
{
	int long	ms;

	pthread_mutex_lock(philo->left_fork);
	ms = (get_time() - philo->data->start);
	print_message(philo, "has taken a fork", ms);
	ms = (get_time() - philo->data->start);
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, "has taken a fork", ms);
}

void	print_message(t_philo *philo, const char *message, int long ms)
{
	pthread_mutex_lock(&philo->data->print);
	if (!(philo->data->print_ok))
	{
		printf("%ld\t%d %s\n", ms, philo->id, message);
		pthread_mutex_unlock(&philo->data->print);
	}
	else
		pthread_mutex_unlock(&philo->data->print);
}

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
	lock_forks(philo);
	ms = (get_time() - philo->data->start);
	if (self_dead(philo, ms))
		return (1);
	print_message(philo, "is eating", ms);
	powernap(philo->data->time_to_eat);
	philo->last_eat = ms;
	unlock_forks(philo);
	philo->eat_count++;
	return (0);
}
