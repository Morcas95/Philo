#include "philo.h"

int main(int argc, char **argv)
{
    t_data data;

    if (argc < 5 || argc > 6)
        return (printf("Error: Wrong args\n"), 1);
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
    cleanup(&data, 3);
    return (0);
}