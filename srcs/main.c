/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:02:35 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/01 03:24:21 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	printf("atoi = %d, ft_atoi = %d", atoi(argv[1]), ft_atoi(argv[1]));
	return (0);
}
