/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:10:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/22 12:21:39 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../incl/philosophers.h"

int	usage_error(void)
{
	printf("Invalid number of arguments");
	return (1);
}

int	error_handler(t_data *data)
{
	int	i;

	i = 0;
	free(data->philosophers);
	i++;
	return (1);
}
