/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 02:57:33 by guortun-          #+#    #+#             */
/*   Updated: 2024/03/26 12:34:20 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	sleeping(t_philo *philo)
{
	int long	ms;

	ms = (get_time() - philo->data->start);
	print_message(philo, "is sleeping", ms);
	powernap(philo->data->time_to_sleep);
	ms = (get_time() - philo->data->start);
	if (self_dead(philo, ms))
		return (1);
	return (0);
}

// NUMEROS PARES E IMPARES
// SI EL PRIMERO ES MAS GRANDE HACE BIEN LOS PARES (60 ms de diff maximo) y hace
// bien impares con +70ms de diff
// SI EL SEGUNDO ES MAS GRANDE

// Tomar el last eat despues de powenap y luego hacer la resta de ms para que se
// printee correctamente.