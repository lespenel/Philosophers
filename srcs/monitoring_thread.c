/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:40:59 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/07 00:36:32 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stddef.h>
#include <unistd.h>

int	get_simulation_status(t_philo *philos)
{
	int	ret;

	pthread_mutex_lock(philos->exec_mutex);
	ret = *philos->simulation_status;
	pthread_mutex_unlock(philos->exec_mutex);
	return (ret);
}

int	get_simulation_status2(t_philo *philos)
{
	int	ret;

	pthread_mutex_lock(philos->exec_mutex);
	ret = *philos->simulation_status;
	pthread_mutex_unlock(philos->exec_mutex);
	return (ret);
}

int	is_philo_dead(t_philo *philo)
{
	size_t	time_since_last_meal;

	pthread_mutex_lock(philo->philo_mutex);
	time_since_last_meal = get_actual_time(philo->clock) - philo->last_meal;
	if (philo->enaught_meal == 1)
	{
		pthread_mutex_unlock(philo->philo_mutex);
		return (0);
	}
	if (time_since_last_meal > (size_t)philo->params->time_to_die)
	{
		pthread_mutex_unlock(philo->philo_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->philo_mutex);
	return (0);
}

int	monitoring_thread(t_master *data)
{
	int i;

	while (get_int(&data->threads.exec_mutex, &data->threads.simulation_status) == 0)
		usleep(100);
	while(get_simulation_status(data->threads.philos) == 1)
	{
		i = 0;
		while (i < get_int(&data->threads.exec_mutex ,&data->param.number_of_philo))
		{
			if (is_philo_dead(&data->threads.philos[i]) && 
					get_simulation_status(data->threads.philos))
			{
				print_state(&data->threads.philos[i], 
						*data->threads.philos[i].id, "died");
				pthread_mutex_lock(&data->threads.exec_mutex);
				data->threads.simulation_status = 0;
				pthread_mutex_unlock(&data->threads.exec_mutex);
			}
			usleep(500);
			i++;
		}

	}
	return (0);
}

int	start_monitoring(t_master *data)
{			
	if (pthread_create(&data->threads.monitoring, NULL, 
				(void *)monitoring_thread, data) == -1)
		return (-1);
	return (0);
}
