/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 12:54:27 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/12 17:59:45 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../incl/philosopher.h"
#include "../incl/utils.h"
#include "../incl/time.h"
#include "../incl/threads.h"

void	init_data(int argc, char *argv[], t_data *data)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

int	usage_error(void)
{
	printf("Invalid number of arguments");
	return (1);
}

int	malloc_philosophers(t_data *data, t_philosopher *philosophers)
{
	philosophers = malloc(sizeof(t_philosopher) * data->number_of_philosophers);
	if (!philosophers)
		return (1);
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
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_data			*data;
	t_philosopher	*philosophers;

	philosophers = NULL;
	if (argc != 5 && argc != 6)
		return (usage_error());
	data = malloc(sizeof(t_data) * 1);
	init_data(argc, argv, data);
	set_start_time(data);
	philosophers = malloc(sizeof(t_philosopher) * data->number_of_philosophers);
	if (!philosophers)
		return (1);
	init_philosophers(data, philosophers);
	start_threads(philosophers);
	pthread_join(philosophers[0].thread, NULL);
}

/*
number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/
