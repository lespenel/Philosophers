/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 01:51:27 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/07 01:11:03 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

static int	init_threads_tab(t_thread *threads, t_params *params);
static int	init_forks_and_mutex(t_thread *threads, t_params *params);
static int	init_philo_ids(t_thread *threads, t_params *param);
static int	init_philos(t_thread *threads, t_master *data);

int	init_threads(t_master *data, t_thread *threads)
{
	if (init_forks_and_mutex(threads, &data->param) == -1)
		return (-1);
	if (init_philo_ids(threads, &data->param) == -1)
		return (-1);
	if (init_threads_tab(threads, &data->param) == -1)
		return (-1);
	if (pthread_mutex_init(&threads->mutex_print, NULL) == -1)
		return (print_error("Mutex init failure\n"));
	if (pthread_mutex_init(&threads->exec_mutex, NULL) == -1)
		return (print_error("Mutex init failure\n"));
	if (init_philos(threads, data) == -1)
		return (-1);
	threads->thread_ready = 0;
	threads->simulation_status = 1;
	return (0);
}

static int	init_philos(t_thread *threads, t_master *data)
{
	int	i;

	threads->philos = malloc(sizeof(t_philo) * data->param.number_of_philo);
	if (threads->philos == NULL)
		return (print_error("Memory allocation failure (philos)\n"));
	i = 0;
	while (i < data->param.number_of_philo)
	{
		threads->philos[i].simulation_status = &threads->simulation_status;
		threads->philos[i].id = threads->philo_ids + i;
		threads->philos[i].clock = &data->clock;
		threads->philos[i].mutex_print = &threads->mutex_print;
		threads->philos[i].exec_mutex = &threads->exec_mutex;
		threads->philos[i].philo_mutex = threads->philos_mutex + i;
		threads->philos[i].left_fork = threads->forks + i;
		threads->philos[i].right_fork = threads->forks + ((i + 1)
				% data->param.number_of_philo);
		threads->philos[i].params = &data->param;
		threads->philos[i].meal_number = 0;
		threads->philos[i].enaught_meal = 0;
		threads->philos[i].last_meal = 0;
		threads->philos[i].thread = &data->threads;
		i++;
	}
	return (0);
}

static int	init_philo_ids(t_thread *threads, t_params *param)
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

static int	init_forks_and_mutex(t_thread *threads, t_params *params)
{
	int	i;

	threads->forks = malloc(sizeof(pthread_mutex_t) * params->number_of_philo);
	if (threads->forks == NULL)
		return (print_error("Memory allocation failure (forks)\n"));
	threads->philos_mutex = malloc(sizeof(pthread_mutex_t)
			* params->number_of_philo);
	if (threads->forks == NULL)
	{
		free(threads->forks);
		return (print_error("Memory allocation failure (forks)\n"));
	}
	i = 0;
	while (i < params->number_of_philo)
	{
		pthread_mutex_init(&threads->forks[i], NULL);
		pthread_mutex_init(&threads->philos_mutex[i], NULL);
		i++;
	}
	return (0);
}

static int	init_threads_tab(t_thread *threads, t_params *params)
{
	threads->threads = malloc(sizeof(pthread_t) * params->number_of_philo);
	if (threads->threads == NULL)
		return (print_error("Memory allocation failure (threads)\n"));
	return (0);
}
