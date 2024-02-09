/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_datas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:33:10 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/09 05:33:11 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

static int	destroy_mutexes_tab(t_master *datas, pthread_mutex_t *mutex);

int	free_datas(t_master *datas)
{
	if (datas->mutex_philos)
		destroy_mutexes_tab(datas, datas->mutex_philos);
	if (datas->forks)
		destroy_mutexes_tab(datas, datas->forks);
	pthread_mutex_destroy(&datas->mutex_print);
	pthread_mutex_destroy(&datas->mutex_master);
	if (datas->philos_ids)
		free(datas->philos_ids);
	if (datas->philo_tids)
		free(datas->philo_tids);
	if (datas->philos)
		free(datas->philos);
	return (0);
}

static int	destroy_mutexes_tab(t_master *datas, pthread_mutex_t *mutex)
{
	int	i;

	i = 0;
	while (i < datas->params.number_of_philo)
	{
		pthread_mutex_destroy(mutex + i);
		i++;
	}
	free(mutex);
	return (0);
}

int	error_join_loop(int nb, t_master *datas)
{
	int	i;

	i = 0;
	set_int(&datas->mutex_master, &datas->syncro_threads, 1);
	set_int(&datas->mutex_master, &datas->simulation_status, 0);
	while (i < nb)
	{
		pthread_join(datas->philo_tids[i], NULL);
		i++;
	}
	return (0);
}
