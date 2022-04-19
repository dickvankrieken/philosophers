/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   act.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 17:49:46 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/19 19:04:00 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../incl/philosopher.h"
#include "../incl/time.h"

void	ph_take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	printf("[%zu] (%d) has taken a fork\n", time_passed(philo->data->start_time), philo->id);
	printf("[%zu] (%d) has taken a fork\n", time_passed(philo->data->start_time), philo->id);
}

void	ph_eat(t_philosopher *philo)
{
	printf("[%zu] (%d) is eating\n", time_passed(philo->data->start_time), philo->id);
	usleep_more_accurate(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ph_sleep(t_philosopher *philo)
{
	printf("[%zu] (%d) is sleeping\n", time_passed(philo->data->start_time), philo->id);
	usleep_more_accurate(philo->data->time_to_sleep);
}
