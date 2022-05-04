/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:11:09 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/04 13:55:25 by dvan-kri      ########   odam.nl         */
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
#include "../incl/utils.h"

int	check_who_died(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_lock(&data->last_eaten_mutex);
		if (time_passed(data->philosophers[i].last_eaten) > data->time_to_die)
		{
			pthread_mutex_unlock(&data->last_eaten_mutex);
			return (i);
		}
		pthread_mutex_unlock(&data->last_eaten_mutex);
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
	while (check_bool_with_mutex(&data_pointer->number_of_meals_mutex,
			&data_pointer->number_of_times_passed) == FALSE)
	{
		dead_philosopher_id = check_who_died(data_pointer);
		if ((dead_philosopher_id != -1))
		{
			pthread_mutex_lock(&data_pointer->dead_mutex);
			data_pointer->philosopher_dead = TRUE;
			pthread_mutex_unlock(&data_pointer->dead_mutex);
			printf("%zu %d died\n", time_passed(data_pointer->start_time),
				dead_philosopher_id + 1);
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

int	main(int argc, char *argv[])
{
	t_err			error;
	t_data			data;

	if (argc != 5 && argc != 6)
		return (usage_error());
	init_data(argc, argv, &data);
	error = init_mutexes(&data);
	if (error != SUCCESS)
		return (error_handler(error));
	set_start_time(&data);
	init_philosophers(&data);
	error = start_monitoring_thread(&data);
	if (error != SUCCESS)
		return (error_handler(error));
	error = start_philo_threads(&data);
	if (error != SUCCESS)
		return (error_handler(error));
	pthread_join_all_threads(&data);
}
