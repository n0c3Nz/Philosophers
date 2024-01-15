/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 02:57:33 by guortun-          #+#    #+#             */
/*   Updated: 2024/01/15 21:03:33 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

/*void	*philo_routine(void *dat)
{
	t_data	*data;
	data = (t_data *)dat;
	while (1){
		sleeping(data);
		eating(data);
	}
	pthread_exit(NULL);
}*/
void	*philo_routine(void *dat)
{
	t_philo	*philo;
	philo = (t_philo *)dat;
	sleeping(philo);
	eating(philo);
	pthread_exit(NULL);
}
int	sleeping(t_philo *philo)
{
	int long	ms;

	philo->state = SLEEP;
	
	pthread_mutex_lock(&philo->data->print);
	ms = (get_time() - philo->data->start) / 1000;
	//printf("%ldms\t%d is sleeping (STATUS: %i) Dormirá: %ld\n", ms, philo->id, philo->state, philo->data->time_to_sleep * 1000);
	printf("%ldms\t%d is sleeping (STATUS: %i)\n", ms, philo->id, philo->state);
	pthread_mutex_unlock(&philo->data->print);
	usleep(philo->data->time_to_sleep * 1000);
	return (0);
}

int	eating(t_philo *philo)
{
	int long	ms;

	philo->state = EAT;
	//pthread_mutex_lock(&philo->data->print);
	//printf("%ldms\t%d has taken a fork\n", ms, philo->id);
	//printf("%ldms\t%d has taken a fork\n", ms, philo->id);
	pthread_mutex_lock(philo->right_fork);
	ms = (get_time() - philo->data->start) / 1000;
	printf("%ldms\t%d is eating (STATUS: %i)\n", ms, philo->id, philo->state);
	pthread_mutex_unlock(philo->right_fork);
	usleep(philo->data->time_to_eat * 1000);
	//pthread_mutex_unlock(philo->right_fork);
	return (0);
}
