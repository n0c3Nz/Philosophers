/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:25 by guortun-          #+#    #+#             */
/*   Updated: 2024/01/24 19:11:59 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philosophers.h"

static int	are_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 5 || argc == 6)
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (!ft_isdigit(argv[i][j]))
					return (0);
				j++;
			}
			i++;
		}
		return (1);
	}
	return (0);
}

static pthread_t	*init_pthreads(t_data *data)
{
	pthread_t	*philo_thread;

	philo_thread = malloc(data->philo_count * sizeof(pthread_t));
	if (!philo_thread)
		return (NULL);
	return (philo_thread);
}

static void	free_data(t_data *data, pthread_t *philo_thread)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	free(data->philos);
	data->philos = NULL;
	free(data->forks);
	data->forks = NULL;
	free(data);
	data = NULL;
	free(philo_thread);
	philo_thread = NULL;
}

int	main(int argc, char **argv)
{
	t_data		*data;
	pthread_t	*philo_thread;
	int			i;

	if (!are_digits(argc, argv))
		return (error("Bad arguments"));
	if (ft_atoi(argv[1]) < 2)
		return (error("One Philosopher can't eat alone"));
	data = init_data(argc, argv);
	philo_thread = init_pthreads(data);
	i = 0;
	while (i < data->philo_count)
	{
		pthread_create(&philo_thread[i], NULL, &philo_routine,
			(void *)&data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->philo_count)
	{
		pthread_join(philo_thread[i], NULL);
		i++;
	}
	free_data(data, philo_thread);
	return (0);
}
