/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 12:07:15 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/21 15:18:04 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //temp
#include <pthread.h>
#include <unistd.h>
#include "../incl/philosophers.h"
#include "../incl/time.h"
#include "../incl/act.h"

void	pthread_join_all_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(data->philosophers[i].thread, NULL);
		i++;
	}
}

void    *ft_philosopher(void *philosopher)
{
	t_philosopher *philo_pointer;

	philo_pointer = philosopher;
	while (1 && philo_pointer->data->philosopher_dead != TRUE)
	{
		ph_take_forks(philo_pointer);
		ph_eat(philo_pointer);
		ph_sleep(philo_pointer);
		ph_think(philo_pointer);
	}
	return (NULL);
}

int start_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_create(&data->philosophers[i].thread, NULL, ft_philosopher, &data->philosophers[i]);
		i++;
	}
	return (0);
}
