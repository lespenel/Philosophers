/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:16:05 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/01 17:32:18 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <time.h>
#include <stdio.h>

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("tv_sec = %ld, tv_usec = %ld\n", time.tv_sec, time.tv_usec);
	return (0);
}
