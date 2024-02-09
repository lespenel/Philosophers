/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:32:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/09 05:32:43 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "unistd.h"
#include <stdio.h>

static int	sleeping_routine(t_philo *philo);

int	get_simulation_status(t_philo *philos)
{
	int	ret;

	pthread_mutex_lock(&philos->master->mutex_master);
	ret = philos->master->simulation_status;
	pthread_mutex_unlock(&philos->master->mutex_master);
	return (ret);
}

int	philo_routine(t_philo *philo)
{
	while (get_int(&philo->master->mutex_master,
			&philo->master->syncro_threads) == 0)
		usleep(100);
	if (philo->id % 2)
		usleep(500);
	while (get_simulation_status(philo))
	{
		if (get_int(philo->mutex_philo, &philo->is_philo_full))
			break ;
		if (eating_routine(philo) == -1)
			return (-1);
		if (sleeping_routine(philo) == -1)
			return (-1);
		if (print_state(philo->master, THINKING, philo->id) == -1)
			return (-1);
	}
	return (0);
}

static int	sleeping_routine(t_philo *philo)
{
	print_state(philo->master, SLEEPING, philo->id);
	ft_usleep(philo->master, philo->master->params.time_to_sleep);
	if (philo->master->params.number_of_philo % 2)
		usleep(500);
	return (0);
}

int	single_philo_routine(t_philo *philo)
{
	while (get_int(&philo->master->mutex_master,
			&philo->master->syncro_threads) == 0)
		usleep(100);
	if (print_state(philo->master, FORK, 1) == -1)
		return (-1);
	ft_usleep(philo->master, philo->master->params.time_to_die + 10);
	return (0);
}
