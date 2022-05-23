/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:11:09 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/23 15:21:53 by dvan-kri      ########   odam.nl         */
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
#include "../incl/utils.h"

static int	check_who_died(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_lock(&data->philosophers[i].last_eaten_mutex);
		if (time_passed(data->philosophers[i].last_eaten) > data->time_to_die)
		{
			pthread_mutex_unlock(&data->philosophers[i].last_eaten_mutex);
			unlock_all_forks(data);
			return (i);
		}
		pthread_mutex_unlock(&data->philosophers[i].last_eaten_mutex);
		i++;
	}
	return (-1);
}

static void	*ft_monitor(void *data)
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
			printf("%lld %d died\n", time_passed(data_pointer->start_time),
				dead_philosopher_id + 1);
			pthread_mutex_unlock(&data_pointer->dead_mutex);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

static t_err	start_monitoring_thread(t_data *data)
{
	if (pthread_create(&data->monitoring_thread, NULL, ft_monitor, data) != 0)
		return (PTHREAD_CREATE_FAIL);
	return (SUCCESS);
}

static t_err	validate_input(int argc, t_data data)
{
	if (data.number_of_philosophers < 1 || data.number_of_philosophers > 200
		|| data.time_to_eat < 1 || data.time_to_die < 1
		|| data.time_to_sleep < 1)
		return (WRONG_ARGUMENT);
	if (argc == 6 && data.number_of_times_each_philosopher_must_eat < 1)
		return (WRONG_ARGUMENT);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_err			error;
	t_data			data;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid number of arguments");
		return (0);
	}
	init_data(argc, argv, &data);
	error = validate_input(argc, data);
	if (error != SUCCESS)
		return (error_handler(error));
	error = init_mutexes(&data);
	if (error != SUCCESS)
		return (error_handler(error));
	data.start_time = time_stamp();
	init_philosophers(&data);
	error = start_monitoring_thread(&data);
	if (error != SUCCESS)
		return (error_handler(error));
	error = start_philo_threads(&data);
	if (error != SUCCESS)
		return (error_handler(error));
	pthread_join_all_threads(&data);
}
