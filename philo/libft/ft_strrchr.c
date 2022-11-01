/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 07:49:41 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:04:20 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
locate the last occurence of the character
str = the string
c = character to be located
*/
char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*s)
		s++;
	while (s >= str)
		if (*s-- == (char)c)
			return ((char *)s + 1);
	return (NULL);
}
