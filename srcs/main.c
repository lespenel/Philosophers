/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:02:35 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/04 06:52:00 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "philo.h"

int	eating_routine(t_philo *philo)
{

	if (*philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		taking_fork(philo);
		pthread_mutex_lock(philo->right_fork);
		taking_fork(philo);
		eat_state(philo);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		taking_fork(philo);
		pthread_mutex_lock(philo->left_fork);
		taking_fork(philo);
		eat_state(philo);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	return (0);
}

int	life_check(t_philo *philo)
{
	if (get_actual_time(philo->clock) - philo->start_time < philo->params->time_to_die)
		return (0);
	pthread_mutex_lock(philo->dead_mutex);
	dead_state(philo);
	*philo->living = 0;
	pthread_mutex_unlock(philo->dead_mutex);
	return (0);
}

int	print_time_routine(t_philo *philo)
{
	philo->start_time = get_actual_time(philo->clock);
	while (*philo->living)
	{
		eating_routine(philo);
		life_check(philo);
	}
	return (0);
}

int	create_loop(t_master *data)
{
	int i;

	i = 0;
	while (i < data->param.number_of_philo)
	{
		if (pthread_create(&data->threads.threads[i], NULL, (void *)print_time_routine, &data->threads.philos[i]) == -1)
		{
			free(data->threads.forks);
			free(data->threads.philos);
			return (print_error("pthread_create failure\n"));
		}
		i++;
	}
	return (0);
}

int	join_loop(t_master *data)
{
	int i;

	i = 0;
	while (i < data->param.number_of_philo)
	{
		if (pthread_join(data->threads.threads[i], NULL) == -1)
		{
			free(data->threads.forks);
			free(data->threads.philos);
			return (print_error("pthread_join failure\n"));
		}
		if (printf("%d killed\n", i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	create_philo(t_master *data)
{
	if (create_loop(data) == -1)
		return (-1);
	if (join_loop(data) == -1)
		return (-1);
	free(data->threads.philos);
	free(data->threads.threads);
	free(data->threads.philo_ids);
	free(data->threads.forks);
	pthread_mutex_destroy(&data->threads.mutex);
	return (0);
}

int	main(int argc, char **argv)
{
	t_master	data;

	if (get_params(argc, argv, &data.param) == -1)
		return (-1);
	if (get_begin_time(&data.clock) == -1)
		return (-1);
	if (init_threads(&data, &data.threads) == -1)
		return (-1);
	create_philo(&data);
	return (0);
}
