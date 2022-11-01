/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 08:25:44 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:04:14 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 Locate null terminated string(needle) in the string(haystack).
 Not more than len are searched. Character after a \0 are not searched.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlen;
	size_t	i;

	i = 0;
	needlen = ft_strlen(needle);
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && (i < len))
	{
		if ((ft_strncmp(haystack, needle, needlen) == 0)
			&& (i + needlen <= len))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
