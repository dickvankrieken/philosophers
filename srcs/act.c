/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   act.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 17:49:46 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/15 16:53:20 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../incl/philosopher.h"
#include "../incl/time.h"

void	ph_take_forks(t_philosopher *philo)
{
	printf("[%zu] (%d) has taken a fork\n", time_passed(philo->data->start_time), philo->id);
}

void	ph_eat(t_philosopher *philo)
{
	printf("[%zu] (%d) is eating\n", time_passed(philo->data->start_time), philo->id);
	usleep_more_accurate(philo->data->time_to_eat);
}

void	ph_sleep(t_philosopher *philo)
{
	printf("[%zu] (%d) is sleeping\n", time_passed(philo->data->start_time), philo->id);
	usleep_more_accurate(philo->data->time_to_sleep);
}
