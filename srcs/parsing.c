/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 03:28:33 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/01 22:05:12 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//TODO: proteger les cas d'erreurs
int	get_params(char **argv, t_params *param)
{
	param->time_to_die = ft_atoi(argv[1]);
	param->time_to_eat = ft_atoi(argv[2]);
	param->time_to_sleep = ft_atoi(argv[3]);
	param->number_of_philo = ft_atoi(argv[4]);
	param->numbr_of_time_each_philo_must_eat = ft_atoi(argv[5]);
	return (0);
}
