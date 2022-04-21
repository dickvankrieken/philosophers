/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:11:09 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/21 15:45:23 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../incl/philosophers.h"
#include "../incl/utils.h"
#include "../incl/time.h"
#include "../incl/threads.h"
#include "../incl/error.h"
#include "../incl/init.h"
#include "../incl/act.h" //temp
#include <unistd.h> //temp


int	malloc_resources(t_data *data, int number_of_philosophers)
{
	data->philosophers = malloc(sizeof(t_philosopher) * number_of_philosophers);
	if (!data->philosophers)
		return (-1);
	data->forks = malloc(sizeof(pthread_mutex_t) * number_of_philosophers);
	if (!data->forks)
		return (-1);
	return (0);
}

void	death_checker(t_data *data)
{
	/* als de time_to_die kleiner is dan de tijd die verstreken is sinds de last_eaten van een Ph, dan moet er een berichtje komen en moet de simulatie stoppen . . .
	 */
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (data->time_to_die < time_passed(data->philosophers[i].last_eaten))
		{
			/* doe iets wat er voor zorgt dat de hele simulatie stopt
			maar wat dan? en hoe dan? */
			printf("time passed == %zu\n", time_passed(data->philosophers[i].last_eaten));
			data->philosopher_dead = TRUE;
			return ;
		}
		i++;
	}
	usleep(5);
	death_checker(data);
}


int main(int argc, char *argv[])
{
	t_data			data;

	if (argc != 5 && argc != 6)
		return (usage_error());
	if (malloc_resources(&data, ft_atoi(argv[1])) == -1)
		return (error_handler(data));
	init_data(argc, argv, &data);
	init_forks(&data);
	set_start_time(&data);
	init_philosophers(&data, data.philosophers, data.number_of_philosophers);

	start_threads(&data);
	death_checker(&data);
	printf("someone died\n");
	pthread_join_all_threads(&data);
}

/*
number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
*/
