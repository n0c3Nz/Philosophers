/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 02:57:33 by guortun-          #+#    #+#             */
/*   Updated: 2024/01/31 20:21:51 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	sleeping(t_philo *philo)
{
	if (!(dead(philo)))
	{
		print_message(philo, "is sleeping");
		powernap(philo->data->time_to_sleep);
		return (0);
	}
	return (-1);
}

// NUMEROS PARES E IMPARES
// SI EL PRIMERO ES MAS GRANDE HACE BIEN LOS PARES (60 ms de diff maximo) y hace
// bien impares con +70ms de diff
// SI EL SEGUNDO ES MAS GRANDE

// Tomar el last eat despues de powenap y luego hacer la resta de ms para que se
// printee correctamente.