#include "philo.h"

int	print_error(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (1);
}

void cleanup(t_data *data, int stage)
{
    int i;
    
    if (stage >= 1 && data->forks)
        free(data->forks);
    if (stage >= 2 && data->philos)
        free(data->philos);
    if (stage >= 3)
    {
        i = 0;
        while (i < data->number_philo)
        {
            pthread_mutex_destroy(&data->forks[i]);
            i++;
        }
        pthread_mutex_destroy(&data->write_lock);
        pthread_mutex_destroy(&data->dead_lock);
    }
}

char	**free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void destroy_forks(t_data *data, int i)
{
	while (i-- > 0)
        pthread_mutex_destroy(&data->forks[i]);
}