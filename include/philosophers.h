/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:11:20 by guortun-          #+#    #+#             */
/*   Updated: 2024/01/24 17:32:50 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define EAT 0
# define SLEEP 1
# define THINK 2
# define FORK 3
# define DEAD 4

/*	COLORS	*/
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

#define DEBUG_TRACE_ENTER printf("Entrando a la función %s\n", __func__);
#define DEBUG_TRACE_EXIT printf("Saliendo de la función %s\n", __func__);

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				last_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				dead;
	int				full_philos;
	long int		start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t dead_mutex;
	t_philo			*philos;
}				t_data;

/*		BASIC FUNCS		*/
ssize_t		ft_strlen(const char *str);
int			ft_error(char *str);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			error(char *str);
/*		PHILOS FUNCS		*/
long int	get_time(void);
t_data		*init_data(int argc, char **argv);
void		*philo_routine(void *date);
int			is_eat_count(t_philo *philo);
/*		PHILOS ACTIONS		*/
int			sleeping(t_philo *philo);
int			eating(t_philo *philo);
int			thinking(t_philo *philo);
int			dead(t_philo *philo);
void		powernap(int ms);
/*		TESTS		*/

# endif