/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:46:35 by mtrembla          #+#    #+#             */
/*   Updated: 2022/06/17 11:03:16 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char **ft_split(char const *s, char c);
 * *s = la string à découper
 *  c = le caractère délimitant les séparation
 *
 *  Retourne les nouvelles strings. NULL si malloc échoue */

static char	**ft_malloc_error(char **tab)
{
	while (*tab--)
	{
		free (tab);
	}
	free (tab);
	return (NULL);
}

static unsigned int	ft_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	strs;

	if (!*s)
		return (0);
	i = 0;
	strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		strs++;
	return (strs);
}

static void	ft_next_str(char **s2, unsigned int *s2len, char c)
{
	unsigned int	i;

	*s2 += *s2len;
	*s2len = 0;
	i = 0;
	while (**s2 && **s2 == c)
		(*s2)++;
	while ((*s2)[i])
	{
		if ((*s2)[i] == c)
			return ;
		(*s2len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*s2;
	unsigned int	s2len;
	unsigned int	strs;
	unsigned int	i;

	s2 = (char *)s;
	s2len = 0;
	i = 0;
	if (!s)
		return (NULL);
	strs = ft_nb_strs(s, c);
	tab = (char **)malloc(sizeof(char *) * (strs + 1));
	if (!tab)
		return (NULL);
	while (i < strs)
	{
		ft_next_str(&s2, &s2len, c);
		tab[i] = (char *)malloc(sizeof(char) * (s2len + 1));
		if (!tab[i])
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i++], s2, s2len + 1);
	}
	tab[i] = NULL;
	return (tab);
}
