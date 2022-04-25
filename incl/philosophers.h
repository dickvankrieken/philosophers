/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosophers.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 12:07:26 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/25 18:02:17 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

typedef enum t_err
{
	SUCCESS,
	MUTEX_FAIL,
	PTHREAD_CREATE_FAIL
}

typedef enum e_bool
{
	FALSE, TRUE
}	t_bool;

typedef struct s_philosopher
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t *right_fork;
	pthread_t		thread;
	size_t			last_eaten;
	int				id;
	t_bool			is_dead;
	struct s_data	*data;
}	t_philosopher;

typedef struct s_data
{
	/* pthread_mutex_t	*forks; */
	pthread_mutex_t print_mutex;
	t_philosopher	*philosophers;
	t_bool			philosopher_dead;
	size_t			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				number_of_philosophers;
	int				number_of_times_each_philosopher_must_eat;

}	t_data;

#endif
