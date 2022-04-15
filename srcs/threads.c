#include <stdio.h> //temp
#include <pthread.h>
#include <unistd.h>
#include "../incl/philosopher.h"
#include "../incl/time.h"
#include "../incl/act.h"

void    *ft_philosopher(void *philosopher)
{
	t_philosopher *philo_pointer;

	philo_pointer = philosopher;
	while (1)
	{
		ph_take_forks(philosopher);
		ph_eat(philosopher);
		ph_sleep(philosopher);
	}
	return (NULL);
}

int start_threads(t_philosopher *philosopher)
{
	int i;

	i = 0;
	while (i < philosopher->data->number_of_philosophers)
	{
		pthread_create(&philosopher[i].thread, NULL, ft_philosopher, &philosopher[i]);
		i++;
	}
	return (0);
}
