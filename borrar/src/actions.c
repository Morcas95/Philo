#include "philo.h"

void pick_forks(t_philo *philo)
{
    if (philo->data->number_philo == 1)
    {
        pthread_mutex_lock(philo->left_fork);
        write_status(philo, "has taken a fork");
        ft_usleep(philo->data->time_to_die, philo->data);
        pthread_mutex_unlock(philo->left_fork);
        return ;
    }
    if (philo->id == philo->data->number_philo)
    {
        pthread_mutex_lock(philo->right_fork);
        write_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->left_fork);
        write_status(philo, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(philo->left_fork);
        write_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        write_status(philo, "has taken a fork");
    }
}

void is_eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->dead_lock);
    philo->last_meal_time = get_time();
    pthread_mutex_unlock(&philo->data->dead_lock);
    write_status(philo, "is eating");
    ft_usleep(philo->data->time_to_eat, philo->data);
    pthread_mutex_lock(&philo->data->dead_lock);
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->data->dead_lock);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    if (philo->data->time_to_die < philo->data->time_to_eat + philo->data->time_to_sleep)
    {
        ft_usleep((philo->data->time_to_die - philo->data->time_to_eat) / 2, philo->data);
    }
}

void is_sleeping(t_philo *philo)
{
    write_status(philo, "is sleeping");
    ft_usleep(philo->data->time_to_sleep, philo->data);
}