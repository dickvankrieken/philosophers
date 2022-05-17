/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 12:07:15 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/17 18:13:28 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include "../incl/philosophers.h"
#include "../incl/time.h"
#include "../incl/act.h"
#include "../incl/utils.h"

static t_bool	act(t_philosopher *philosophers)
{
	if (ph_take_forks(philosophers) == TRUE)
		return (TRUE);
	if (ph_eat(philosophers) == TRUE)
		return (TRUE);
	if (ph_sleep(philosophers) == TRUE)
		return (TRUE);
	if (ph_think(philosophers) == TRUE)
		return (TRUE);
	return (FALSE);
}

static void	act_number_of_times(t_philosopher *philosophers)
{
	int	i;

	i = 0;
	while ((i < philosophers->data->number_of_times_each_philosopher_must_eat))
	{
		if (act(philosophers) == TRUE)
			return ;
		i++;
	}
	pthread_mutex_lock(&philosophers->data->number_of_meals_mutex);
	philosophers->data->number_of_times_passed = TRUE;
	pthread_mutex_unlock(&philosophers->data->number_of_meals_mutex);
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
		while (1)
		{
			if (act(philo_pointer) == TRUE)
				return (NULL);
		}
	}
	return (NULL);
}

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
