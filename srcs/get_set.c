/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:33:21 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/09 05:33:23 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	get_int(pthread_mutex_t *mutex, int *var)
{
	int	ret;

	pthread_mutex_lock(mutex);
	ret = *var;
	pthread_mutex_unlock(mutex);
	return (ret);
}

int	set_int(pthread_mutex_t *mutex, int *var, int to_put_in)
{
	pthread_mutex_lock(mutex);
	*var = to_put_in;
	pthread_mutex_unlock(mutex);
	return (0);
}

int	get_long(pthread_mutex_t *mutex, long int *var)
{
	int	ret;

	pthread_mutex_lock(mutex);
	ret = *var;
	pthread_mutex_unlock(mutex);
	return (ret);
}

int	set_long(pthread_mutex_t *mutex, long int *var, long int to_put_in)
{
	pthread_mutex_lock(mutex);
	*var = to_put_in;
	pthread_mutex_unlock(mutex);
	return (0);
}
