/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 05:33:44 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/09 05:33:46 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	t_master	datas;

	memset(&datas, 0, sizeof(t_master));
	if (get_params(argc, argv, &datas.params) == -1)
		return (-1);
	if (init_datas(&datas) == -1)
	{
		free_datas(&datas);
		return (-1);
	}
	if (start_simulation(&datas) == -1)
	{
		free_datas(&datas);
		return (-1);
	}
	free_datas(&datas);
	return (0);
}
