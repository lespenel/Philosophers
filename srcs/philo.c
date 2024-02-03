/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 01:51:27 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/03 01:54:51 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <inttypes.h>
#include <stdlib.h>

int	init_philo(t_params *params, t_philo table)
{
	table.philo = malloc(sizeof(int) * params->number_of_philo);
	if (table.philo == NULL)
	{
		return (-1);
	}
	table.fork = malloc(sizeof(int) * params->number_of_philo);
	if (table.fork == NULL)
	{
		free(table.philo);
		return (-1);
	}
	return (0);
}
