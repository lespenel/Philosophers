/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:16:05 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/03 05:04:32 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include "philo.h"

int	get_begin_time(t_time *time)
{
	if (gettimeofday(&time->begin, NULL) == -1)
		return (print_error("gettimeofday failed\n"));
	return (0);
}

int	get_actual_time(t_time *time)
{
	if (gettimeofday(&time->actual, NULL) == -1)
		return (print_error("gettimeofday failed\n"));
	return (0);
}

int	print_actual_time(t_time *time)
{
	int	current_time;

	if (get_actual_time(time) == -1)
		return (-1);
	current_time = (time->actual.tv_sec - time->begin.tv_sec) * 1000;
	current_time += (time->actual.tv_usec - time->begin.tv_usec) / 1000;
	if (printf("%d\n", current_time) == -1)
		return (print_error("print error\n"));
	return (0);
}

int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (print_error("gettimeofday failed\n"));
	printf("tv_sec = %ld, tv_usec = %ld\n", time.tv_sec, time.tv_usec);
	return (0);
}
