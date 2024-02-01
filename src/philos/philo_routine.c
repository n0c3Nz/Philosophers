/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:40:23 by guortun-          #+#    #+#             */
/*   Updated: 2024/02/01 22:21:40 by guortun-         ###   ########.fr       */
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
		if (philo->data->philo_count % 2 == 0 && philo->id % 2 == 0)
			usleep(250);
		else if (philo->data->philo_count % 2 != 0
			&& philo->id % 2 == 0)
			usleep(250);//printf("xd\n");
	while (!(dead(philo)) && is_eat_count(philo) == 0)
	{
		if (eating(philo) == -1)
			break ;
		if (sleeping(philo) == -1)
			break ;
		if (thinking(philo) == -1)
			break ;
	}
	pthread_exit(NULL);
}
