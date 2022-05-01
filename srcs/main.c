/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:11:09 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/01 13:22:08 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> //temp
#include "../incl/philosophers.h"
#include "../incl/time.h"
#include "../incl/threads.h"
#include "../incl/error.h"
#include "../incl/init.h"

int	check_who_died(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (time_passed(data->philosophers[i].last_eaten) > data->time_to_die)
		{
			return (i);
		}	
		i++;
	}
	return (-1);
}

void	*ft_monitor(void *data)
{
	t_data	*data_pointer;
	int		dead_philosopher_id;

	dead_philosopher_id = 0;
	data_pointer = data;
	while (data_pointer->number_of_times_passed == FALSE)
	{
		dead_philosopher_id = check_who_died(data_pointer);
		if ((dead_philosopher_id != -1))
		{
			data_pointer->philosopher_dead = TRUE;
			if (data_pointer->number_of_philosophers == 1)
			{
				pthread_mutex_unlock(data_pointer->philosophers[0].right_fork);
			}
			pthread_mutex_lock(&data_pointer->print_mutex);
			printf("[%zu] (%d) died\n", time_passed(data_pointer->start_time), dead_philosopher_id + 1);
			pthread_mutex_unlock(&data_pointer->print_mutex);
			return (NULL);
		}
	}
	return (NULL);
}

t_err	start_monitoring_thread(t_data *data)
{
	if (pthread_create(&data->monitoring_thread, NULL, ft_monitor, data) != 0)
		return (PTHREAD_CREATE_FAIL);
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
	if ((error = start_monitoring_thread(&data)) != SUCCESS)
		return (error_handler(error));
	if ((error = start_philo_threads(&data)) != SUCCESS)
	 	return(error_handler(error));
	pthread_join_all_threads(&data);
}

/*
number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/
