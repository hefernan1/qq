/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:14:32 by hefernan          #+#    #+#             */
/*   Updated: 2020/12/31 16:10:32 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_countwords(char const *s, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static char			**ft_tab(char *s, char c, char **tab, int words)
{
	int				k;
	int				f;
	unsigned int	i;
	unsigned int	j;

	k = 0;
	i = 0;
	f = 0;
	while (k < words)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (!(tab[k] = ft_substr(s, j, i - j)))
		{
			while (f < k)
				free(tab[f++]);
			return (NULL);
		}
		k++;
	}
	tab[k] = NULL;
	return (tab);
}

char				**ft_split(char const *s, char c)
{
	char			**tab;
	int				words;

	tab = NULL;
	if (!s)
		return (NULL);
	words = ft_countwords((char *)s, c);
	if (!(tab = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	if (!(tab = ft_tab((char *)s, c, tab, words)))
	{
		free(tab);
		tab = NULL;
	}
	return (tab);
}
