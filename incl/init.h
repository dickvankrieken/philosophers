/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 12:26:42 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/22 12:20:31 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	init_data(int argc, char *argv[], t_data *data);
void	init_philosophers(t_data *data, t_philosopher *philosopher, int number_of_philosophers);
int		init_mutexes(t_data *data);
