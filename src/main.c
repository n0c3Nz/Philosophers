/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:25 by guortun-          #+#    #+#             */
/*   Updated: 2024/03/21 16:06:20 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

static void	print_one_philo(void)
{
	printf("0\t1 has taken a fork\n");
	powernap(1000);
	printf("100\t1 died\n");
}

int	main(int argc, char **argv)
{
	t_data		*data;
	pthread_t	*philo_thread;
	int			i;

	if (!are_digits(argc, argv))
		return (error("Bad arguments"));
	if (ft_atoi(argv[1]) < 2)
	{
		print_one_philo();
		return (1);
	}
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
		pthread_join(philo_thread[i++], NULL);
	free_data(data, philo_thread);
	return (0);
}
