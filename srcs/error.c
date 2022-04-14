/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 13:56:39 by dvan-kri      #+#    #+#                 */
/*   Updated: 2022/04/14 13:56:49 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	usage_error(void)
{
	printf("Invalid number of arguments");
	return (1);
}
