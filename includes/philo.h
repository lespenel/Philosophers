/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:04:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/04 07:10:24 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stddef.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_params
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_time_each_philo_must_eat;
}	t_params;

typedef struct s_time
{
	struct timeval	begin;
	struct timeval	actual;
} t_time;

typedef struct s_philo
{
	int				*id;
	int				*living;
	int				start_time;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t	*dead_mutex;
	t_time			*clock;
	t_params		*params;
}	t_philo;

typedef struct s_thread
{
	int					*philo_ids;
	pthread_mutex_t		*forks;
	pthread_t			*threads;
	t_philo				*philos;
	int					living;
	pthread_mutex_t		mutex;
	pthread_mutex_t		dead_mutex;
}	t_thread;

typedef struct s_master
{
	t_params	param;
	t_time		clock;
	t_thread	threads;
}	t_master;

int	print_error(char *str);
int	ft_atoi(char *nptr);
int	get_params(int argc, char **argv, t_params *param);
int	init_philo(t_params *params, t_philo *table);
int	init_threads(t_master *data, t_thread *threads);

int	taking_fork(t_philo *philo);
int	thinking_state(t_philo *philo);
int	eat_state(t_philo *philo);
int	sleep_state(t_philo *philo);
int	dead_state(t_philo *philo);
int	print_state(t_time *clock, int id, char *str);

int	get_begin_time(t_time *time);
int	get_actual_time(t_time *time);
int	ft_usleep(t_time *clock, int timer);
int	get_time(void);

#endif
