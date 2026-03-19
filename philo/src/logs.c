/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalonso <maalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:14:56 by maalonso          #+#    #+#             */
/*   Updated: 2026/03/19 15:14:57 by maalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(t_philo *philo, char *status)
{
	long	time;

	pthread_mutex_lock(&philo->data->write_lock);
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->simulation_end == 1 && ft_strncmp(status, "died", 4) != 0)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		pthread_mutex_unlock(&philo->data->write_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	time = get_time() - philo->data->start_time;
	printf("%ld %d %s\n", time, philo->id, status);
	pthread_mutex_unlock(&philo->data->write_lock);
}
