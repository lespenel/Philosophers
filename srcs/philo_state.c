/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 03:09:43 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/03 07:29:05 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

int	sleep_state(t_params *param)
{
	printf("%s %d is sleeping\n", )
	return (usleep(param->time_to_sleep * 1000));
}

int	eat_state(t_params *param)
{
	return(usleep(param->time_to_eat));
}

int	dead_state(t_params *param)
{
	return (0);
}

int	thinking_state(t_params *param)
{
	return (0);
}

int	taking_fork(t_params *param)
{
	return (0);
}
