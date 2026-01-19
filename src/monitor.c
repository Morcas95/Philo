#include "philo.h"

int check_death(t_data *data)
{
    int i;

    i = 0;
    while (i < data->number_philo)
    {
        pthread_mutex_lock(&data->dead_lock);
        if ((get_time() - data->philos[i].last_meal_time) >= data->time_to_die)
        {
            data->simulation_end = 1;
            pthread_mutex_unlock(&data->dead_lock);
            write_status(&data->philos[i], "died");
            return (1);
        }
        pthread_mutex_unlock(&data->dead_lock);
        i++;
    }
    return (0);
}

int check_victory(t_data *data)
{
    int finished_eating;
    int i;

    if (data->number_of_meals == -1)
        return (0);
    i = 0;
    finished_eating = 0;
    while (i < data->number_philo)
    {
        pthread_mutex_lock(&data->dead_lock);
        if (data->philos[i].meals_eaten >= data->number_of_meals)
            finished_eating++;
        pthread_mutex_unlock(&data->dead_lock);
        i++;
    }
    if (finished_eating == data->number_philo)
    {
        pthread_mutex_lock(&data->dead_lock);
        data->simulation_end = 1;
        pthread_mutex_unlock(&data->dead_lock);
        return (1);
    }
    return (0);
}
