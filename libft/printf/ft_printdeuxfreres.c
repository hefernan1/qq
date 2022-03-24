/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdeuxfreres.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:53:21 by hefernan          #+#    #+#             */
/*   Updated: 2021/09/28 09:11:55 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_format *magnum)
{
	write(1, &c, 1);
	magnum->len++;
}

void	ft_putstring(char *str, t_format *magnum)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], magnum);
		i++;
	}
}

void	parse_f(const char *str, t_format *magnum, int *n)
{
	if (str[*n] == 'c' || str[*n] == 's' || str[*n] == 'p' || str[*n] == 'd'
		|| str[*n] == 'i' || str[*n] == 'u' || str[*n] == 'x' || str[*n] == 'X'
		|| str[*n] == '%')
		magnum->type = str[*n];
	*n = *n + 1;
}

void	parg(t_format *magnum, va_list lol)
{
	char		*str;
	void		*arg;
	long long	nbr;

	arg = va_arg(lol, void *);
	nbr = (long long)arg;
	str = ft_itoa_base(nbr, "0123456789abcdef");
	ft_putstring("0x", magnum);
	ft_putstring(str, magnum);
	free (str);
}

void	aff_nbr(t_format *magnum, va_list lol)
{
	char	*str;

	if (magnum->type == 'd' || magnum->type == 'i')
		str = ft_itoa(va_arg(lol, int));
	else if (magnum->type == 'u')
		str = ft_itoa_base(va_arg(lol, unsigned int), "0123456789");
	else if (magnum->type == 'x')
		str = ft_itoa_base(va_arg(lol, unsigned int), "0123456789abcdef");
	else
		str = ft_itoa_base(va_arg(lol, unsigned int), "0123456789ABCDEF");
	ft_putstring(str, magnum);
	free (str);
}
