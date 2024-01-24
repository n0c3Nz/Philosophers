/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 02:57:33 by guortun-          #+#    #+#             */
/*   Updated: 2024/01/24 18:17:12 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	sleeping(t_philo *philo)
{
	int long	ms;

	if (!(dead(philo)))
	{
		ms = (get_time() - philo->data->start);
		pthread_mutex_lock(&philo->data->print);
		printf("%ldms\t%d is sleeping\n", ms, philo->id);
		pthread_mutex_unlock(&philo->data->print);
		powernap(philo->data->time_to_sleep);
		return (0);
	}
	return (-1);
}

// ESPEFICIANDO MUST_EAT_COUNT
// NUMEROS PARES E IMPARES
// SI EL PRIMERO ES MAS GRANDE HACE BIEN LOS PARES (60 ms de diff maximo) y hace
// bien impares con +70ms de diff
// SI EL SEGUNDO ES MAS GRANDE

// Tomar el last eat despues de powenap y luego hacer la resta de ms para que se
// printee correctamente.