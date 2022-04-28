/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   act.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:10:47 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/28 17:33:07 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../incl/philosophers.h"
#include "../incl/time.h"

void	ph_take_forks(t_philosopher *philo)
{
	if (philo->data->philosopher_dead == FALSE)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		printf("[%zu] (%d) has taken a fork\n", time_passed(philo->data->start_time), philo->id);
		printf("[%zu] (%d) has taken a fork\n", time_passed(philo->data->start_time), philo->id);
	}
}

void	ph_eat(t_philosopher *philo)
{
	if (philo->data->philosopher_dead == FALSE)
	{
		philo->last_eaten = time_stamp();
		printf("[%zu] (%d) is eating\n", time_passed(philo->data->start_time), philo->id);
		usleep_more_accurate(philo->data->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	ph_sleep(t_philosopher *philo)
{
	if (philo->data->philosopher_dead == FALSE)
	{
		printf("[%zu] (%d) is sleeping\n", time_passed(philo->data->start_time), philo->id);
		usleep_more_accurate(philo->data->time_to_sleep);
		printf("[%zu] (%d) is thinking\n", time_passed(philo->data->start_time), philo->id);

	}
}
