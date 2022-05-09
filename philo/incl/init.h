/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 12:26:42 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/02 12:25:10 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

void	init_data(int argc, char *argv[], t_data *data);
void	init_philosophers(t_data *data);
int		init_mutexes(t_data *data);

#endif