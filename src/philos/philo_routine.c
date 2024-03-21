/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:40:23 by guortun-          #+#    #+#             */
/*   Updated: 2024/03/15 16:54:09 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	powernap(int ms)
{
	long	tmp;

	tmp = get_time() + ms;
	while (get_time() < tmp)
		usleep(700);
}

void	*philo_routine(void *dat)
{
	t_philo	*philo;

	philo = (t_philo *)dat;
	if (philo->id == 1)
	{
		pthread_mutex_lock(&philo->data->print);
		usleep(100);
	}
	else
		pthread_mutex_lock(&philo->data->print);
	pthread_mutex_unlock(&philo->data->print);
	if (philo->id % 2 == 0)
		usleep(75);
	while (!(dead(philo)) && is_eat_count(philo) == 0)
	{
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		thinking(philo);
	}
	pthread_exit(NULL);
}
