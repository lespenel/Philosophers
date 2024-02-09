/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:34:07 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/09 05:34:08 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>
#include <unistd.h>

static long int	ft_atol(char *nptr);

int	print_error(char *str)
{
	int	len;
	int	ret;

	len = 0;
	ret = write(2, "Error: ", 7);
	if (str)
	{
		while (str[len])
			len++;
		ret = write(2, str, len);
	}
	(void)ret;
	return (-1);
}

int	get_params(int argc, char **argv, t_params *param)
{
	if (argc != 5 && argc != 6)
		return (print_error("Invalid number of parameters\n"));
	param->number_of_philo = ft_atol(argv[1]);
	if (param->number_of_philo <= 0)
		return (print_error("Invalid value: number_of_philo\n"));
	param->time_to_die = ft_atol(argv[2]);
	if (param->time_to_die == -1)
		return (print_error("Invalid value: time_to_die\n"));
	param->time_to_eat = ft_atol(argv[3]);
	if (param->time_to_eat == -1)
		return (print_error("Invalid value: time_to_eat\n"));
	param->time_to_sleep = ft_atol(argv[4]);
	if (param->time_to_sleep == -1)
		return (print_error("Invalid value: time_to_sleep\n"));
	if (argc == 6)
	{
		param->number_of_time_each_philo_must_eat = ft_atol(argv[5]);
		if (param->number_of_time_each_philo_must_eat == -1)
			return (print_error("Invalid value: time_of_each_philo_eat\n"));
	}
	else
		param->number_of_time_each_philo_must_eat = -1;
	return (0);
}

static long int	ft_atol(char *nptr)
{
	long int	nb;
	size_t		len;
	size_t		index;

	len = 0;
	index = 0;
	nb = 0;
	while (nptr[len])
		len++;
	if (nptr[index] < '0' || nptr[index] > '9')
		return (-1);
	while (nptr[index] <= '9' && nptr[index] >= '0')
	{
		if (LONG_MAX / 10 < nb || LONG_MAX - (nptr[index] - '0') < nb * 10)
			return (-1);
		nb = nb * 10 + (nptr[index] - '0');
		index += 1;
	}
	if (len != index)
		return (-1);
	return (nb);
}
