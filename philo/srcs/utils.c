/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:04:59 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/11 13:17:01 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"

static int	ft_isspace(const char str)
{
	if (str == ' ' || str == '\t' || str == '\n'
		|| str == '\v' || str == '\f' || str == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	k;

	res = 0;
	i = 0;
	k = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		k = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + ((int)str[i] - 48);
		i++;
	}
	return (res * k);
}

t_bool	check_bool_with_mutex(pthread_mutex_t *mutex, t_bool *bool)
{
	pthread_mutex_lock(mutex);
	if (*bool == TRUE)
	{
		pthread_mutex_unlock(mutex);
		return (TRUE);
	}
	else
	{
		pthread_mutex_unlock(mutex);
		return (FALSE);
	}
}

void	unlock_all_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_unlock(&data->forks[i]);
		i++;
	}
}
