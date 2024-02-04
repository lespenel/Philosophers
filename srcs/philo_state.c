/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:09:43 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/04 07:13:55 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

int	sleep_state(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_print);
	print_state(philo->clock, *philo->id , "is sleeping");
	pthread_mutex_unlock(philo->mutex_print);
	return (ft_usleep(philo->clock, philo->params->time_to_sleep));
}

int	eat_state(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_print);
	print_state(philo->clock, *philo->id , "is eating");
	pthread_mutex_unlock(philo->mutex_print);
	return(ft_usleep(philo->clock, philo->params->time_to_eat));
}

int	dead_state(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_print);
	print_state(philo->clock, *philo->id, "is dead");
	pthread_mutex_unlock(philo->mutex_print);
	return (0);
}

int	thinking_state(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_print);
	print_state(philo->clock, *philo->id , "is thinking");
	pthread_mutex_unlock(philo->mutex_print);
	return (0);
}

int	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_print);
	print_state(philo->clock, *philo->id, "taking a fork");
	pthread_mutex_unlock(philo->mutex_print);
	return (0);
}
