/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:14:10 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:02:44 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
dst = where to copy
src = to be copied
len = number of cases
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	if (!dst && !src)
		return (NULL);
	if (d > s)
		while (len--)
			d[len] = s[len];
	else
	{
		while (len--)
		{
			*d++ = *s++;
		}
	}
	return (dst);
}
