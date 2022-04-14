/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 12:54:27 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/14 14:55:44 by dvan-kri      ########   odam.nl         */
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

int	malloc_philosophers(t_philosopher **philosophers, int number_of_philosophers)
{
	/*
	 malloc de mutex - vorken
	 malloc de t_philosopher structs
	 malloc de data
	 */
	*philosophers = malloc(sizeof(t_philosopher) * number_of_philosophers);
	if (!philosophers)
		return (-1);
	return (0);
}

int	malloc_data(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!data)
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
		i++;
	}
//	printf("de start_time is %zu", philosophers[0].data->start_time);
}

int main(int argc, char *argv[])
{
	t_data			*data;
	t_philosopher	*philosophers;

	philosophers = NULL;
	data = NULL;
	if (argc != 5 && argc != 6)
		return (usage_error());
	if (malloc_data(&data))
		return (-1);
	init_data(argc, argv, data);
	if (malloc_philosophers(&philosophers, data->number_of_philosophers))
		return (-1);
	init_philosophers(data, philosophers);
	set_start_time(data);
	start_threads(philosophers);
	pthread_join(philosophers[0].thread, NULL);
}

/*
number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/
