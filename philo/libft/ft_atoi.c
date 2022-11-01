/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 09:03:53 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:00:03 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	nb;
	long long	negative;
	long long	i;

	nb = 0;
	negative = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			negative = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i++] - '0');
		if ((nb * negative) > INT_MAX)
			return (-1);
		if ((nb * negative) < INT_MIN)
			return (0);
	}
	return (nb * negative);
}
