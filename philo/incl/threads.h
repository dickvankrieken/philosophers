/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 14:08:49 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/04 14:08:50 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include "philosophers.h"

t_err	pthread_join_all_threads(t_data *data);
int		start_philo_threads(t_data *data);

#endif
