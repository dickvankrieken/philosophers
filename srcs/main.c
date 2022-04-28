/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:11:09 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/28 18:35:59 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "../incl/philosophers.h"
#include "../incl/time.h"
#include "../incl/threads.h"
#include "../incl/error.h"
#include "../incl/init.h"

/* int	malloc_resources(t_data *data, int number_of_philosophers) */
/* { */
/* 	data->philosophers = malloc(sizeof(t_philosopher) * number_of_philosophers); */
/* 	if (!data->philosophers) */
/* 		return (-1); */
/* 	data->forks = malloc(sizeof(pthread_mutex_t) * number_of_philosophers); */
/* 	if (!data->forks) */
/* 		return (-1); */
/* 	return (0); */
/* } */


void	*ft_monitor(void *data)
{
	t_data	*data_pointer;

	data_pointer = data;
	while (1)
	{
		/* als de time_to_die is verstreken gerekend vanaf de last_eaten time van iedere ph, 
		zet philosopher_dead naar true, print 'Philosopher died, en return de functie. */
		

		usleep(1000000);
	}

	return (NULL);
}

t_err	start_monitoring_thread(t_data *data)
{

	pthread_create(&data->monitoring_thread, NULL, ft_monitor, &data);
	return (SUCCESS);
}

int main(int argc, char *argv[])
{
	t_err			error;
	t_data			data;

	if (argc != 5 && argc != 6)
		return (usage_error());
	init_data(argc, argv, &data);
	if ((error = init_mutexes(&data)) != SUCCESS)
		return (error_handler(error));
	set_start_time(&data);
	init_philosophers(&data);
	// int i = -1;
	// while (i++ < data.number_of_philosophers)
	// 	printf("thread %d left fork: %p right fork: %p\n", i + 1, data.philosophers[i].left_fork, data.philosophers[i].right_fork);
	if ((error = start_philo_threads(&data)) != SUCCESS)
	 	return(error_handler(error));
	start_monitoring_thread(&data);
	pthread_join_all_threads(&data);
}

/*
number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/
