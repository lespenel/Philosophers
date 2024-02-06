/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:04:56 by lespenel          #+#    #+#             */
/*   Updated: 2024/02/06 04:24:29 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *nptr)
{
	int			nb;
	size_t		len;
	size_t		index;

	len = 0;
	index = 0;
	nb = 0;
	while (nptr[len])
		len++;
	if (nptr[index] < '0' || nptr[index] > '9')
		return (-1);
	while (nptr[index] <= '9' && nptr[index] >= '0')
	{
		if (INT_MAX / 10 < nb || INT_MAX - (nptr[index] - '0') < nb * 10)
			return (-1);
		nb = nb * 10 + (nptr[index] - '0');
		index += 1;
	}
	if (len != index)
		return (-1);
	return (nb);
}
