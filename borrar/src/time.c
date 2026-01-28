#include "philo.h"

long get_time(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL))
        return (0);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void ft_usleep(long time, t_data *data)
{
    long start_time;

    start_time = get_time();
    while ((get_time() - start_time) < time)
    {
        pthread_mutex_lock(&data->dead_lock);
        if (data->simulation_end == 1)
        {
            pthread_mutex_unlock(&data->dead_lock);
            break;
        }
        pthread_mutex_unlock(&data->dead_lock);
        usleep(500);
    }
}