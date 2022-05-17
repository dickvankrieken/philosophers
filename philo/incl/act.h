/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   act.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 14:09:02 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/17 18:00:11 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACT_H
# define ACT_H

t_bool	ph_take_forks(t_philosopher *philo);
t_bool	ph_eat(t_philosopher *philo);
t_bool	ph_sleep(t_philosopher *philo);
t_bool	ph_think(t_philosopher *philo);

#endif
