/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   act.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:10:47 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/17 17:58:47 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../incl/philosophers.h"
#include "../incl/time.h"
#include "../incl/utils.h"

t_bool	ph_take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (print_act(philo, "has taken a fork") == TRUE)
		return (TRUE);
	pthread_mutex_lock(philo->left_fork);
	if (print_act(philo, "has taken a fork") == TRUE)
		return (TRUE);
	return (FALSE);
}

t_bool	ph_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->last_eaten_mutex);
	philo->last_eaten = time_stamp();
	pthread_mutex_unlock(&philo->last_eaten_mutex);
	if (print_act(philo, "is eating") == TRUE)
		return (TRUE);
	usleep_more_accurate(philo->data, philo->data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (FALSE);
}

t_bool	ph_sleep(t_philosopher *philo)
{
	if (print_act(philo, "is sleeping") == TRUE)
		return (TRUE);
	usleep_more_accurate(philo->data, philo->data->time_to_sleep);
	return (FALSE);
}

t_bool	ph_think(t_philosopher *philo)
{
	if (print_act(philo, "is thinking") == TRUE)
		return (TRUE);
	return (FALSE);
}
