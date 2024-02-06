/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:12:17 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/06 02:16:18 by lespenel         ###   ########.fr       */
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
