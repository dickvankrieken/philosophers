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
	ph_take_forks(philosopher);
	ph_eat(philosopher);
	ph_sleep(philosopher);
	return (NULL);
}

int start_threads(t_philosopher *philosopher)
{
	pthread_create(&philosopher[0].thread, NULL, ft_philosopher, philosopher);
	return (0);
}
