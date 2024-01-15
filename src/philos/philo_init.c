#include "../../include/philosophers.h"

long int get_time(void)
{
	struct timeval tiempo;

	return (gettimeofday(&tiempo, NULL), tiempo.tv_usec);
}
static void		set_forks(t_data *data)
{
	int i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}
static void 	set_philos(t_data *data)
{
	int i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].state = THINK;
		data->philos[i].eat_count = 0;
		data->philos[i].last_eat = data->start;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->philo_count];
		data->philos[i].print = &data->print;
		data->philos[i].data = data;
		i++;
	}
}
t_data *init_data(int argc, char **argv)
{
	t_data *data;
	data = (t_data *)malloc(sizeof(t_data));
	data->philo_count = ft_atoi(argv[1]);// Número de philos
	data->time_to_die = ft_atoi(argv[2]);// Tiempo de muerte
	data->time_to_eat = ft_atoi(argv[3]);// Tiempo de comer
	data->time_to_sleep = ft_atoi(argv[4]);// Tiempo de dormir
	data->must_eat_count = -1;
	if (argc == 6)
		data->must_eat_count = ft_atoi(argv[5]);
	data->dead = 0;
	data->full_philos = -1;
	data->start = get_time();
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philo_count);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_count);
	pthread_mutex_init(&data->print, NULL);
	set_forks(data);
	set_philos(data);
	return (data);
}
