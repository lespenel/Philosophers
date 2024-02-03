/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:04:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/03 05:23:55 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <sys/time.h>

typedef struct s_params
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_time_each_philo_must_eat;
}	t_params;

typedef struct s_philo
{
	int	*philo;
	int	*fork;
}	t_philo;

typedef struct s_time
{
	struct timeval	begin;
	struct timeval	actual;
} t_time;

int	print_error(char *str);
int	ft_atoi(char *nptr);
int	get_params(int argc, char **argv, t_params *param);
int	init_philo(t_params *params, t_philo table);

int	get_begin_time(t_time *time);
int	get_actual_time(t_time *time);
int	print_actual_time(t_time *time);
int	get_time(void);

int	eat_state(t_params *param);
int	sleep_state(t_params *param);

#endif
