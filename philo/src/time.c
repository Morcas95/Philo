/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalonso <maalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:15:38 by maalonso          #+#    #+#             */
/*   Updated: 2026/03/19 15:16:06 by maalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

void	ft_usleep(long time, t_data *data)
{
	long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
	{
		pthread_mutex_lock(&data->dead_lock);
		if (data->simulation_end == 1)
		{
			pthread_mutex_unlock(&data->dead_lock);
			break ;
		}
		pthread_mutex_unlock(&data->dead_lock);
		usleep(100);
	}
}

void	ms_sleep_check(t_data *data, long ms)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < ms)
	{
		if (data && data->simulation_end == 1)
			break ;
		usleep(200);
	}
}
