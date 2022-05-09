/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:05:30 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/09 11:28:14 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

t_bool	check_bool_with_mutex(pthread_mutex_t *mutex, t_bool *bool);
int		ft_atoi(const char *str);
void	unlock_all_forks(t_data *data);

#endif
