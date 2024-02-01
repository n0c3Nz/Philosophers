/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:35:22 by guortun-          #+#    #+#             */
/*   Updated: 2024/02/01 23:12:40 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	lock_forks(t_philo *philo, int long ms)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->data->print);
	printf("%ldms\t%d %s\n", ms, philo->id, "Has taken a fork");
	printf("%ldms\t%d %s\n", ms, philo->id, "Has taken a fork");
	pthread_mutex_unlock(&philo->data->print);
	unlock_forks(philo);
}

void	print_message(t_philo *philo, const char *message, int long ms)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ldms\t%d %s\n", ms, philo->id, message);
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

void	eating(t_philo *philo)
{
	int long	ms;

	philo->last_eat = get_time() - philo->data->start;
	ms = (get_time() - philo->data->start);
	lock_forks(philo, ms);
	print_message(philo, "is eating", ms);
	powernap(philo->data->time_to_eat);
	unlock_forks(philo);
	philo->eat_count++;
}
