/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:48:55 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:04:04 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*s = chaine à picosser
*f = fonction à appliquer sur tout les caractère

 return une nouvelle chaine avec malloc résultant des *f successif.
 NULL si échec.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sptr;
	int		i;

	if (!s || !f)
		return (NULL);
	sptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!sptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		sptr[i] = f(i, s[i]);
		i++;
	}
	sptr[i] = '\0';
	return (sptr);
}
