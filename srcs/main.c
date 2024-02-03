/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:02:35 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/03 05:56:03 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "philo.h"

int	creat_philo(t_params *param, t_time *clock)
{
	int	i;
	pthread_t *threads;

	threads = malloc(sizeof(pthread_t) * param->number_of_philo);
	if (threads == NULL)
	{
		return (-1);
	}
	i = 0;
	while (i < param->number_of_philo)
	{
		if (pthread_create(&threads[i], NULL, (void *)print_actual_time, clock) == -1)
		{
			free(threads);
			return (-1);
		}
		i++;
	}
	i = 0;
	while (i < param->number_of_philo)
	{
		if (pthread_join(threads[i], NULL) == -1)
		{
			free(threads);
			return (-1);
		}
		i++;
	}
	free(threads);
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	param;
	t_time		clock;

	if (get_params(argc, argv, &param) == -1)
		return (-1);
	if (get_begin_time(&clock) == -1)
		return (-1);
	creat_philo(&param, &clock);
	get_time();
	usleep(68000);
	print_actual_time(&clock);
	usleep(2000000);
	get_time();
	print_actual_time(&clock);
	//printf("atoi = %d, ft_atoi = %d", atoi(argv[1]), ft_atoi(argv[1]));
	return (0);
}
