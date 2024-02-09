/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel </var/spool/mail/lespenel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:27:09 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/09 05:26:03 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>

# define DIED 1
# define EATING 2
# define SLEEPING 3
# define FORK 4
# define THINKING 5

typedef struct s_philo	t_philo;

typedef struct s_params
{
	long int	number_of_philo;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	long int	number_of_time_each_philo_must_eat;
}	t_params;

typedef struct s_master
{
	t_params		params;
	struct timeval	begin_clock;
	pthread_t		*philo_tids;
	pthread_t		monitoring_tid;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_master;
	pthread_mutex_t	*mutex_philos;
	pthread_mutex_t	*forks;
	int				*philos_ids;
	t_philo			*philos;
	int				simulation_status;
	int				syncro_threads;
}	t_master;

typedef struct s_philo
{
	t_master		*master;
	int				id;
	long int		last_meal;
	long int		meal_number;
	int				is_philo_full;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*mutex_philo;
}	t_philo;

int			start_simulation(t_master *datas);
int			error_join_loop(int nb, t_master *threads_ids);
int			get_simulation_status(t_philo *philos);
int			print_state_lock(t_master *datas, int param, int philo_id);

/*--------routines-----------------*/

int			single_philo_routine(t_philo *philo);
int			philo_routine(t_philo *philo);
int			eating_routine(t_philo *philo);
int			monitoring_routine(t_master *philo);

/*--------get_set------------------*/

int			get_int(pthread_mutex_t *mutex, int *var);
int			set_int(pthread_mutex_t *mutex, int *var, int to_put_in);
int			get_long(pthread_mutex_t *mutex, long int *var);
int			set_long(pthread_mutex_t *mutex, long int *var, long int to_put_in);

/*--------time---------------------*/

int			set_begin_time(t_master *datas);
long int	get_actual_time(t_master *datas);
int			ft_usleep(t_master *datas, long int timer);

/*--------parsing_init_error-------*/

int			print_state(t_master *datas, int param, int philo_id);
int			print_error(char *str);
int			get_params(int argc, char **argv, t_params *param);
int			init_datas(t_master *datas);
int			free_datas(t_master *datas);

#endif
