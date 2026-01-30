#ifndef PHILO_H
# define PHILO_H

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
    int             number_of_meals;
    int simulation_end;
    pthread_mutex_t *forks;
    t_philo *philos;
    pthread_mutex_t write_lock;
    pthread_mutex_t dead_lock;
    long start_time;
}					t_data;

/* ERRORS */
int	print_error(const char *str);
void cleanup(t_data *data, int stage);
void destroy_forks(t_data *data, int i);

/* ARGUMENTS CHECKS */
int check_input(int argc, char **argv, t_data *data);
void set_value(char **value, t_data *data, int argc);
int	check_nbr(char *argv);

/* TRHEADS CREATION */
int init_mutexes(t_data *data);
void init_philos(t_data *data);
int create_threads(t_data *data);

/* UTILS */
long get_time(void);
void ft_usleep(long time, t_data *data);
int	ft_atoi(const char *nptr);
long	ft_atoi_long(const char *str);
char	**ft_split(char const *s, char c);
char	**free_all(char **str);
char	*const_ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

/* LOGS */
void write_status(t_philo *philo, char *status);

/* ACTIONS */
void pick_forks(t_philo *philo);
void is_eating(t_philo *philo);
void is_sleeping(t_philo *philo);

/* ENDING CHECKS */
int check_death(t_data *data);
int check_victory(t_data *data);

#endif