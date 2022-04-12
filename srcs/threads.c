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
    take_forks();
	printf("time passed == %zu\n", (time_stamp() - philo_pointer->data->start_time));
	usleep(100000);
	printf("time passed == %zu\n", (time_stamp() - philo_pointer->data->start_time));	
	return (NULL);
}

int start_threads(t_philosopher *philosopher)
{
	pthread_create(&philosopher[0].thread, NULL, ft_philosopher, philosopher);

	return (0);
}