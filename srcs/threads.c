/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 12:07:15 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/04 13:56:38 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //temp
#include <pthread.h>
#include <unistd.h>
#include "../incl/philosophers.h"
#include "../incl/time.h"
#include "../incl/act.h"
#include "../incl/utils.h"

t_err	pthread_join_all_threads(t_data *data)
{
	int	i;

	if (pthread_join(data->monitoring_thread, NULL) != 0)
		return (PTHREAD_JOIN_FAIL);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(data->philosophers[i].thread, NULL) != 0)
		{
			return (PTHREAD_JOIN_FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

void	act(t_philosopher *philosophers)
{
	if (check_bool_with_mutex(&philosophers->data->dead_mutex,
			&philosophers->data->philosopher_dead)
		== FALSE)
		ph_take_forks(philosophers);
	if (check_bool_with_mutex(&philosophers->data->dead_mutex,
			&philosophers->data->philosopher_dead)
		== FALSE)
		ph_eat(philosophers);
	if (check_bool_with_mutex(&philosophers->data->dead_mutex,
			&philosophers->data->philosopher_dead)
		== FALSE)
		ph_sleep(philosophers);
	if (check_bool_with_mutex(&philosophers->data->dead_mutex,
			&philosophers->data->philosopher_dead)
		== FALSE)
		ph_think(philosophers);
}

void	act_number_of_times(t_philosopher *philosophers)
{
	int	i;

	i = 0;
	while ((i < philosophers->data->number_of_times_each_philosopher_must_eat)
		&& (philosophers->data->philosopher_dead == FALSE))
	{
		act(philosophers);
		i++;
	}
	philosophers->data->number_of_times_passed = TRUE;
}

void	*ft_philosopher(void *philosopher)
{
	t_philosopher	*philo_pointer;

	philo_pointer = philosopher;
	if (philo_pointer->id % 2 == 0)
		usleep(100);
	if (philo_pointer->data->number_of_times_each_philosopher_must_eat > -1)
	{
		act_number_of_times(philo_pointer);
	}
	else
	{
		while (check_bool_with_mutex(&philo_pointer->data->dead_mutex,
				&philo_pointer->data->philosopher_dead) == FALSE)
		{
			act(philo_pointer);
		}
	}
	return (NULL);
}

t_err	start_philo_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->philosophers[i].thread, NULL,
				ft_philosopher, &data->philosophers[i]) != 0)
			return (PTHREAD_CREATE_FAIL);
		i++;
	}
	return (SUCCESS);
}
