#ifndef THREADS_H
# define THREADS_H

# include "philosophers.h"

t_err	pthread_join_all_threads(t_data *data);
int		start_philo_threads(t_data *data);

#endif
