/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   act.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 17:49:46 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/12 17:58:15 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../incl/philosopher.h"
#include "../incl/time.h"

void	take_forks(t_philosopher *philo)
{
	printf("[%zu] (%d) has taken a fork", time_passed(philo->data->start_time), philo->id);
}
