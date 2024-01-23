/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:25 by guortun-          #+#    #+#             */
/*   Updated: 2024/01/22 21:08:50 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./include/philosophers.h"

static int	are_digits(int argc, char **argv)
{
	int i;
	int j;

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
	return(0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (!are_digits(argc, argv))
		return (error("Bad arguments"));
	data = init_data(argc, argv);
	pthread_t philo_thread[data->philo_count];
	int i = 0;
	while (i < data->philo_count)
	{
		pthread_create(&philo_thread[i], NULL, &philo_routine, (void *)&data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->philo_count)
	{
		pthread_join(philo_thread[i], NULL);
		i++;
	}
	i = 0;
	/*if (data->dead == 1)
	{*/
	while (i < data->philo_count)
	{
		//pthread_detach(philo_thread[i]);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	//}
	printf("All philosophers are full\n");
	return (0);
}
