/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:39:34 by guortun-          #+#    #+#             */
/*   Updated: 2024/01/31 18:59:59 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	thinking(t_philo *philo)
{
	if (!(dead(philo)))
	{
		print_message(philo, "is thinking");
		return (0);
	}
	return (-1);
}
