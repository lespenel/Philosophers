/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:02:35 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/05 05:39:26 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_master	data;

	if (get_params(argc, argv, &data.param) == -1)
		return (-1);
	if (init_threads(&data, &data.threads) == -1)
		return (-1);
	if (get_begin_time(&data.clock) == -1)
		return (-1);
	if (start_philos(&data) == -1)
		return (-1);
	return (0);
}
