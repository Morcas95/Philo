#include "philo.h"

int main(int argc, char **argv)
{
    t_data data;
    if (argc < 5 || argc > 6)
    {
		print_error("Only 5 or 6 arguments to be entered.\n");
        return (1);
    }
    if (check_input(argc, argv, &data) == 1)
		return (1);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.number_philo);
	data.philos = malloc(sizeof(t_philo) * data.number_philo);
	if(!data.forks || !data.philos)
	{
		free(data.forks);
		free(data.philos);
		return (1);
	}
    return (0);
}