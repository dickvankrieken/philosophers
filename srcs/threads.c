#include <stdio.h> //temp
#include <pthread.h>
#include <unistd.h>
#include "../incl/philosopher.h"
#include "../incl/time.h"
#include "../incl/act.h"

void	pthread_join_all_threads(t_data data)
{
	int	i;

	i = 0;
	while (i < data.number_of_philosophers)
	{
		pthread_join(data.philosophers[i].thread, NULL);
		i++;
	}
}

void    *ft_philosopher(void *philosopher)
{
	t_philosopher *philo_pointer;

	philo_pointer = philosopher;
	while (1)
	{
		pthread_mutex_lock(philo_pointer->left_fork);
		ph_take_forks(philosopher);
		ph_eat(philosopher);
		ph_sleep(philosopher);
	}
	return (NULL);
}

int start_threads(t_data data)
{
	int i;

	i = 0;
	while (i < data.number_of_philosophers)
	{ 
		pthread_create(&data.philosophers[i].thread, NULL, ft_philosopher, &data.philosophers[i]);
		i++;
	}
	return (0);
}
