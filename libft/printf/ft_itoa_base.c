/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 22:49:02 by hefernan          #+#    #+#             */
/*   Updated: 2021/09/21 05:13:50 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_lenlen(unsigned long n, int len_base)
{
	int		size;

	size = 0;
	while (n > 0)
	{
		n /= len_base;
		size++;
	}
	return (size);
}

static char	*ft_div_mod(unsigned long n, char *base)
{
	int		size;
	int		mod;
	int		len_base;
	char	*str;

	len_base = ft_strlen(base);
	size = ft_lenlen(n, len_base);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!(str))
		return (NULL);
	str[size] = '\0';
	size--;
	mod = 0;
	while (n > 0)
	{
		mod = n % len_base;
		str[size] = base[mod];
		n /= len_base;
		size--;
	}
	return (str);
}

static char	*ft_base_0(char *base)
{
	char		*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!(str))
		return (NULL);
	str[0] = base[0];
	str[1] = '\0';
	return (str);
}

char	*ft_itoa_base(unsigned long n, char *base)
{
	if (n == 0)
		return (ft_base_0(base));
	if (base == NULL)
		return (NULL);
	else
		return (ft_div_mod(n, base));
}
