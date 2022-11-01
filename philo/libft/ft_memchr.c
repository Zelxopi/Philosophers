/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 08:04:29 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:02:31 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
search for the first occurrence of the character c in the first n bytes 
of the stringpointed to by s. 
Return pointer to the matching byte, NULL if no match.

s = where the search is performed
c = value to be passed as an int (but function perform byte by byte using
unsigned char conversion of this value)
n = number of byte to be analysed
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		if (*str++ == (unsigned char)c)
			return (str - 1);
	return (NULL);
}
