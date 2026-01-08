#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_data
{
	int				num_philo;
	long				time_to_die;
	long         	time_to_eat;
    long             time_to_sleep;
    int             must_eat_count;
}					t_data;

typedef struct s_philo
{
	int				id;
    int             meals_eaten;
    long last_meal_time;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_data *data;
}					t_philo;

int	print_error(const char *str);
int check_input(int argc, char **argv, t_data *data);
void set_value(char **value, t_data *data);
int	check_nbr(char *argv);

#endif