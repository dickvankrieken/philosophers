/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   act.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:10:47 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/16 11:43:41 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../incl/philosophers.h"
#include "../incl/time.h"
#include "../incl/utils.h"

static void	ph_take_fork(t_philosopher *philo)
{
	if (check_bool_with_mutex(&philo->data->dead_mutex,
			&philo->data->philosopher_dead) == FALSE)
	{
		printf("%d %d has taken a fork\n",
			time_passed(philo->data->start_time), philo->id);
	}	
}

void	ph_take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ph_take_fork(philo);
	pthread_mutex_lock(philo->left_fork);
	ph_take_fork(philo);
}

void	ph_eat(t_philosopher *philo)
{
	if (check_bool_with_mutex(&philo->data->dead_mutex,
			&philo->data->philosopher_dead) == FALSE)
	{
		pthread_mutex_lock(&philo->last_eaten_mutex);
		philo->last_eaten = time_stamp();
		pthread_mutex_unlock(&philo->last_eaten_mutex);
		if (check_bool_with_mutex(&philo->data->dead_mutex,
				&philo->data->philosopher_dead) == FALSE)
		{
			printf("%d %d is eating\n",
				time_passed(philo->data->start_time), philo->id);
		}
		usleep_more_accurate(philo->data, philo->data->time_to_eat);
	}
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ph_sleep(t_philosopher *philo)
{
	if (check_bool_with_mutex(&philo->data->dead_mutex,
			&philo->data->philosopher_dead) == FALSE)
	{
		printf("%d %d is sleeping\n",
			time_passed(philo->data->start_time), philo->id);
		usleep_more_accurate(philo->data, philo->data->time_to_sleep);
	}
}

void	ph_think(t_philosopher *philo)
{
	if (check_bool_with_mutex(&philo->data->dead_mutex,
			&philo->data->philosopher_dead) == FALSE)
	{
		printf("%d %d is thinking\n",
			time_passed(philo->data->start_time), philo->id);
	}
}
