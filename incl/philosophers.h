/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 12:07:26 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/08 16:44:21 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

# define MAX_PHILOS 200

typedef enum t_err
{
	SUCCESS,
	WRONG_ARGUMENT,
	MUTEX_FAIL,
	PTHREAD_JOIN_FAIL,
	PTHREAD_CREATE_FAIL
}	t_err;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_philosopher
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	size_t			last_eaten;
	int				id;
	t_bool			is_dead;
	struct s_data	*data;
}	t_philosopher;

typedef struct s_data
{
	t_philosopher	philosophers[MAX_PHILOS];
	pthread_mutex_t	forks[MAX_PHILOS];
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	last_eaten_mutex;
	pthread_mutex_t	number_of_meals_mutex;
	pthread_t		monitoring_thread;
	t_bool			philosopher_dead;
	t_bool			number_of_times_passed;
	size_t			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				number_of_philosophers;
	int				number_of_times_each_philosopher_must_eat;
}	t_data;

#endif
