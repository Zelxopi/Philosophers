/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:41:39 by mtrembla          #+#    #+#             */
/*   Updated: 2022/10/04 13:11:40 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*s = string à écrire
fd = fd sur lequel écrire
*/
void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
			write (fd, s++, 1);
}
