/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:22:27 by mtrembla          #+#    #+#             */
/*   Updated: 2021/09/11 10:52:53 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void *b; select la string
int c; la valeur à mettre
size_t len; nombre de case où mettre la valeur de int c
*/
void	*ft_memset(void *b, int c, size_t len)
{
	char	*a;

	a = (char *)b;
	while (len)
	{
		*a++ = (char)c;
		len--;
	}
	return (b);
}
