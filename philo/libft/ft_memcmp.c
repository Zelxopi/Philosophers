/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 08:10:48 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:02:36 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
compares the first n bytes of memory area s1 & s2

return value < 0 if s1 is less than s2
return value > 0 if s2 is less than s1
return value = 0 if s1 is equal to s2

s1 & s2 = pointer to blocks of memory
n = number of byte to be compared
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*one;
	unsigned char	*two;
	size_t			i;

	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (one[i] != two[i])
			return ((int)(one[i] - two [i]));
		if (n == 0)
			return ((int)n);
		i++;
	}
	return (0);
}
