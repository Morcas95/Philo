/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalonso <maalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:41:13 by morcas            #+#    #+#             */
/*   Updated: 2026/01/15 16:11:38 by maalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_value(char **value, t_data *data)
{
	int i;

	i = 0;
	while (value[i])
	{
		if (i == 0)
			data->number_philo = ft_atoi(value[i]);
		if (i == 1)
			data->time_to_die = ft_atoi_long(value[i]);
		if (i == 2)
			data->time_to_eat = ft_atoi_long(value[i]);
		if (i == 3)
			data->time_to_sleep = ft_atoi_long(value[i]);
		if (i == 4)
			data->number_eats = ft_atoi(value[i]);
		i++;
	}
	data->simulation_end = 0;
}

int	check_nbr(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_input(int argc, char **argv, t_data *data)
{
	int		i;
	long	tmp_argv;
	
	char	**tmp_array;
	i = 0;
	if (argc == 2)
		tmp_array = ft_split(argv[1], ' ');
	else
		tmp_array = argv + 1;
	while (tmp_array && tmp_array[i])
	{
		if (*tmp_array[i] == '\0')
			return (print_error("Error\nEmpty argument\n"));
		tmp_argv = ft_atoi_long(tmp_array[i]);
		if (tmp_argv < 1 || tmp_argv > INT_MAX)
			return (print_error("Error\nOnly positive numbers inside INT range\n"));
		if (!check_nbr(tmp_array[i]))
			return (print_error("Error\nOnly numbers to be introduced\n"));
		i++;
	}
	set_value(tmp_array, data);
	if (argc == 2)
		free_all(tmp_array);
	return (0);
}
