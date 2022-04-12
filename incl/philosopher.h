/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philosopher.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 12:57:10 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/12 17:48:11 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include "philosopher.h"

typedef enum e_bool
{
	false, true
}	t_bool;

typedef struct s_data
{
	size_t	start_time;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_philosophers;
	int		number_of_times_each_philosopher_must_eat;	
}	t_data;

typedef struct s_philosopher
{
	pthread_t	 thread;
	size_t	last_eaten;
	int		id;
	t_bool	is_dead;
	t_data	*data;
}	t_philosopher;

#endif
