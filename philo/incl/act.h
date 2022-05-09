/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   act.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 14:09:02 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/04 14:09:03 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACT_H
# define ACT_H

void	ph_take_forks(t_philosopher *philo);
void	ph_eat(t_philosopher *philo);
void	ph_sleep(t_philosopher *philo);
void	ph_think(t_philosopher *philo);

#endif
