/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:04:37 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/05 05:37:59 by lespenel         ###   ########.fr       */
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
	int				last_meal;
	int				meal_number;
	int				enaught_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*exec_mutex;
	t_time			*clock;
	t_params		*params;
}	t_philo;

typedef struct s_thread
{
	int					*philo_ids;
	pthread_mutex_t		*forks;
	pthread_t			*threads;
	pthread_t			monitoring;
	t_philo				*philos;
	int					living;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		exec_mutex;
}	t_thread;

typedef struct s_master
{
	t_params	param;
	t_time		clock;
	t_thread	threads;
}	t_master;

int	eating_routine(t_philo *philo);
int	sleeping_routine(t_philo *philo);
int	thinking_routine(t_philo *philo);

int	get_living_status(t_philo *philo);

int	start_philos(t_master *data);
int	start_monitoring(t_master *data);

int	print_error(char *str);
int	ft_atoi(char *nptr);
int	get_params(int argc, char **argv, t_params *param);
int	init_philo(t_params *params, t_philo *table);
int	init_threads(t_master *data, t_thread *threads);

int	print_state(t_philo *philo, int id, char *str);
int	get_begin_time(t_time *time);
int	get_actual_time(t_time *time);
int	ft_usleep(t_time *clock, int timer);

#endif
