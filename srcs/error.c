/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:10:41 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/05/08 16:50:43 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../incl/philosophers.h"

int	usage_error(void)
{
	return (1);
}

void	error_handler(t_err error)
{
	if (error == WRONG_ARGUMENT)
		printf("An error has occured: WRONG ARGUMENT");
	else if (error == MUTEX_FAIL)
		printf("An error has occured: MUTEX FAILED");
	else if (error == PTHREAD_CREATE_FAIL)
		printf("An error has occured: PTHREAD CREATE FAILED");
	else if (error == PTHREAD_JOIN_FAIL)
		printf("An error has occured: PTHREAD JOIN FAILED");
}
