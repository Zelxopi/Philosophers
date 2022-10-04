/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:39:26 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:02:51 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
c = caractère à écrire
fd = file descriptor sur lequel écrire
*/
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
