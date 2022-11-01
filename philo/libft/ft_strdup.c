/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 07:33:19 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:03:28 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Alloue assez de mémoire pour copier la s1, fait la copie et retourne
 un pointeur dessus*/
char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
