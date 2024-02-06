/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:24:06 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/06 07:05:25 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static int	odd_eating(t_philo *philo);
static int	even_eating(t_philo *philo);
static int	eating_state(t_philo *philo);

int	eating_routine(t_philo *philo)
{
	if (odd_eating(philo) == -1)
		return (-1);
	if (even_eating(philo) == -1)
		return (-1);
	if (pthread_mutex_lock(philo->philo_mutex) == -1)
		return (-1);
	philo->last_meal = get_actual_time(philo->clock);
	if (pthread_mutex_unlock(philo->philo_mutex) == -1)
		return (-1);
	philo->meal_number += 1;
	if (philo->params->number_of_time_each_philo_must_eat > 0 && 
			philo->meal_number == philo->params->number_of_time_each_philo_must_eat)
	{
		if (pthread_mutex_lock(philo->philo_mutex) == -1)
			return (-1);
		philo->enaught_meal = 1;
		if (pthread_mutex_unlock(philo->philo_mutex) == -1)
			return (-1);
	}
	return (0);
}

static int	odd_eating(t_philo *philo)
{
	if (get_int(philo->philo_mutex, philo->id) % 2 == 1)
	{
		if (print_state(philo, *philo->id, "has taken a fork") == -1)
			return (-1);
		if (pthread_mutex_lock(philo->left_fork) == -1)
			return (-1);
		if (pthread_mutex_lock(philo->right_fork) == -1)
			return (-1);
		if (print_state(philo, *philo->id, "has taken a fork") == -1)
			return (-1);
		if (eating_state(philo) == -1)
			return (-1);
		if (pthread_mutex_unlock(philo->left_fork) == -1)
			return (-1);
		if (pthread_mutex_unlock(philo->right_fork) == -1)
			return (-1);
	}
	return (0);
}

static int	even_eating(t_philo *philo)
{
	if (get_int(philo->philo_mutex, philo->id) % 2 == 0)
	{
		if (pthread_mutex_lock(philo->right_fork) == -1)
			return (-1);
		if (print_state(philo, *philo->id, "has taken a fork") == -1)
			return (-1);
		if (pthread_mutex_lock(philo->left_fork) == -1)
			return (-1);
		if (print_state(philo, *philo->id, "has taken a fork") == -1)
			return (-1);
		if (eating_state(philo) == -1)
			return (-1);
		if (pthread_mutex_unlock(philo->right_fork) == -1)
			return (-1);
		if (pthread_mutex_unlock(philo->left_fork) == -1)
			return (-1);
	}
	return (0);
}

static int	eating_state(t_philo *philo)
{
	if (print_state(philo, *philo->id, "is eating") == -1)
		return (-1);
	if (ft_usleep(philo->clock, philo->params->time_to_eat) == -1)
		return (-1);
	return (0);
}

