/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_datas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:33:33 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/09 05:33:34 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

static int	init_mutex_tabs(t_master *datas);
static int	init_philos(t_master *datas);

int	init_datas(t_master *datas)
{
	datas->simulation_status = 1;
	datas->philo_tids = malloc(sizeof(pthread_t)
			* datas->params.number_of_philo);
	if (datas->philo_tids == NULL)
		return (print_error("Memory alocation failure (philo_tids)\n"));
	datas->philos_ids = malloc(sizeof(int) * datas->params.number_of_philo);
	if (datas->philos_ids == NULL)
		return (print_error("Memory alocation failure (philo_ids)\n"));
	if (init_mutex_tabs(datas) == -1)
		return (-1);
	if (init_philos(datas) == -1)
		return (-1);
	if (pthread_mutex_init(&datas->mutex_print, NULL) == -1)
		return (print_error("Mutex_init failure (m_print)\n"));
	if (pthread_mutex_init(&datas->mutex_master, NULL) == -1)
		return (print_error("Mutex_init failure (m_master)\n"));
	return (0);
}

static int	init_philos(t_master *datas)
{
	int	i;

	datas->philos = malloc(sizeof(t_philo) * datas->params.number_of_philo);
	if (datas->philos == NULL)
		return (print_error("Memory alocation failure (philos)\n"));
	i = 0;
	while (i < datas->params.number_of_philo)
	{
		datas->philos[i].master = datas;
		datas->philos[i].id = i + 1;
		datas->philos[i].meal_number = 0;
		datas->philos[i].last_meal = 0;
		datas->philos[i].is_philo_full = 0;
		datas->philos[i].right_fork = datas->forks + i;
		datas->philos[i].left_fork = (datas->forks
				+ (i + 1) % datas->params.number_of_philo);
		datas->philos[i].mutex_philo = datas->mutex_philos + i;
		i++;
	}
	return (0);
}

static int	init_mutex_tabs(t_master *datas)
{
	int	i;

	datas->mutex_philos = malloc(sizeof(pthread_mutex_t)
			* datas->params.number_of_philo);
	if (datas->mutex_philos == NULL)
		return (print_error("Memory alocation failure (philo_ids)\n"));
	datas->forks = malloc(sizeof(pthread_mutex_t)
			* datas->params.number_of_philo);
	if (datas->forks == NULL)
		return (print_error("Memory alocation failure (forks)\n"));
	i = 0;
	while (i < datas->params.number_of_philo)
	{
		if (pthread_mutex_init(&datas->forks[i], NULL) == -1)
			return (print_error("Mutex_init failure (forks)\n"));
		if (pthread_mutex_init(&datas->mutex_philos[i], NULL) == -1)
			return (print_error("Mutex_init failure (philos)\n"));
		i++;
	}
	return (0);
}
