/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 03:28:33 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/06 04:14:42 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	print_error(char *str)
{
	int	len;

	len = 0;
	write(2, "Error: ", 7);
	if (str)
	{
		while (str[len])
			len++;
		write(2, str, len);
	}
	return (-1);
}

//TODO: proteger les cas d'erreurs
int	get_params(int argc, char **argv, t_params *param)
{
	if (argc != 5 && argc != 6)
		return (print_error("Invalid number of parameters\n"));
	param->number_of_philo = ft_atoi(argv[1]);
	if (param->number_of_philo <= 0)
		return (print_error("Invalid value: number_of_philo\n"));
	param->time_to_die = ft_atoi(argv[2]);
	if (param->time_to_die == -1)
		return (print_error("Invalid value: time_to_die\n"));
	param->time_to_eat = ft_atoi(argv[3]);
	if (param->time_to_eat == -1)
		return (print_error("Invalid value: time_to_eat\n"));
	param->time_to_sleep = ft_atoi(argv[4]);
	if (param->time_to_sleep == -1)
		return (print_error("Invalid value: time_to_sleep\n"));
	if (argc == 6)
	{
		param->number_of_time_each_philo_must_eat = ft_atoi(argv[5]);
		if (param->number_of_time_each_philo_must_eat == -1)
			return (print_error("Invalid value: time_of_each_philo_eat\n"));
	}
	else
		param->number_of_time_each_philo_must_eat = -1;
	return (0);
}
