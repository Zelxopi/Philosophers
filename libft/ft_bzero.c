/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:31:09 by mtrembla          #+#    #+#             */
/*   Updated: 2021/09/11 11:05:12 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//change les cases d'une string en 0
void	ft_bzero(void *s, size_t n)
{
	char	*clean;

	clean = s;
	while (n--)
		*clean++ = 0;
}
