/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 02:57:33 by guortun-          #+#    #+#             */
/*   Updated: 2024/01/23 00:58:04 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_eat_count(t_philo *philo)
{
	if (philo->data->must_eat_count >= 0)
	{
		if (philo->eat_count < philo->data->must_eat_count)
			return(0);
		else
			return(1);
	}
	return(0);
}

void	*philo_routine(void *dat)
{
	t_philo	*philo;

	philo = (t_philo *)dat;
	while (philo->data->dead == 0 && is_eat_count(philo) == 0)
	{
		if (philo->data->philo_count % 2 == 0 && philo->id % 2 == 0)
			usleep(300);
		else if (philo->data->philo_count % 2 != 0 && philo->id % 2 != 0 && philo->id != 1)
			usleep(300);
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

	if (!(dead(philo)))
	{
		philo->state = SLEEP;
		ms = (get_time() - philo->data->start);
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
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		if (!(dead(philo)))
		{
			ms = (get_time() - philo->data->start);
			pthread_mutex_lock(&philo->data->print);
			printf("%ldms\t%d has taken a fork\n", ms, philo->id);
			//pthread_mutex_unlock(&philo->data->print);
			//pthread_mutex_lock(&philo->data->print);
			printf("%ldms\t%d has taken a fork\n", ms, philo->id);
			pthread_mutex_unlock(&philo->data->print);
			philo->state = EAT;
			pthread_mutex_lock(&philo->data->print);
			printf("%ldms\t%d is eating\n", ms, philo->id);
			pthread_mutex_unlock(&philo->data->print);
			powernap(philo->data->time_to_eat);
			philo->last_eat = get_time() - philo->data->start;
			philo->eat_count++;
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			return (0);
		}
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
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
	return (-1);
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
	if ((ms - philo->last_eat) > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->dead_mutex);
		philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->dead_mutex);
		philo->state = DEAD;
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms\t%d died\n", ms, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		return (1);
	}
	return (0);
}
//!TODO: Comprobar por qué son diferentes los siguientes valores: ✅
// ./Philosophers 4 700 500 200 (añade + 100 ms delay en la muerte)
// ./Philosophers 4 700 200 500 (no añade delay en la muerte)
//~> Era porque tenía mal el orden de los mutex en algunas funciones.
//~> Ahora ya no hay delay en la muerte. Sí, si que hay xdd.
//!TODO: Desarrollar el flow con la variable must_eat_count
//!TODO: Mirar los detach, los mutex destroy y los mallocs. (mira frees también) ✅

// ESPEFICIANDO MUST_EAT_COUNT
// NUMEROS PARES E IMPARES
// SI EL PRIMERO ES MAS GRANDE HACE BIEN LOS PARES (60 ms de diff maximo) y hace bien impares con +70ms de diff
// SI EL SEGUNDO ES MAS GRANDE