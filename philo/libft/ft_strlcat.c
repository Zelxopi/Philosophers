/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:55:57 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:03:47 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Return length of dst(before concatenation) plus lenght of src. 
 Return the string terminated by \0 but not filled with 0
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (dst[len] && len < dstsize)
		len++;
	i = len;
	while (src[len - i] && (len + 1) < dstsize)
	{
		dst[len] = src[len - i];
		len++;
	}
	if (i < dstsize)
		dst[len] = '\0';
	return (i + ft_strlen(src));
}
