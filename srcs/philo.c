/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 07:42:33 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/05 06:35:04 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static int	philo_routine(t_philo *philo);
static int	create_threads_loop(t_master *data);
static int	join_threads_loop(t_master *data);

//TODO: single philo;
int	start_philos(t_master *data)
{
	if (data->param.number_of_time_each_philo_must_eat == 0)
		return (0);
	if (data->param.number_of_philo == 1)
		return (-5000);
	if (create_threads_loop(data) == -1)
		return (-1);
	if (start_monitoring(data) == -1)
		return (-1);
	if (join_threads_loop(data) == -1)
		return (-1);

	free(data->threads.philos);
	free(data->threads.threads);
	free(data->threads.philo_ids);
	free(data->threads.forks);
	pthread_mutex_destroy(&data->threads.mutex_print);
	pthread_mutex_destroy(&data->threads.exec_mutex);
	pthread_mutex_destroy(&data->threads.dead_mutex);
	return (0);
}

static int	philo_routine(t_philo *philo)
{
	//philo->start_time = get_actual_time(philo->clock);
	//philo->last_meal = philo->start_time;
	while (get_living_status(philo) == 1)
	{
		if (philo->enaught_meal == 1)
			break ;
		if (get_living_status(philo) == 1)
			eating_routine(philo);
		if (get_living_status(philo) == 1)
			sleeping_routine(philo);
		if (get_living_status(philo) == 1)
			thinking_routine(philo);
	}
	return (0);
}

static int	create_threads_loop(t_master *data)
{
	int i;

	i = 0;
	while (i < data->param.number_of_philo)
	{
		if (pthread_create(&data->threads.threads[i], NULL, (void *)philo_routine, &data->threads.philos[i]) == -1)
		{
			free(data->threads.forks);
			free(data->threads.philos);
			return (print_error("pthread_create failure\n"));
		}
		i++;
	}
	return (0);
}

static int	join_threads_loop(t_master *data)
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
		i++;
	}
	if (pthread_join(data->threads.monitoring, NULL) == -1)
		return (print_error("pthread_join failure\n"));
	return (0);
}
