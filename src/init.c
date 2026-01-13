#include "philo.h"

int init_mutexes(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_philo)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
        {
            while (i-- > 0)
                pthread_mutex_destroy(&data->forks[i]);
            return (1); 
        }
        i++;
    }
    if (pthread_mutex_init(&data->write_lock, NULL) != 0)
        return (1);
    if (pthread_mutex_init(&data->dead_lock, NULL) != 0)
        return (pthread_mutex_destroy(&data->write_lock), 1);
    return (0);
}

void init_philos(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_philo)
    {
        data->philos[i].id = i + 1;
        data->philos[i].last_meal_time = 0;
        data->philos[i].meals_eaten = 0;
        data->philos[i].data = data;
        data->philos[i].left_fork = &data->forks[i];
        data->philos[i].right_fork = &data->forks[(i + 1) % data->number_philo];
        i++;
    }
}

void *philosopher_routine(void *arg)
{
    printf("La rutina funciona");
    return (NULL);
}

int create_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_philo)
    {
        if (pthread_create(&data->philos[i].thread, NULL, philosopher_routine, &data->philos[i]) != 0)
        {
            pthread_mutex_lock(&data->dead_lock);
            data->simulation_end = 1;
            pthread_mutex_unlock(&data->dead_lock);
            while (i-- > 0)
                pthread_join(data->philos[i].thread, NULL);
            cleanup(data, 3);
            return (1);
        }
        i++;
    }
    return (0);
}
