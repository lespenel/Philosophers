/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:34:31 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/09 05:34:32 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

static int	print_dead_state(void);
static int	print_sleeping_state(void);
static int	print_eating_state(void);
static int	print_thinking_state(void);

int	print_state_lock(t_master *datas, int param, int philo_id)
{
	long int	time;

	if (get_simulation_status(datas->philos) == 0)
		return (0);
	time = get_actual_time(datas);
	if (time == -1)
		return (-1);
	if (printf("%-6ld %-4d", time, philo_id) == -1)
		return (print_error("printf failure\n"));
	if (param == DIED)
		return (print_dead_state());
	if (param == EATING)
		return (print_eating_state());
	if (param == SLEEPING)
		return (print_sleeping_state());
	if (param == THINKING)
		return (print_thinking_state());
	if (param == FORK)
	{
		if (printf("has taken a fork\n") == -1)
			return (print_error("printf failure\n"));
	}
	return (0);
}

static int	print_dead_state(void)
{
	int	ret;

	ret = 0;
	ret = printf("\033[0;31m");
	if (ret == -1)
		return (print_error("printf failure\n"));
	ret = printf("died\n");
	if (ret == -1)
		return (print_error("printf failure\n"));
	ret = printf("\033[0m");
	if (ret == -1)
		return (print_error("printf failure\n"));
	return (ret);
}

static int	print_thinking_state(void)
{
	int	ret;

	ret = 0;
	ret = printf("\033[0;35m");
	if (ret == -1)
		return (print_error("printf failure\n"));
	ret = printf("is thinking\n");
	if (ret == -1)
		return (print_error("printf failure\n"));
	ret = printf("\033[0m");
	if (ret == -1)
		return (print_error("printf failure\n"));
	return (ret);
}

static int	print_eating_state(void)
{
	int	ret;

	ret = 0;
	ret = printf("\033[0;33m");
	if (ret == -1)
		return (print_error("printf failure\n"));
	ret = printf("is eating\n");
	if (ret == -1)
		return (print_error("printf failure\n"));
	ret = printf("\033[0m");
	if (ret == -1)
		return (print_error("printf failure\n"));
	return (ret);
}

static int	print_sleeping_state(void)
{
	int	ret;

	ret = 0;
	ret = printf("\033[0;36m");
	if (ret == -1)
		return (print_error("printf failure\n"));
	ret = printf("is sleeping\n");
	if (ret == -1)
		return (print_error("printf failure\n"));
	ret = printf("\033[0m");
	if (ret == -1)
		return (print_error("printf failure\n"));
	return (ret);
}
