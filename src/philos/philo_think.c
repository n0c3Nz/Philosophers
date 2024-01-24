/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:39:34 by guortun-          #+#    #+#             */
/*   Updated: 2024/01/24 18:17:22 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	thinking(t_philo *philo)
{
	int long	ms;

	if (!(dead(philo)))
	{
		ms = (get_time() - philo->data->start);
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms\t%d is thinking\n", ms, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		return (0);
	}
	return (-1);
}
