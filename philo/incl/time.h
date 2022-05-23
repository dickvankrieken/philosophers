/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:08:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/18 10:48:52 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include "philosophers.h"

void	usleep_more_accurate(t_data *data, size_t time);
size_t	time_stamp(void);
size_t	time_passed(size_t start);

#endif
