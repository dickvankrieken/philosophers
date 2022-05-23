/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:08:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/23 15:35:42 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include "philosophers.h"

void		usleep_more_accurate(t_data *data, long long time);
long long	time_stamp(void);
long long	time_passed(long long start);

#endif
