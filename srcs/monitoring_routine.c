/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:33:57 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/09 05:33:59 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static int	is_philo_dead(t_philo *philo);

int	monitoring_routine(t_master *datas)
{
	long int	i;

	while (get_int(&datas->mutex_master, &datas->syncro_threads) == 0)
		usleep(100);
	while (get_int(&datas->mutex_master, &datas->simulation_status))
	{
		i = 0;
		while (i < get_long(&datas->mutex_master,
				&datas->params.number_of_philo))
		{
			if (is_philo_dead(&datas->philos[i])
				&& get_int(&datas->mutex_master, &datas->simulation_status))
			{
				print_state(datas, DIED, datas->philos[i].id);
				set_int(&datas->mutex_master, &datas->simulation_status, 0);
			}
			i++;
		}
		usleep(500);
	}
	return (0);
}

static int	is_philo_dead(t_philo *philo)
{
	size_t	time_since_last_meal;

	pthread_mutex_lock(philo->mutex_philo);
	time_since_last_meal = get_actual_time(philo->master) - philo->last_meal;
	if (philo->is_philo_full == 1)
	{
		pthread_mutex_unlock(philo->mutex_philo);
		return (0);
	}
	if (time_since_last_meal > (size_t)philo->master->params.time_to_die)
	{
		pthread_mutex_unlock(philo->mutex_philo);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex_philo);
	return (0);
}
