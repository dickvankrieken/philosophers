/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 13:56:39 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/19 14:22:05 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../incl/philosopher.h"

int	usage_error(void)
{
	printf("Invalid number of arguments");
	return (1);
}

int	error_handler(t_data data)
{
	int	i;

	i = 0;

	free(data.philosophers);
	i++;
	return (1);
}