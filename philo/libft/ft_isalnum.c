/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:12:36 by mtrembla          #+#    #+#             */
/*   Updated: 2021/09/07 15:03:15 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*test for alphanumeric characters (0 to 9 and A,a to Z,z)
 aka if isalpha and isdigit */
int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
