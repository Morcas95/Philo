#include "philo.h"

int main(int argc, char **argv)
{
    t_data data;
    int i;

    if (argc < 5 || argc > 6)
        return (printf("Error\nWrong args\n"), 1);
    if (check_input(argc, argv, &data) == 1)
        return (1);
    data.forks = malloc(sizeof(pthread_mutex_t) * data.number_philo);
    if (!data.forks)
        return (1);
    data.philos = malloc(sizeof(t_philo) * data.number_philo);
    if (!data.philos)
        return (free(data.forks), 1);
    if (init_mutexes(&data) != 0)
        return (cleanup(&data, 2), 1);
    init_philos(&data);
    data.start_time = get_time();
    if (create_threads(&data) == 1)
        return (cleanup(&data, 3), 1);
    while (1)
    {
        if (check_death(&data) == 1 || check_victory(&data))
            break ;
        usleep(100);
    }
    i = 0;
    while (i < data.number_philo)
    {
        pthread_join(data.philos[i].thread, NULL);
        i++;
    }
    cleanup(&data, 3);
    return (0);
}
