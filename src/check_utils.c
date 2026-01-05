/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morcas <morcas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:41:13 by morcas            #+#    #+#             */
/*   Updated: 2026/01/05 22:00:50 by morcas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	check_input(int argc, char **argv)
{
	int		i;
	long	tmp_argv;
	char	**tmp_array;

	i = 0;
	if (argc == 2)
		tmp_array = ft_split(argv[1], ' ');
	else
		tmp_array = argv + 1;
	while (i < argc)
	{
		if (!tmp_array[i])
			return (print_error("Error\nEmpty argument\n"));
		tmp_argv = ft_atoi_long(tmp_array[i]);
		if (tmp_argv < INT_MIN || tmp_argv > INT_MAX)
			return (print_error("Error\nOnly numbers inside INT range\n"));
		if (!check_nbr(tmp_array[i]))
			return (print_error("Error\nOnly numbers to be introduced\n"));
		i++;
	}
	if (argc == 2)
		free_all(tmp_array);
	return (0);
}