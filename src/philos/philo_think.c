/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:39:34 by guortun-          #+#    #+#             */
/*   Updated: 2024/02/01 22:34:08 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	thinking(t_philo *philo)
{
	int long	ms;

	ms = (get_time() - philo->data->start);
	if (!(dead(philo)))
	{
		print_message(philo, "is thinking", ms);
		return (0);
	}
	return (-1);
}
