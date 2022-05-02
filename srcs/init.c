/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 12:07:06 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/02 12:22:56 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"
#include "../incl/utils.h"

void	init_data(int argc, char *argv[], t_data *data)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->philosopher_dead = FALSE;
	data->number_of_times_passed = FALSE;
	if (argc == 6)
	{
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	}
	else
		data->number_of_times_each_philosopher_must_eat = -1;
}

void	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->philosophers[i].data = data;
		data->philosophers[i].id = i + 1;
		if (i == 0)
			data->philosophers[i].right_fork
				= &data->forks[data->number_of_philosophers - 1];
		else
			data->philosophers[i].right_fork = &data->forks[i - 1];
		data->philosophers[i].left_fork = &data->forks[i];
		data->philosophers[i].last_eaten = data->start_time;
		i++;
	}
}

t_err	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) == -1)
			return (MUTEX_FAIL);
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) == -1)
		return (MUTEX_FAIL);
	return (0);
}
