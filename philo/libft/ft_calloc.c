/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 07:00:44 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:00:36 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Alloue de la mémoire comme malloc mais met toutes les valeurs
  à 0 au lieu de les laisser au hasard */
void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	s = malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}
