/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:04:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/01 22:06:03 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_params
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	numbr_of_time_each_philo_must_eat;
}	t_params;

typedef struct s_philo
{
	int	*philo;
	int	*fork;
}	t_philo;

int	ft_atoi(char *nptr);
int	get_params(char **argv, t_params *param);
int	get_time(void);

#endif
