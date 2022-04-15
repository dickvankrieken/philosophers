/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 12:54:27 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/15 16:57:45 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../incl/philosopher.h"
#include "../incl/utils.h"
#include "../incl/time.h"
#include "../incl/threads.h"
#include "../incl/error.h"

void	init_data(int argc, char *argv[], t_data *data)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

int	malloc_resources(t_data **data, t_philosopher **philosophers, int number_of_philosophers)
{
	*data = malloc(sizeof(t_data));
	if (!data)
		return (-1);
	*philosophers = malloc(sizeof(t_philosopher) * number_of_philosophers);
	if (!philosophers)
		return (-1);
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * number_of_philosophers);
	if (!((*data)->forks))
		return (-1);
	return (0);
}

void	init_philosophers(t_data *data, t_philosopher *philosophers)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		philosophers[i].data = data;
		philosophers[i].id = i + 1;
		if (i = 0)
			philosophers[i].right_fork = data->forks[data->number_of_philosophers - 1];
		else
			philosophers[i].right_fork = data->forks[i - 1];
		philosophers[i].left_fork = data->forks[i];
		i++;
	}
}

void	pthread_join_all_threads(t_philosopher *philosophers)
{
	int	i;

	i = 0;
	while (i < philosophers[0].data->number_of_philosophers)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
}


int main(int argc, char *argv[])
{
	t_data			*data;
	t_philosopher	*philosophers;

	philosophers = NULL;
	data = NULL;
	if (argc != 5 && argc != 6)
		return (usage_error());
	if (malloc_resources(&data, &philosophers, ft_atoi(argv[1])))
		return (-1);
	init_data(argc, argv, data);
	init_philosophers(data, philosophers);
	set_start_time(data);
	start_threads(philosophers);
	pthread_join_all_threads(philosophers);
}

/*
number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/
