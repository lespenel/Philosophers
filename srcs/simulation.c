/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:34:55 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/09 05:34:56 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static int	start_single_philo(t_master *datas);
static int	start_philos(t_master *datas);
static int	start_monitoring(t_master *datas);
static int	join_threads(t_master *datas);

int	start_simulation(t_master *datas)
{
	if (datas->params.number_of_time_each_philo_must_eat == 0)
		return (0);
	if (datas->params.number_of_philo == 1)
	{
		if (start_single_philo(datas) == -1)
			return (-1);
	}
	else if (start_philos(datas) == -1)
		return (-1);
	if (start_monitoring(datas) == -1)
		return (-1);
	if (set_begin_time(datas) == -1)
		return (-1);
	set_int(&datas->mutex_master, &datas->syncro_threads, 1);
	if (join_threads(datas) == -1)
		return (-1);
	return (0);
}

static int	start_philos(t_master *datas)
{
	long int	i;

	i = 0;
	while (i < datas->params.number_of_philo)
	{
		if (pthread_create(&datas->philo_tids[i], NULL,
				(void *)philo_routine, &datas->philos[i]) == -1)
		{
			error_join_loop(i + 1, datas);
			free_datas(datas);
			return (print_error("pthread_create failure\n"));
		}
		i++;
	}
	return (0);
}

static int	join_threads(t_master *datas)
{
	long int	i;

	i = 0;
	while (i < get_long(&datas->mutex_master,
			&datas->params.number_of_philo))
	{
		if (pthread_join(datas->philo_tids[i], NULL) == -1)
			return (print_error("pthread_join failure\n"));
		i++;
	}
	set_int(&datas->mutex_master, &datas->simulation_status, 0);
	if (pthread_join(datas->monitoring_tid, NULL) == -1)
		return (print_error("pthread_join failure\n"));
	return (0);
}

static int	start_monitoring(t_master *datas)
{
	if (pthread_create(&datas->monitoring_tid, NULL,
			(void *)monitoring_routine, datas) == -1)
		return (print_error("pthread_create failure\n"));
	return (0);
}

static int	start_single_philo(t_master *datas)
{
	if (pthread_create(&datas->philo_tids[0], NULL,
			(void *)single_philo_routine, &datas->philos[0]) == -1)
		return (print_error("pthreade_create failure\n"));
	return (0);
}
