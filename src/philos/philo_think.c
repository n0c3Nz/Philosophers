/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:39:34 by guortun-          #+#    #+#             */
/*   Updated: 2024/03/26 12:34:36 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	thinking(t_philo *philo)
{
	int long	ms;

	ms = (get_time() - philo->data->start);
	if (self_dead(philo, ms))
		return (1);
	print_message(philo, "is thinking", ms);
	return (0);
}
