/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:04:56 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/01 03:31:12 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *nptr)
{
	int			nb;
	short int	min_int;
	size_t		index;

	index = 0;
	nb = 0;
	min_int = 0;
	if (nptr[index] == '-' && nptr[10] == '8')
	{
		nptr[10] = '7';
		min_int = -1;
	}
	if (nptr[index] == '-' || nptr[index] == '+')
		index++;
	while (nptr[index] <= '9' && nptr[index] >= '0')
	{
		if (INT_MAX / 10 < nb || INT_MAX - (nptr[index] - '0') < nb * 10)
			return (-1);
		nb = nb * 10 + (nptr[index] - '0');
		index += 1;
	}
	if (nptr[0] == '-')
		return (nb * -1 + min_int);
	return (nb);
}
