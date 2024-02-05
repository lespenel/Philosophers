/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:43:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/04 19:45:30 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	sleeping_routine(t_philo *philo)
{
	if (print_state(philo, *philo->id, "is sleeping") == -1)
		return (-1);
	if (ft_usleep(philo->clock, philo->params->time_to_sleep) == -1)
		return (-1);
	return (0);
}
