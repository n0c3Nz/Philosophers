/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:40:23 by guortun-          #+#    #+#             */
/*   Updated: 2024/02/04 22:30:01 by guortun-         ###   ########.fr       */
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
	if (philo->id % 2 == 0)
		usleep(50);
	while (!(dead(philo)) && is_eat_count(philo) == 0)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	pthread_exit(NULL);
}
