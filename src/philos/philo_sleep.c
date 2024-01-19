/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 02:57:33 by guortun-          #+#    #+#             */
/*   Updated: 2024/01/19 17:02:38 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	*philo_routine(void *dat)
{
	t_philo	*philo;

	philo = (t_philo *)dat;
	while (philo->data->dead == 0)
	{
		if (philo->id % 2 == 0){
			usleep(700);
			//usleep(700);
		}
		if (eating(philo) == -1)
			break ;		
		if (sleeping(philo) == -1)
			break ;
		if (thinking(philo) == -1)
			break ;
	}
	pthread_exit(NULL);
}
void powernap(int ms)
{
	long tmp;

	tmp = get_time() + ms;
	while (get_time() < tmp)
	{
		usleep(700);
	}
}
int	sleeping(t_philo *philo)
{
	int long	ms;

	//pthread_mutex_lock(&philo->data->print);
	if (!(dead(philo)))
	{
		//pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_lock(&philo->data->print);
		philo->state = SLEEP;
		ms = (get_time() - philo->data->start);
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms\t%d is sleeping\n", ms, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		powernap(philo->data->time_to_sleep);
		return (0);
	}
	//pthread_mutex_unlock(&philo->data->print);
	return (-1);
}

int	eating(t_philo *philo)
{
	int long	ms;

	if (!(dead(philo)))
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		ms = (get_time() - philo->data->start);
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms\t%d has taken a fork\n", ms, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms\t%d has taken a fork\n", ms, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		philo->state = EAT;
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms\t%d is eating\n", ms, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		philo->last_eat = get_time() - philo->data->start;
		powernap(philo->data->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	return (-1);
}

int	thinking(t_philo *philo)
{
	int long	ms;

	if (!(dead(philo)))
	{
		philo->state = THINK;
		ms = (get_time() - philo->data->start);
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms\t%d is thinking\n", ms, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->print);
	return (-1);
}

int	dead(t_philo *philo)
{
	int long	ms;

	ms = (get_time() - philo->data->start);
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->print);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->print);
	if ((ms - philo->last_eat) > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->print);
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->print);
		philo->state = DEAD;
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms\t%d died\n", ms, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		return (1);
	}
	return (0);
}
//!TODO: Comprobar por qué son diferentes los siguientes valores:
// ./Philosophers 4 700 500 200 (añade + 100 ms delay en la muerte)
// ./Philosophers 4 700 200 500 (no añade delay en la muerte)