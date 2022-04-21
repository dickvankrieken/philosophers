#ifndef THREADS_H
# define THREADS_H

# include "philosophers.h"

void	pthread_join_all_threads(t_data *data);
int		start_threads(t_data *data);

#endif
