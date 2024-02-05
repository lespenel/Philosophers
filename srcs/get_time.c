/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:16:05 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/05 06:28:44 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

int	get_begin_time(t_time *time)
{
	if (gettimeofday(&time->begin, NULL) == -1)
		return (print_error("gettimeofday failed\n"));
	return (0);
}

int	print_state(t_philo *philo, int id, char *str)
{
	if (get_living_status(philo) == 0)
		return (0);
	if (pthread_mutex_lock(philo->mutex_print) == -1)
		return (-1);
	if (printf("%-6d %-3d %s\n", get_actual_time(philo->clock), id, str) == -1)
		return (print_error("printf error\n"));
	if (pthread_mutex_unlock(philo->mutex_print) == -1)
		return (-1);
	return (0);
}

int	get_actual_time(t_time *time)
{
	int	current_time;

	if (gettimeofday(&time->actual, NULL) == -1)
		return (print_error("gettimeofday failed\n"));
	current_time = (time->actual.tv_sec - time->begin.tv_sec) * 1000;
	current_time += (time->actual.tv_usec - time->begin.tv_usec) / 1000;
	return (current_time);
}

int	ft_usleep(t_time *clock, int timer)
{
	int	start;

	start = get_actual_time(clock);
	while ((get_actual_time(clock) - start) < timer)
		usleep(500);
	return (0);
}
