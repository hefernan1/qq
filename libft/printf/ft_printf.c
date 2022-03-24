/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:32:29 by hefernan          #+#    #+#             */
/*   Updated: 2021/09/28 09:11:58 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_str(t_format *magnum, va_list lol)
{
	char	*str;
	int		i;

	str = va_arg(lol, char *);
	i = 0;
	if (!str)
	{
		str = ft_strdup("(null)");
		i++;
	}
	ft_putstring(str, magnum);
	if (i != 0)
		free(str);
}

static void	aff_tout(t_format *magnum, va_list lol)
{
	if (magnum->type == 'c')
		ft_putchar(va_arg(lol, int), magnum);
	if (magnum->type == 's')
		put_str(magnum, lol);
	if (magnum->type == 'p')
		parg(magnum, lol);
	if (magnum->type == 'u' || magnum->type == 'i' || magnum->type == 'd'
		|| magnum->type == 'x' || magnum->type == 'X')
		aff_nbr(magnum, lol);
	if (magnum->type == '%')
		ft_putchar('%', magnum);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	t_format	magnum;
	va_list		lol;

	i = 0;
	va_start (lol, str);
	magnum.len = 0;
	while (str[i])
	{
		magnum.type = 0;
		if (str[i] == '%')
		{
			i++;
			parse_f(str, &magnum, &i);
			aff_tout(&magnum, lol);
		}
		else
		{
			ft_putchar(str[i], &magnum);
			i++;
		}
	}
	va_end(lol);
	return (magnum.len);
}
