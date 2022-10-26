/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:41:20 by mtrembla          #+#    #+#             */
/*   Updated: 2022/08/09 14:41:34 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
compare s1 and s2

s1 = first string to be compared
s2 = second string to be compared

return value < 0 s1 less than s2
return value > 0 s2 less than s1
return value = 0 s1 is equal to s2
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2))
		if (*s1++ != *s2++)
			return ((unsigned char) *--s1 - (unsigned char) *--s2);
	return (0);
}
