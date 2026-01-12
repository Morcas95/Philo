#include "philo.h"

void init_forks(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_philo)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->write_lock, NULL);
    pthread_mutex_init(&data->dead_lock, NULL);
    i = 0;
    while (i < data->number_philo - 1)
    {
        data->philos[i].id = i + 1;
        data->philos[i].last_meal_time = 0;
        data->philos[i].meals_eaten = 0;
        data->philos[i].data = data;
        data->philos[i].left_fork = &data->forks[i];
        data->philos[i].right_fork = &data->forks[(i + 1) % data->number_philo];
    }
}
