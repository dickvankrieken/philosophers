/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:08:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/12 17:56:50 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

void	set_start_time(t_data *data);
size_t	time_stamp(void);
size_t	time_passed(size_t start);

#endif
