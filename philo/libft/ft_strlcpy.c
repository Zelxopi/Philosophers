/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:28:40 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:03:53 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Copie la longueur d'une string et retourne la copie terminé par '\0' 
en plus de la longueur
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (--dstsize && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}	
