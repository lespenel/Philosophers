/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:32:52 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/09 05:32:54 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	odd_eating(t_philo *philo);
static int	even_eating(t_philo *philo);
static int	eating_state(t_philo *philo);

int	eating_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (odd_eating(philo) == -1)
			return (-1);
	}
	else if (even_eating(philo) == -1)
		return (-1);
	philo->meal_number += 1;
	if (philo->meal_number
		== philo->master->params.number_of_time_each_philo_must_eat)
	{
		set_int(philo->mutex_philo, &philo->is_philo_full, 1);
	}
	return (0);
}

static int	odd_eating(t_philo *philo)
{
	if (pthread_mutex_lock(philo->left_fork) == -1)
		return (-1);
	if (print_state(philo->master, FORK, philo->id) == -1)
		return (-1);
	if (pthread_mutex_lock(philo->right_fork) == -1)
		return (-1);
	if (print_state(philo->master, FORK, philo->id) == -1)
		return (-1);
	if (eating_state(philo) == -1)
		return (-1);
	if (pthread_mutex_unlock(philo->left_fork) == -1)
		return (-1);
	if (pthread_mutex_unlock(philo->right_fork) == -1)
		return (-1);
	return (0);
}

static int	even_eating(t_philo *philo)
{
	if (pthread_mutex_lock(philo->right_fork) == -1)
		return (-1);
	if (print_state(philo->master, FORK, philo->id) == -1)
		return (-1);
	if (pthread_mutex_lock(philo->left_fork) == -1)
		return (-1);
	if (print_state(philo->master, FORK, philo->id) == -1)
		return (-1);
	if (eating_state(philo) == -1)
		return (-1);
	if (pthread_mutex_unlock(philo->right_fork) == -1)
		return (-1);
	if (pthread_mutex_unlock(philo->left_fork) == -1)
		return (-1);
	return (0);
}

static int	eating_state(t_philo *philo)
{
	if (print_state(philo->master, EATING, philo->id) == -1)
		return (-1);
	set_long(philo->mutex_philo,
		&philo->last_meal, get_actual_time(philo->master));
	if (ft_usleep(philo->master, philo->master->params.time_to_eat) == -1)
		return (-1);
	return (0);
}
