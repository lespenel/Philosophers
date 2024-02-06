/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 04:01:45 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/06 04:10:23 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	free_data(t_thread *threads)
{
	if (threads->philos)
		free(threads->philos);
	if (threads->threads)
		free(threads->threads);
	if (threads->philo_ids)
		free(threads->philo_ids);
	if (threads->forks)
		free(threads->forks);
	if (threads->philos_mutex)
		free(threads->philos_mutex);
	pthread_mutex_destroy(&threads->mutex_print);
	pthread_mutex_destroy(&threads->exec_mutex);
	return (0);
}
