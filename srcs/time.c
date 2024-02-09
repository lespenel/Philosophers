/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 04:08:30 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/09 04:23:17 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>

int	print_state(t_master *datas, int param, int philo_id)
{
	pthread_mutex_lock(&datas->mutex_print);
	print_state_lock(datas, param, philo_id);
	pthread_mutex_unlock(&datas->mutex_print);
	return (0);
}

int	set_begin_time(t_master *datas)
{
	if (gettimeofday(&datas->begin_clock, NULL) == -1)
		return (print_error("gettimeofday failure\n"));
	return (0);
}

long int	get_actual_time(t_master *datas)
{
	struct timeval	time;
	long int		current_time;

	if (gettimeofday(&time, NULL) == -1)
		return (print_error("gettimeofday failure\n"));
	current_time = ((time.tv_sec - datas->begin_clock.tv_sec) * 1000)
		+ (time.tv_usec - datas->begin_clock.tv_usec) / 1000;
	return (current_time);
}

int	ft_usleep(t_master *datas, long int timer)
{
	long int	start;

	start = get_actual_time(datas);
	while (get_actual_time(datas) - start < timer)
		usleep(500);
	return (0);
}
