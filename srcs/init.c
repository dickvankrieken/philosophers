/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 12:07:06 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/22 12:24:19 by dvan-kri      ########   odam.nl         */
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
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

void	init_philosophers(t_data *data, t_philosopher *philosopher, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		philosopher[i].data = data;
		philosopher[i].id = i + 1;
		if (i == 0)
			philosopher[i].right_fork = &data->forks[data->number_of_philosophers - 1];
		else
			philosopher[i].right_fork = &data->forks[i - 1];
		philosopher[i].left_fork = &data->forks[i];
		philosopher[i].last_eaten = data->start_time;
		i++;
	}
}

int		init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) == -1)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) == -1)
		return (1);
	return (0);
}
