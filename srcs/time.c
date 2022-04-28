/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:10:27 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/28 18:02:31 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // temp
#include <sys/time.h>
#include <unistd.h>
#include "../incl/philosophers.h"
#include "../incl/time.h"

void	usleep_more_accurate(size_t time)
{
	size_t 			time_passed;
	size_t			time_start;

	time_start = time_stamp();
	time_passed = 0;
	while (time_passed < time)
	{
		usleep(100);
		time_passed = time_stamp() - time_start;
	}
}

void	set_start_time(t_data *data)
{
	data->start_time = time_stamp();
}

size_t	time_stamp(void)
{
	struct timeval	the_time;
	size_t			time_in_milliseconds;

	gettimeofday(&the_time, NULL);
	time_in_milliseconds = (the_time.tv_sec * 1000) + (the_time.tv_usec / 1000);
	return (time_in_milliseconds);
}

size_t	time_passed(size_t start)
{
	// printf(">>>%zu<<<", (time_stamp() - start));
	return (time_stamp() - start);
}
