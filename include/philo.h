#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data  t_data;
typedef struct s_philo t_philo;

typedef struct s_philo
{
    int				id;
    int             meals_eaten;
    long last_meal_time;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_data *data;
    pthread_t thread;
}					t_philo;

typedef struct s_data
{
	int				number_philo;
	long				time_to_die;
	long         	time_to_eat;
    long             time_to_sleep;
    int             number_eats;
    int simulation_end;
    pthread_mutex_t *forks;
    t_philo *philos;
    pthread_mutex_t write_lock;
    pthread_mutex_t dead_lock;
    long start_time;
}					t_data;


int	print_error(const char *str);
void cleanup(t_data *data, int stage);
int check_input(int argc, char **argv, t_data *data);
void set_value(char **value, t_data *data);
int	check_nbr(char *argv);
int init_mutexes(t_data *data);
void init_philos(t_data *data);
int create_threads(t_data *data);
long get_time(void);
void ft_usleep(long time, t_data *data);

#endif