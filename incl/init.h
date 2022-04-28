/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 12:26:42 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/28 16:20:52 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	init_data(int argc, char *argv[], t_data *data);
void	init_philosophers(t_data *data);
int		init_mutexes(t_data *data);
