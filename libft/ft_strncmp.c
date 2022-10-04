/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 07:56:02 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:04:09 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
compare the first n bytes of s1 and s2

s1 = first string to be compared
s2 = second string to be compared
n = number of characters to compare

return value < 0 s1 less than s2
return value > 0 s2 less than s1
return value = 0 s1 is equal to s2
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
		if (*s1++ != *s2++)
			return ((unsigned char) *--s1 - (unsigned char) *--s2);
	return (0);
}
