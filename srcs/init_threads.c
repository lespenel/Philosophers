/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 01:51:27 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/04 06:46:29 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <inttypes.h>
#include <pthread.h>
#include <stdlib.h>


int	init_philo_ids(t_thread *threads, t_params *param)
{
	int	i;

	threads->philo_ids = malloc(sizeof(int) * param->number_of_philo);
	if (threads->philo_ids == NULL)
		return (print_error("Memory allocation failure (philo_ids)\n"));
	i = 0;
	while (i < param->number_of_philo)
	{
		threads->philo_ids[i] = i + 1;
		i++;
	}
	return (0);
}

int	init_forks(t_thread *threads, t_params *params)
{
	int	i;

	threads->forks = malloc(sizeof(pthread_mutex_t) * params->number_of_philo);
	if (threads->forks == NULL)
		return (print_error("Memory allocation failure (forks)\n"));
	i = 0;
	while (i < params->number_of_philo)
	{
		pthread_mutex_init(&threads->forks[i], NULL);
		i++;
	}
	return (0);
}

int	init_threads_tab(t_thread *threads, t_params *params)
{
	threads->threads = malloc(sizeof(pthread_t) * params->number_of_philo);
	if (threads->threads == NULL)
		return (print_error("Memory allocation failure (threads)\n"));
	return (0);
}

int	init_philos(t_thread *threads, t_master *data)
{
	int	i;

	threads->philos = malloc(sizeof(t_philo) * data->param.number_of_philo);
	if (threads->philos == NULL)
		return (print_error("Memory allocation failure (philos)\n"));
	i = 0;
	while (i < data->param.number_of_philo)
	{
		threads->philos[i].living = &threads->living;
		threads->philos[i].id = threads->philo_ids + i;
		threads->philos[i].clock = &data->clock;
		threads->philos[i].dead_mutex = &threads->dead_mutex;
		threads->philos[i].mutex_print = &threads->mutex;
		threads->philos[i].left_fork = threads->forks + i;
		threads->philos[i].right_fork = threads->forks + ((i + 1) % data->param.number_of_philo);
		threads->philos[i].params = &data->param;
		i++;
	}
	return (0);
}

int	init_threads(t_master *data, t_thread *threads)
{
	if (init_forks(threads, &data->param) == -1)
		return (-1);
	if (init_philo_ids(threads, &data->param) == -1)
		return (-1);
	if (init_threads_tab(threads, &data->param) == -1)
		return (-1);
	if (pthread_mutex_init(&threads->mutex, NULL) == -1)
		return (print_error("Mutex init failure\n"));
	if (pthread_mutex_init(&threads->dead_mutex, NULL) == -1)
		return (print_error("Mutex init failure\n"));
	if (init_philos(threads, data) == -1)
		return (-1);
	threads->living = 1;
	return (0);
}
